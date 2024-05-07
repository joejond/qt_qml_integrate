#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>

class backend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString stringVar READ stringVar WRITE setStringVar NOTIFY stringVarChanged)
public:
    explicit backend(QObject *parent = nullptr);
    Q_INVOKABLE void invokeFunc();
    Q_INVOKABLE QString getStringVar();
    QString stringVar();

signals:
    void stringVarChanged();

public slots:
    void callMe();
    void setStringVar(QString);

private:
    QString m_stringVar;

};

#endif // BACKEND_H
