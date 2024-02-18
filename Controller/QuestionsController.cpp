#include "QuestionsController.h"

#include <QtQml>

#include "AnswersController.h"
#include "Questions/Questions.h"

namespace Love {

QuestionsController::QuestionsController(QObject *parent) : QObject(parent) {
  qmlRegisterType<QuestionsController>("QuestionType", 1, 0, "QuestionType");
}

QString QuestionsController::getQuestion() {
  return questionsMap[static_cast<Questions>(m_currentQuestion)];
}

QString QuestionsController::getAnswer() {
  return answersMap[static_cast<Questions>(m_currentQuestion)].toString();
}

QuestionsController::QuestionType QuestionsController::getQuestionType() {
  switch (static_cast<Questions>(m_currentQuestion)) {
    case Questions::KISS:
    case Questions::BIRTHDAY:
    case Questions::FIRST_SEX:
    case Questions::FIRST_MEET: {
      return QuestionType::CalendarType;
    }
    case Questions::FIRST_DINNER_FOR_YOU:
    case Questions::FAVORITE_BODY_PARTS:
    case Questions::COMPLIMENTS:
    case Questions::FIRST_TRAVEL:
    case Questions::LOVE_WORDS: {
      return QuestionType::StringType;
    }
  }
  return QuestionType::Unknown;
}

void QuestionsController::nextQuestion() {
  ++m_currentQuestion;
  emit questionChanged();
}

bool QuestionsController::checkAnswer(QVariant answer) {
  if (getQuestionType() == QuestionType::CalendarType) {
    answer = answer.toDateTime().toString("dd.MM.yyyy");
    auto right_answer = answersMap[static_cast<Questions>(m_currentQuestion)]
                            .toDateTime()
                            .toString("dd.MM.yyyy");
    return answer == right_answer;
  }

  return answer ==
         answersMap[static_cast<Questions>(m_currentQuestion)].toString();
}

QStringList QuestionsController::getMounth() {
  QStringList result;
  for (int i = 1; i < 13; ++i) {
    result.push_back(QString::number(i));
  }

  return result;
}

QStringList QuestionsController::getYears() {
  QStringList result;
  for (int i = 1999; i < 2024; ++i) {
    result.push_back(QString::number(i));
  }

  return result;
}

QStringList QuestionsController::getDays() {
  QStringList result;
  for (int i = 1; i < 32; ++i) {
    result.push_back(QString::number(i));
  }

  return result;
}

}  // namespace Love
