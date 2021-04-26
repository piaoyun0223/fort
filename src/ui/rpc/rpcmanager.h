#ifndef RPCMANAGER_H
#define RPCMANAGER_H

#include <QObject>

class ControlManager;
class FortManager;
class FortSettings;

class RpcManager : public QObject
{
    Q_OBJECT

public:
    explicit RpcManager(FortManager *fortManager, QObject *parent = nullptr);

    FortManager *fortManager() const { return m_fortManager; }
    FortSettings *settings() const;
    ControlManager *controlManager() const;

    void initialize();

private:
    void setupServerSignals();
    void setupAppInfoManagerSignals();
    void setupQuotaManagerSignals();

    void invokeOnClients(qint8 rpcObj, const char *member, const QVariantList &args);

private:
    FortManager *m_fortManager = nullptr;
};

#endif // RPCMANAGER_H