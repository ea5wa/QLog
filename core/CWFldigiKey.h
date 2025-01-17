#ifndef CWFLDIGIKEY_H
#define CWFLDIGIKEY_H

#include <QObject>
#include <QNetworkAccessManager>
#include "CWKey.h"

class CWFldigiKey : public CWKey
{

public:
    CWFldigiKey(const QString &hostname,
                const quint16 port,
                const CWKey::CWKeyModeID mode,
                const qint32 defaultSpeed,
                QObject *parent = nullptr);
    ~CWFldigiKey(){ nam->deleteLater();};

    virtual bool open() override;
    virtual bool close() override;
    virtual QString lastError() override;

    virtual bool sendText(const QString &text) override;
    virtual bool setWPM(const qint16 wpm) override;
    virtual bool imediatellyStop() override;


protected:

    QString lastLogicalError;
    bool isOpen;
    QNetworkAccessManager *nam;
    QString hostname;
    quint16 port;

    const QString TX;

private:
    bool sendXMLRPCCall(const QString&,
                        QByteArray &,
                        const QList<QPair<QString, QString>>* = nullptr);
private slots:
    void getEcho();
};

#endif // CWFLDIGIKEY_H
