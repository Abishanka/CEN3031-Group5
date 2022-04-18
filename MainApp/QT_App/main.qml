import QtQuick
import QtQuick.Window 2.2
import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.3
import QtQml 2.3



ApplicationWindow{
    visible: true
    width: 640
    height: 480
    title: "C-Minder"

    Material.accent: "#000000"
    Material.primary: "#ffb6c1"
    Material.background: "#000000"

    flags: Qt.WindowStaysOnTopHint

    header: ToolBar{
        height: 70

        Rectangle {
            width: 50
            height: 50
            Image {
                width: 50
                height: 50
                source: "/Resources/Images/Logo.png"
            }
        }

        RowLayout{
            anchors.right: parent.right
            height: 70

            ToolButton{
                icon.source: "/Resources/Images/home.png"
                Text {
                              text: "Home"
                              anchors.bottom: parent.bottom
                              anchors.horizontalCenter: parent.horizontalCenter
                     }
            onClicked: {
                statusView.visible     = true
                settingsView.visible   = false
            }
            }

            ToolButton{
                icon.source: "/Resources/Images/TestCopy.png"
                Text {
                        text: "Settings"
                        anchors.bottom: parent.bottom
                        anchors.horizontalCenter: parent.horizontalCenter
                      }
            onClicked: {
                statusView.visible     = false
                settingsView.visible   = true
            }
            }

            ToolButton{
                icon.source: "/Resources/Images/sync.png"
                Text {
                              text: "Sync"
                              anchors.bottom: parent.bottom
                              anchors.horizontalCenter: parent.horizontalCenter
                     }
            onClicked: {
                //
            }
            }


        Item { Layout.fillWidth: true }
        Switch {
                    checked: true
                    text: qsTr("Change-view")
               }

        }
      }//toolbar

    //Display List View
    ColumnLayout {
     id: mainLayout
     anchors.fill: parent

    Rectangle{
     color: "#FFF"
     Layout.fillWidth: true
     height: 40
     z: 2
     RowLayout {
     id: rowLayout
     anchors.fill: parent
     anchors.centerIn: parent
     TextField {
     placeholderText: "Search for assingment here.."
     Layout.fillWidth: true
     font.pointSize: 12
     background: Rectangle {
     implicitWidth: 100
     implicitHeight: 30
     }

     onTextChanged: {
     filterModel.setFilterString(text);
     }
     }
     }
     }

    Rectangle {
        height: 10
    }

    Rectangle {
        height: 40
        anchors.horizontalCenter: parent.horizontalCenter
        Text {
            text: "Assingments Due Today"
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            color: "#ffb6c1"
            font.pointSize: 25
        }
    }

    Rectangle {
        height: 10
    }

    ListView {
     id: view
     model: filterModel
     Layout.minimumHeight: 25
     Layout.fillHeight: true
     Layout.fillWidth: true
     cacheBuffer: 100
     spacing: 10

    delegate: Rectangle{
     width: parent.width - 30
     radius: 50
     //anchors.horizontalCenter: parent.horizontalCenter
     anchors.left: parent.left
     anchors.leftMargin: 5

     height: 45
     color: Qt.lighter("#ffb6c1", 0.8)
     Text {
     id: nameTxt
     text: course + "    " + assingment + "    " + dueDate    //Use these key words as variables to place them. You can create separate rectangles if you want to
     font.pointSize: 8
     color: "#000"
     anchors.left: parent.left
     anchors.leftMargin: 20
     anchors.verticalCenter: parent.verticalCenter
     }
     }
     }
     }

}//applicationwindow

