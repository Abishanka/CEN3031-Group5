import QtQuick
import QtQuick.Window 2.2
import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3



/*
Window {
    width: 640
    height: 480
    visible: true
<<<<<<< HEAD
    title: qsTr("Hello World")
}
*/


ApplicationWindow{

    visible: true
    width: 640
    height: 480
    color: "#ffb6c1"
    title: qsTr("C-Minder")



    header: ToolBar{
                //objectName: 'tool'
                height: 70
                RowLayout{
                   height: 70

                    ToolButton{
                        id: helpButton
                                x: 370
                                y: 0
                                text: qsTr("Settings")
                                /* just change `visible` property by click */
                                onClicked: {
                                    statusView.visible     = false
                                    settingsView.visible   = true
                                }
                    }
                    ToolButton{

                        text: qstr("settingIcon")
                        icon.source: "/Resources/Images/Logo.png"

                        Text {
                                     text: parent.text
                                     anchors.bottom: parent.bottom
                                     anchors.horizontalCenter: parent.horizontalCenter
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
                            text: "homepage"

                        }
                    }



              }//toolbar


    ScrollBar {
        id: vbar
        hoverEnabled: true
        active: hovered || pressed
        orientation: Qt.Vertical
        size: frame.height / content.height
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: parent.bottom
    }

    ScrollBar {
        id: hbar
        hoverEnabled: true
        active: hovered || pressed
        orientation: Qt.Horizontal
        size: frame.width / content.width
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

            }//applicationwindow












=======
    title: qsTr("C Minder")
}
>>>>>>> 16e2ce6c5345dca815d113c6361ad7e67ba220b1

