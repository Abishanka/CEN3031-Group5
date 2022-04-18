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
    //color: "#ffb6c1"
    title: qsTr("C-Minder")

    //Material.theme: Material.Dark
    Material.accent: "#000000"
    Material.primary: "#ffb6c1"
    Material.background: "#000000"

    //flags: Qt.WindowStaysOnTopHint

    header: ToolBar{
        //objectName: 'tool'
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
                text: qstr("settingIcon")
                icon.source: "/Resources/Images/TestCopy.png"

                Text {
                             //text: parent.text
                             anchors.right: parent.right
                             //anchors.bottom: parent.bottom
                             //anchors.horizontalCenter: parent.horizontalCenter
                      }
            onClicked: {
                //Popup.open;
                statusView.visible     = false
                //homeB.visible          = true
                //settingsB.visible      = false
                settingsView.visible   = true
            }
          }

            ToolButton{

                text: qstr("HomeButton")
                icon.source: "/Resources/Images/homepage.png"
                Text {
                              text: parent.text
                              anchors.bottom: parent.bottom
                              anchors.horizontalCenter: parent.horizontalCenter
                     }
            onClicked: {

                statusView.visible     = true
                //settingsB.visible      = true
                //homeB.visible          = false
                settingsView.visible   = false
            }
            }




        Item { Layout.fillWidth: true }
        Switch {
                    checked: true
                    text: qsTr("Change-view")
               }

    }
            Item {
                /* use id for access */
                id: statusView
                x: 0
                y: 50
                width: 640
                height: 430
                /* visible: true */

                Text {
                    anchors.centerIn: parent
                    //text: "MainPage with courses"

                }
            }

            Item {
                id: settingsView
                x: 0
                y: 50
                width: 640
                height: 430
                /* invisible */
                visible: false

                Text {
                    //anchors.right: parent
                    anchors.centerIn: parent
                    text: "settings"

                }
            }
      }//toolbar

    //Display List View

    ColumnLayout {
     id: mainLayout
     anchors.fill: parent
     anchors.margins: margin

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
     placeholderText: "Type here.."
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

    ListView {
     id: view
     model: filterModel
     Layout.minimumHeight: 25
     Layout.fillHeight: true
     Layout.fillWidth: true
     cacheBuffer: 100
     spacing: 10

    delegate: Rectangle{
     width: parent.width - 100
     radius: 50
     //anchors.horizontalCenter: parent.horizontalCenter
     anchors.left: parent.left
     height: 45
     color: Qt.lighter("#ffb6c1", 0.8)
     Text {
     id: nameTxt
     text: assingment + "    " + course + "    " + dueDate    //Use these key words as variables to place them. You can create separate rectangles if you want to
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

