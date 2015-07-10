import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    width: 640
    height: 480

    property alias button3: button3
    property alias button2: button2
    property alias button1: button1

    RowLayout {
        anchors.centerIn: parent

        Button {
            id: button1
            text: qsTr("Press Me 1")
        }

        Button {
            id: button2
            text: qsTr("Press Me 2")
        }

        Button {
            id: button3
            text: qsTr("Press Me 3")
        }
    }

    TextInput {
        id: noImages
        x: 129
        y: 83
        width: 80
        height: 20
        text: qsTr("Text Input")
        font.pixelSize: 12
    }

    TextInput {
        id: leftSlit
        x: 129
        y: 109
        width: 80
        height: 20
        text: qsTr("Text Input")
        font.pixelSize: 12
    }

    TextInput {
        id: rightSlit
        x: 129
        y: 135
        width: 80
        height: 20
        text: qsTr("Text Input")
        font.pixelSize: 12
    }

    Button {
        id: start
        x: 129
        y: 173
        text: qsTr("Button")
    }
}
