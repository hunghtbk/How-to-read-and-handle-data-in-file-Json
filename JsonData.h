#ifndef JSONDATA_H
#define JSONDATA_H
#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <QList>


/*

    Neu dung [] thi su dung JsonArray de convert to Array, sau do moi xu ly
    Neu dung {} thi su dung JsonObject de convert toString/toBool/toInt.

*/

class PageElement;
class ActionElement;
class AfterActionElement;

class ActionElement
{
public:
    ActionElement(QJsonObject jsonOBJ);
    QString m_type;
    QString m_fileName;

};

class PageElement
{
public:
    PageElement(QJsonObject jsonOBJ);
    QString m_url;
    QList<ActionElement*> m_listActionElement;
};

class AfterActionElement
{
public:
    AfterActionElement(QJsonObject jsonOBJ);
    QString m_type;
    QString m_fileName;
    QString m_file;
    QStringList m_listFiles;

};

#endif // JSONDATA_H
