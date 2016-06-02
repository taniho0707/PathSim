import QtQuick 2.2
import QtQuick.Controls 1.1
import MazeField 1.0
import PathField 1.0

ApplicationWindow{
    id: applicationWindow1
    width: 1280
    minimumWidth: 1280
    height: 720
    minimumHeight: 720
    color: "dimgray"
    title: qsTr("PathSim")
    visible: true
    
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
                    id: mazefield
                    width: 1024; height: 1024
                    x: 0; y: 0
                    mazesize: 32
                    transform: Scale { origin.x: 0; origin.y: 0; xScale: 1; yScale: 1}
                }
                PathField {
                    id: pathfield
                    width: 1024; height: 1024
                    x: 0; y: 0
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
            onClicked: mazefield.loadMazeFromClpbrd()
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
        id: rect_algorithm
        x: 560; y: 180
        width: 250; height: 90
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
            width: 180
            model: manage.getPathfileList()
            // model: CheckPath.getPathfileList()
        }
    }
    
    Rectangle {
        x: 560; y: 290
        width: 180; height: 90
        color: "whitesmoke"
        radius: 5
        Label {
            x: 10; y: 10
            id: label_drawing
            font.pixelSize: 18
            text: qsTr("drawing")
        }
        Button {
            id: button_drawpath
            x:30; y:40
            width: 120
            text: "DrawPath"
            onClicked: pathfield.loadPath(combo_algorithm.currentText);
        }
    }
}
