import QtQuick 2.15
import QtQuick.Window 2.10
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.0

Window {
    width: 500
    height: 700
    visible: true
    title: qsTr("Hello World")
    Rectangle {
        id: topRectangle
        width: parent.width
        height: 50
        Button {
            text: "Подсказка"
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.margins: 5
        }

        Button {
            text: "Карта"
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.margins: 5
        }
    }

    LovePage {
        anchors.margins: 40
        anchors.top: topRectangle.bottom
        anchors.left: topRectangle.left
        anchors.right: topRectangle.right
        anchors.bottom: parent.bottom
    }
}
