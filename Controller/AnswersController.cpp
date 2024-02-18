#include "AnswersController.h"

#include <QDateTime>
#include <QDebug>
#include <QRegExp>

namespace Love {

bool AnswersController::checkAnswer(Questions question,
                                    QuestionsController::QuestionType type,
                                    QVariant answer) {
  switch (question) {
    case Questions::KISS:
    case Questions::BIRTHDAY:
    case Questions::FIRST_MEET:
    case Questions::LOVE_WORDS:
    case Questions::FIRST_TRAVEL:
    case Questions::FIRST_SEX:
    case Questions::COMPLIMENTS:
    case Questions::FAVORITE_BODY_PARTS:
    case Questions::FIRST_DINNER_FOR_YOU:
      break;
  }

  return false;
}

}  // namespace Love
