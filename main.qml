import QtQuick 2.2
import QtQuick.Controls 1.1
import MazeField 1.0
import PathField 1.0

ApplicationWindow{
    id: applicationWindow1
    width: 1360
    minimumWidth: 1360
    height: 720
    minimumHeight: 720
    color: "dimgray"
    title: qsTr("PathSim")
    visible: true
    
    Rectangle {
        width: 1036; height: 720
        x: 10; y: 10
        color: "gray"
        clip: true
        ScrollView {
            width: 1036; height: 720
            Rectangle {
                width: 1020+2; height: 1020
                MazeField {
                    id: mazefield
                    width: 1020; height: 1020
                    x: 0; y: 0
                    mazesize: 32
                    transform: Scale { origin.x: 0; origin.y: 0; xScale: 1; yScale: 1}
                }
                PathField {
                    id: pathfield
                    width: 1020; height: 1020
                    x: 0; y: 0
                    transform: Scale { origin.x: 0; origin.y: 0; xScale: 1; yScale: 1}
                }
            }
        }
    }
    
    Rectangle {
        x: 1060; y: 10
        width: 240; height: 180
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
            onClicked: {
                mazefield.loadMazeFromClpbrd();
                pathfield.updateMapFromClpbrd();
            }
        }
        ComboBox {
            id: combo_file
            x:30; y:70
            width: 180
            model: manage.getMazefileList()
        }
        Button {
            id: button_file
            x:90; y:100
            width: 120
            text: "File(maze, png)"
            onClicked: {
                mazefield.loadMazeFromFile("./maze/" + combo_file.currentText);
                pathfield.updateMapFromFile("./maze/" + combo_file.currentText);
            }
        }
        ComboBox {
            id: combo_mouse
            x:30; y:130
            width: 50
            model: [1, 2, 3, 4, 5]
        }
        Button {
            id: button_mouse
            x:90; y:130
            width: 60
            text: "Serial"
        }
    }
    
    Rectangle {
        id: rect_algorithm
        x: 1060; y: 210
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
        x: 1060; y: 320
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
            onClicked: {
                pathfield.loadPath(combo_algorithm.currentText);
            }
        }
    }

    Rectangle {
        x: 1060; y: 430
        width: 220; height: 110
        color: "whitesmoke"
        radius: 5
        Label {
            x: 10; y: 10
            id: label_export
            font.pixelSize: 18
            text: qsTr("export")
        }
        TextField {
            id: text_exportfile
            x: 10; y: 40
            width: 160
            placeholderText: qsTr("file name")
        }
        Label {
            id: label_dotmaze
            x: 170; y: 45
            font.pixelSize: 14
            text: qsTr(".maze")
        }
        Button {
            id: button_exportfile
            x:30; y:70
            width: 120
            text: "File(.maze)"
            onClicked: {
                mazefield.saveMazeToFile("./maze/" + text_exportfile.text + ".maze");
            }
        }
    }
}
