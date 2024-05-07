#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <backend.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    ///
    /// \brief qmlRegisterType
    /// Ini cara kedua dengan membuat QmlRegisterType
    ///
    qmlRegisterType<backend> ("appKu",1,0,"BackEnd");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    ///
    /// \brief callBackend
    /// Ini cara pertama dengan QML Context
    ///
    ///
    ///
//    backend callBackend;
//    QQmlContext * rootContext = engine.rootContext();
//    rootContext->setContextProperty("classA", &callBackend);



    return app.exec();
}
