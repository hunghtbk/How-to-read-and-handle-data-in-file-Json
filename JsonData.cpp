#include "JsonData.h"

ActionElement::ActionElement(QJsonObject jsonOBJ) {
    m_type     = jsonOBJ["type"].toString();
    m_fileName = jsonOBJ["filename"].toString();
}

PageElement::PageElement(QJsonObject jsonOBJ) {
    m_url = jsonOBJ["url"].toString();

    QJsonArray actArray = jsonOBJ["action"].toArray();
    for (int i = 0; i < actArray.size(); i++) {
        ActionElement *actElement = new ActionElement(actArray[i].toObject());
        m_listActionElement.append(actElement);
    }

}

AfterActionElement::AfterActionElement(QJsonObject jsonOBJ) {
    m_type     = jsonOBJ["type"].toString();
    m_fileName = jsonOBJ["filename"].toString();
    m_file     = jsonOBJ["file"].toString();
    QJsonArray afterActArray = jsonOBJ["files"].toArray();
    for (int i = 0; i < afterActArray.size(); i++) {
        QString _subFile = afterActArray.at(i).toString();
        m_listFiles.append(_subFile);
    }
}
