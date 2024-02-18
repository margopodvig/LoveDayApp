#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <QDateTime>
#include <QMap>
#include <QVariant>

namespace Love {

enum class Questions {
  KISS,
  BIRTHDAY,
  FIRST_MEET,
  LOVE_WORDS,
  FIRST_TRAVEL,
  FIRST_SEX,
  COMPLIMENTS,
  FAVORITE_BODY_PARTS,
  FIRST_DINNER_FOR_YOU,
};

static QMap<Questions, QString> questionsMap = []() {
  QMap<Questions, QString> questions;
  questions[Questions::KISS] = "Первый поцелуй";
  questions[Questions::BIRTHDAY] = "Мой день рождения ";
  questions[Questions::FIRST_MEET] = "День первой встречи ";
  questions[Questions::LOVE_WORDS] = "Первые слова про любовь ";
  questions[Questions::FIRST_TRAVEL] = "Первое совместное путешествие ";
  questions[Questions::FIRST_SEX] = "Первый секс ";
  questions[Questions::COMPLIMENTS] =
      "Напиши 5 комплиментов мне(Ответы могут быть неправильными) ";
  questions[Questions::FAVORITE_BODY_PARTS] =
      "Назови три мной любимых твоих части тел ";
  questions[Questions::FIRST_DINNER_FOR_YOU] =
      "Что было первое, что я тебе приготовила? ";
  return questions;
}();

static QMap<Questions, QVariant> answersMap = []() {
  QMap<Questions, QVariant> answers;
  answers[Questions::KISS] = QDateTime::fromString("26.07.2022", "dd.MM.yyyy");
  answers[Questions::BIRTHDAY] =
      QDateTime::fromString("14.05.1999", "dd.MM.yyyy");
  answers[Questions::FIRST_MEET] =
      QDateTime::fromString("17.12.2022", "dd.MM.yyyy");
  answers[Questions::LOVE_WORDS] = "Первые слова про любовь ";
  answers[Questions::FIRST_TRAVEL] = "Первое совместное путешествие ";
  answers[Questions::COMPLIMENTS] =
      "Напиши 5 комплиментов мне(Ответы могут быть неправильными) ";
  answers[Questions::FAVORITE_BODY_PARTS] =
      "Назови три мной любимых твоих части тел ";
  answers[Questions::FIRST_DINNER_FOR_YOU] =
      "Что было первое, что я тебе приготовила? ";
  return answers;
}();

}  // namespace Love

#endif  // QUESTIONS_H
