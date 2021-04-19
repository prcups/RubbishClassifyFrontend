#ifndef CLASSIFY_UTILS_H
#define CLASSIFY_UTILS_H

#include <QObject>
#include <QProcess>
#include <QString>
#include <QtDebug>

class Classify_utils : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString info READ info WRITE setInfo NOTIFY infoChanged)
  Q_PROPERTY(
      int progress READ progress WRITE setProgress NOTIFY progressChanged)
 public:
  explicit Classify_utils(QObject* parent = nullptr);
  Q_INVOKABLE void upload_set();
  Q_INVOKABLE void classify(int img_num);
  QString info() { return m_info; }
  int progress() { return m_progress; }
  void setInfo(const QString& info) {
    m_info = info;
    emit infoChanged(m_info);
  }
  void setProgress(const int& progress) {
    if (progress != m_progress) {
      m_progress = progress;
      emit progressChanged(m_progress);
    }
  }
  void updateStatus(const QString& info, const int& progress) {
    if (progress >= 0 && progress <= 100) {
      setInfo(info);
      setProgress(progress);
    }
  }
  Q_INVOKABLE void loadConfig();
 signals:
  void infoChanged(const QString& info);
  void progressChanged(const int& progress);

 private:
  QString m_info;
  QProcess scp;
  int m_progress;
  bool m_isBusy = false;
  bool m_camera_available = false;
  struct conf {
    QString images_path;
    QString set_upload_address;
    int set_upload_port;
    QString set_upload_position;
    QString set_upload_username;
    QString set_upload_password;

    QString classify_upload_address;
    int classify_upload_port;
    QString classify_upload_position;
    QString classify_upload_username;
    QString classify_upload_password;
    int err = 1;
  } loaded_config;
  bool prepared() {
    if (loaded_config.err) {
      setInfo("配置项有错误");
      return false;
    } else if (m_isBusy) {
      setInfo("有一项任务正在执行");
      return false;
    }
    return true;
  }
  void setbusy(bool isBusy) { m_isBusy = isBusy; }
  Q_INVOKABLE void setCameraAvailable(bool isAvailable) {
    m_camera_available = isAvailable;
  }
};

#endif  // CLASSIFY_UTILS_H
