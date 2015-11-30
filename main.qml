import QtQuick 2.2
import QtQuick.Controls 1.1
//import DrawingTest 1.0
import MazeField 1.0

ApplicationWindow{
    id: applicationWindow1
    width: 1280
    minimumWidth: 1280
    height: 720
    minimumHeight: 720
    color: "dimgray"
    title: qsTr("PathSim")
    visible: true

    // Button {
    //     id: test
    //     x: 179
    //     y: 373
    //     text: qsTr("つぶやく(&P)")
    //     anchors.horizontalCenterOffset: 2
    //     anchors.horizontalCenter: parent.horizontalCenter
    //     transformOrigin: Item.TopLeft
    //     onClicked: manage.test();
    // }

    // TextArea {
    //     id: testText
    //     text: "AAA"
    //     x: 97
    //     y: 210
    //     anchors.horizontalCenterOffset: 2
    //     anchors.horizontalCenter: parent.horizontalCenter
    // }

    // Label {
    //     id: testLabel
    //     x: 97
    //     y: 177
    //     text: qsTr("スクリーンネーム：")
    //     horizontalAlignment: Text.AlignHCenter
    // }

    Rectangle {
        width: 528; height: 528
        x: 10; y: 10
        color: "gray"
        clip: true
        ScrollView {
            width: 528; height: 528
            Rectangle {
                width: 1024+2; height: 1024+2
                MazeField {
                    width: 1024; height: 1024
                    x: 0; y: 0
                    mazesize: 32
                    transform: Scale { origin.x: 0; origin.y: 0; xScale: 1; yScale: 1}
                }
            }
        }
    }

    Rectangle {
        x: 560; y: 10
        width: 180; height: 150
        color: "whitesmoke"
        radius: 5
        Label {
            x: 10; y: 10
            id: label_import
            font.pixelSize: 18
            text: qsTr("import")
        }
        Button {
            id: button_clipboard
            x:30; y:40
            width: 120
            text: "Clipboard"
        }
        Button {
            id: button_file
            x:30; y:70
            width: 120
            text: "File(dat, png)"
        }
        Button {
            id: button_NFC
            x:30; y:100
            width: 60
            text: "NFC"
        }
        ComboBox {
            id: combo_NFC
            x:100; y:100
            width: 50
            model: [1, 2, 3, 4, 5]
        }
    }

    Rectangle {
        x: 560; y: 180
        width: 180; height: 90
        color: "whitesmoke"
        radius: 5
        Label {
            x: 10; y: 10
            id: label_algorithm
            font.pixelSize: 18
            text: qsTr("algorithm")
        }
        ComboBox {
            id: combo_algorithm
            x:30; y:40
            width: 100
            model: ["Adachi", "Adachi2"]
        }
        // Button {
        //     id: button_NFC
        //     x:30; y:100
        //     width: 60
        //     text: "NFC"
        // }
    }

}
