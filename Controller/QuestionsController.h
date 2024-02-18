#ifndef QUESTIONSCONTROLLER_H
#define QUESTIONSCONTROLLER_H

#include <QList>
#include <QObject>
#include <QString>
#include <QVariant>

namespace Love {

class QuestionsController : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString question READ getQuestion NOTIFY questionChanged FINAL)
  Q_PROPERTY(QString answer READ getAnswer NOTIFY questionChanged FINAL)
  Q_PROPERTY(
      QuestionType question_type READ getQuestionType NOTIFY questionChanged)

 public:
  enum class QuestionType {
    StringType,
    CalendarType,
    Unknown,
  };

  Q_ENUM(QuestionType);

  QuestionsController(QObject* parent = nullptr);
  QString getQuestion();
  QString getAnswer();
  void extracted();
  QuestionType getQuestionType();

 public slots:
  void nextQuestion();
  bool checkAnswer(QVariant answer);

  QStringList getMounth();
  QStringList getYears();
  QStringList getDays();

 signals:
  void questionChanged();

 private:
  uint8_t m_currentQuestion = 0;
};

}  // namespace Love

#endif  // QUESTIONSCONTROLLER_H
