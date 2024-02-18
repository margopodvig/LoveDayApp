#include <QDateTime>
#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Controller/QuestionsController.h"

int main(int argc, char* argv[]) {
  QGuiApplication app(argc, argv);

  Love::QuestionsController controller;
  QQmlApplicationEngine engine;
  const QUrl url("qrc:/main.qml");
  QObject::connect(
      &engine, &QQmlApplicationEngine::destroyed, &app,
      []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);
  engine.load(url);

  engine.rootContext()->setContextProperty("controller", &controller);

  return app.exec();
}
