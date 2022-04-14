import QtQuick
import QtQuick.Window 2.2
import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtQml 2.3


ApplicationWindow{
    visible: true
    width: 640
    height: 480
    color: "#ffb6c1"
    title: qsTr("C-Minder")

    // flags: Qt.WindowStaysOnTopHint

    header: ToolBar{
        //objectName: 'tool'
        height: 70
        RowLayout{
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
                    text: "MainPage with courses"

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


    ListView {
        width: 200; height: 250

        required model

        delegate: Text {
            required property string name
            required property string courseName
            required property string date

            text: "Animal: " + name + ", " + courseName + ", "  + date
        }
    }


    AssingmentModel {
            id: _AssingmentList           

            Assingment {
                courseName: "1"
                assingmentName: "1_"
                dueDate: 20
            }
            Assingment {
                courseName: "2"
                assingmentName: "2_"
                dueDate: 30
            }

        }

        ListView {
            anchors.fill: parent
            model: _AssingmentList
            delegate: Item {
                width: ListView.view.width
                height: 40

                Text {
                    anchors.centerIn: parent
                    font.bold: true
                    text: dataObject.courseName + " by " + dataObject.assingmentName + "on" + dataObject.dueDate
                }
            }
        }
}//applicationwindow

