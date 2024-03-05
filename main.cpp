#include <math.h>

#include <QDateTime>
#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <chrono>
#include <iostream>

#include "Controller/QuestionsController.h"

float fromDeg(float angle) { return angle * 180.0f / M_PI; };

constexpr float DEG2_RAD = 180.0f / M_PI;
float fromDeg1(float angle) { return angle * DEG2_RAD; };

static const float ANGLE = fromDeg(180.0);

int main(int argc, char* argv[]) {
  {
    auto now = std::chrono::system_clock::now();
    for (int i = 0; i < 20000000000; ++i) {
      float res = fromDeg(i);
    }

    auto end = std::chrono::system_clock::now();
    std::cout
        << "time:"
        << std::chrono::duration_cast<std::chrono::seconds>(end - now).count()
        << std::endl;
  }

  {
    auto now = std::chrono::system_clock::now();
    for (int i = 0; i < 20000000000; ++i) {
      float res = fromDeg1(i);
    }
    auto end = std::chrono::system_clock::now();
    std::cout
        << "time1:"
        << std::chrono::duration_cast<std::chrono::seconds>(end - now).count()
        << std::endl;
  }

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
