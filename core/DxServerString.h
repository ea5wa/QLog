#ifndef DXSERVERSTRING_H
#define DXSERVERSTRING_H

#include <QString>

class DxServerString
{
public:
    explicit DxServerString(const QString &string,
                            const QString &defaultUsername = QString());

    static bool isValidServerString(const QString &);
    bool isValid() const {return valid;};
    QString getUsername() const {return username;};
    QString getHostname() const {return hostname;};
    int getPort() const {return port;};
    const QString getPasswordStorageKey() const;

private:
    static const QRegularExpression serverStringRegEx();

    QString username, hostname;
    int port;
    bool valid;
};

#endif // DXSERVERSTRING_H
