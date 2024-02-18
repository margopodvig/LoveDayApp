#ifndef ANSWERSCONTROLLER_H
#define ANSWERSCONTROLLER_H

#include "Questions/Questions.h"
#include "QuestionsController.h"

namespace Love {

class AnswersController {
 public:
  static bool checkAnswer(Questions question,
                          QuestionsController::QuestionType type,
                          QVariant answer);
};

}  // namespace Love

#endif  // ANSWERSCONTROLLER_H
