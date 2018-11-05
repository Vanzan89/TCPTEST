#include <QCoreApplication>
#include "TCPSocket.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TCPSocket test;
    test.connect();

    return a.exec();
}
