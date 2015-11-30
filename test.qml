import QtQuick 2.2
import QtQuick.Controls 1.1

ApplicationWindow{
    id: appWindow1
    width: 320
    height: 240
    title: qsTr("Test")
    visible: true
    
    Rectangle{
        id: rect1
        color: "gray"
        width: 100; height: 70
        x: 100

        Text{
            id: text1
            anchors.centerIn: parent
            text: "Button"
        }

        MouseArea{
            id: rect1MouseArea
            anchors.fill: parent
            onClicked: console.log(text1.text + " clicked")
        }
    }
}

