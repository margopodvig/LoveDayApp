import QtQuick 2.15
import QtQuick.Controls 2.15
import QuestionType 1.0

Item {

    property int clickedNumber: 0
    property bool isCalendarType: controller.question_type === QuestionType.CalendarType
    Text {
        id: text1
        text: "Вопросы 1/15"
        anchors.horizontalCenter: parent.horizontalCenter
        font.bold: true
        font.pixelSize: 18
    }

    Text {
        id: questionText
        anchors.margins: 20
        anchors.top: text1.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        text: controller.question
        font.pixelSize: 15
        wrapMode: Text.WordWrap
    }

    Rectangle {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: questionText.bottom
        anchors.bottom: enterButton.top
        InputController {
            id: inputController
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 40
        }
    }

    Timer {
        id: wrong_answer_timer
        interval: 1000
        repeat: false
        onTriggered: {
            enterButton.background.color = "#AAD4EE"
        }
    }

    Button {
        id: enterButton
        readonly property string enter: "Ввести"
        readonly property string next: "Далее"
        anchors.bottom: parent.bottom
        Text {
            id: buttonText
            anchors.centerIn: parent
            text: enterButton.enter
            font.pixelSize: 20
        }

        width: buttonText.implicitWidth + 5
        height: buttonText.implicitHeight + 5
        anchors.horizontalCenter: parent.horizontalCenter
        background: Rectangle {
            color: "#AAD4EE"
        }

        onClicked: {
            if (buttonText.text === next) {
                controller.nextQuestion()
                return
            }

            if (!controller.checkAnswer(inputController.result)) {
                enterButton.background.color = "red"
                wrong_answer_timer.start()
                return
            }

            buttonText.text = next
            enterButton.background.color = "green"
        }
    }
}
