#include "HandleDataInJsonFIle.h"
#include <QFile>
#include <QDebug>
#include "JsonData.h"
#include <QJsonDocument>
#include <QJsonObject>

QString readDataFromFile(QString fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Coudln't open file for reading";
        return "";
    }  else {
        QTextStream in(&file);
        QString myText = in.readAll();
//        qDebug() << myText;
        return myText;
    }
}




void handleData(QString m_data)
{
    PageElement *m_page;
    QList<PageElement*> m_listPage;

    AfterActionElement *m_afterActionElement;
    QList<AfterActionElement*> m_listAfterAction;


    QJsonDocument jsonResponse = QJsonDocument::fromJson(m_data.toUtf8());
    if (!jsonResponse.isObject()) {
            qDebug() << "Document is not an object";
        }
    QJsonObject jsonObject = jsonResponse.object();

    // Read Page element
    QJsonArray jsonArray = jsonObject["pages"].toArray();
    for (int i = 0; i < jsonArray.size(); i++) {
        m_page = new PageElement(jsonArray[i].toObject());
        m_listPage.append(m_page);
    }

    // Read After Action
    jsonArray = jsonObject["after_actions"].toArray();
    for (int i = 0; i < jsonArray.size(); i++) {
        m_afterActionElement = new AfterActionElement(jsonArray[i].toObject());
        m_listAfterAction.append(m_afterActionElement);
    }


    // Read Data after Handle
    for (int i = 0; i < m_listPage.length(); i++) {
        qDebug() << m_listPage.at(i)->m_url;
        for (int j = 0; j < (m_listPage.at(i)->m_listActionElement).length(); j++) {
            qDebug() << m_listPage.at(i)->m_listActionElement.at(j)->m_fileName;
            qDebug() << m_listPage.at(i)->m_listActionElement.at(j)->m_type;
        }
    }

    for (int i = 0; i < m_listAfterAction.size(); i++) {
        qDebug() << m_listAfterAction.at(i)->m_file;
        qDebug() << m_listAfterAction.at(i)->m_fileName;
        qDebug() << m_listAfterAction.at(i)->m_type;

        for (int j = 0; j < (m_listAfterAction.at(i)->m_listFiles).length(); j++) {
            qDebug() << m_listAfterAction.at(i)->m_listFiles.at(j);
        }
    }
}
