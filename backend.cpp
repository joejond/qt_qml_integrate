#include "backend.h"
#include <QDebug>

backend::backend(QObject *parent) :
    QObject(parent),
    m_stringVar("abcde")
{

}

void backend::invokeFunc()
{
    qDebug() << "Jalankan " << __FUNCTION__;

}

QString backend::getStringVar()
{
    return m_stringVar;
}

QString backend::stringVar()
{
    return m_stringVar;
}

void backend::callMe()
{
    qDebug() << "hai Im Called";
}

void backend::setStringVar(QString text)
{
    if(m_stringVar != text)
    {
        m_stringVar = text;
        emit stringVarChanged();
    }

}
