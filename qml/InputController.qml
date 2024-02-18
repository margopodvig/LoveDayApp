import QtQuick 2.15
import QtQuick.Controls 1.4 as QtCalendar
import QtQuick.Controls 2.15
import QuestionType 1.0
import QtQuick.Layouts 1.0

Item {
    id: input_item
    anchors.fill: parent
    property string result: ""

    RowLayout {
        id: date_time_comp
        visible: controller.question_type === QuestionType.CalendarType
        spacing: 10
        ComboBox {
            model: controller.getDays()
            editable: true
            validator: IntValidator {
                top: 31
                bottom: 1
            }
        }
        ComboBox {
            model: controller.getMounth()
            editable: true
            validator: IntValidator {
                top: 12
                bottom: 1
            }
        }
        ComboBox {
            model: controller.getYears()
            editable: true
            validator: IntValidator {
                top: 2023
                bottom: 1999
            }
        }
    }

    TextField {
        id: datefield
        visible: !date_time_comp.visible
        anchors.top: questionText.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.topMargin: 40
        font.pixelSize: 20
        placeholderText: "Ответ"
        onTextChanged: {
            result = text
        }
    }
}
