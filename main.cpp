#include <QCoreApplication>
#include "HandleDataInJsonFIle.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString fileName = "amazon-3.json";

    QString data = readDataFromFile(fileName);

    handleData(data);

    return a.exec();
}
