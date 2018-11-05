#ifndef TCPSocket_HPP
#define TCPSocket_HPP

#include <QTcpSocket>
#include <QDebug>
#include <QObject>

class TCPSocket : public QObject
{
    Q_OBJECT
public:
    explicit TCPSocket (QObject *parent = 0);
    void connect();
    QTcpSocket *socket;
};

#endif
