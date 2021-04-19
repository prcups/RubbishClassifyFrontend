#include "classify_utils.h"

#include <QCamera>
#include <QDebug>
#include <QDir>
#include <QEventLoop>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>
#include <QProcess>
#include <QStandardPaths>

Classify_utils::Classify_utils(QObject* parent) : QObject(parent) {
  connect(&scp, &QProcess::readyReadStandardOutput,
          [&]() { setInfo(scp.readAllStandardOutput()); });
  connect(&scp, &QProcess::readyReadStandardError, [&]() {
    setInfo("错误：" +
            QString::fromStdString(scp.readAllStandardError().toStdString()));
  });
  connect(&scp, &QProcess::stateChanged, [&]() {
    switch (scp.state()) {
      case QProcess::NotRunning:
        setbusy(false);
        if (scp.exitCode() == 0) setInfo("上传成功");
        setProgress(100);
        break;
      case QProcess::Starting:
        setbusy(true);
        updateStatus("上传训练集中", 0);
        break;
      case QProcess::Running:
        setProgress(50);
        break;
    }
  });
}

void Classify_utils::loadConfig() {
  try {
    updateStatus("读取配置", 0);
    QFile rules_file("../config/config.json");
    if (!rules_file.open(QIODevice::ReadOnly)) {
      throw QString("配置文件读取失败");
    }
    QJsonParseError json_err;
    QJsonDocument json_config =
        QJsonDocument::fromJson(rules_file.readAll(), &json_err);
    rules_file.close();
    if (json_err.error != QJsonParseError::NoError) {
      throw QString("配置文件无效:") + json_err.errorString();
    }
    updateStatus("载入并检验配置", 30);

    loaded_config.images_path =
        json_config["images-path"].toString("../assets/images");
    loaded_config.set_upload_address =
        json_config["set-upload-address"].toString();
    loaded_config.set_upload_port = json_config["set-upload-port"].toInt(22);
    loaded_config.set_upload_position =
        json_config["set-upload-position"].toString();
    loaded_config.set_upload_username =
        json_config["set-upload-username"].toString();
    loaded_config.set_upload_password =
        json_config["set-upload-password"].toString();

    loaded_config.classify_upload_address =
        json_config["classify-upload-address"].toString();
    loaded_config.classify_upload_port =
        json_config["classify-upload-port"].toInt(22);
    loaded_config.classify_upload_position =
        json_config["classify-upload-position"].toString();
    loaded_config.classify_upload_username =
        json_config["classify-upload-username"].toString();
    loaded_config.classify_upload_password =
        json_config["classify-upload-password"].toString();

    if (loaded_config.set_upload_address == "" ||
        loaded_config.set_upload_password == "" ||
        loaded_config.set_upload_position == "" ||
        loaded_config.set_upload_username == "" ||
        loaded_config.classify_upload_address == "" ||
        loaded_config.classify_upload_password == "" ||
        loaded_config.classify_upload_position == "" ||
        loaded_config.classify_upload_username == "") {
      throw(QString("配置项为空"));
    }
    loaded_config.err = 0;
  } catch (QString exp) {
    updateStatus("发生错误：" + exp, 100);
    return;
  }
  updateStatus("配置载入成功", 100);
  return;
}

void Classify_utils::upload_set() {
  if (!prepared()) {
    return;
  }
  scp.setProgram("/usr/bin/sshpass");
  scp.setArguments(QStringList()
                   << "-p" << loaded_config.set_upload_password
                   << "/usr/bin/scp"
                   << "-r"
                   << "-P" << QString::number(loaded_config.set_upload_port)
                   << loaded_config.images_path
                   << loaded_config.set_upload_username + "@" +
                          loaded_config.set_upload_address + ":" +
                          loaded_config.set_upload_position);
  scp.start();
}

void Classify_utils::classify(int img_num) {}
