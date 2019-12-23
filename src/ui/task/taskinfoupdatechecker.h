#ifndef TASKINFOUPDATECHECKER_H
#define TASKINFOUPDATECHECKER_H

#include "taskinfo.h"

class TaskInfoUpdateChecker : public TaskInfo
{
    Q_OBJECT
    Q_PROPERTY(QString version READ version NOTIFY versionChanged)
    Q_PROPERTY(QString downloadUrl READ downloadUrl NOTIFY versionChanged)
    Q_PROPERTY(QString releaseText READ releaseText NOTIFY versionChanged)

public:
    explicit TaskInfoUpdateChecker(QObject *parent = nullptr);

    QString version() const { return m_version; }
    QString downloadUrl() const { return m_downloadUrl; }
    QString releaseText() const { return m_releaseText; }

    QByteArray data() const override;
    void setData(const QByteArray &data) override;

signals:
    void versionChanged();

public slots:
    bool processResult(FortManager *fortManager, bool success) override;

private:
    QString m_version;
    QString m_downloadUrl;
    QString m_releaseText;
};

#endif // TASKINFOUPDATECHECKER_H