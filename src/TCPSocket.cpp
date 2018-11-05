#include "TCPSocket.hpp"


 TCPSocket::TCPSocket(QObject* parent) : QObject(parent)
 {
 }

void TCPSocket::connect()
{
    //creating a pointer to this object
    socket = new QTcpSocket(this);

    //connect to host from 80 port
    socket->connectToHost("esphere.ru", 80);

    //do if connect
    if (socket->waitForConnected(1000))
    {
        qDebug() << "Connected!";

        //Sending bytes
        socket->write("Privet pizdyuk!/r/n/r/n/r/n/r/n");

        //Wait for send
        socket->waitForBytesWritten(1000);

        //Wait for reply
        socket->waitForReadyRead(3000);

        //Amount of bytes reply
        qDebug() << "Reading: " << socket->bytesAvailable();

        //Reply
        qDebug() << socket->readAll();
        socket->close();
    }

    //If connected is unsuccesfull
    else {
        qDebug() << "Disconnected!";
    }

}
