import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.VirtualKeyboard 2.15
import QtQuick.Controls 2.5
import appKu 1.0

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    //panggil resitertype
    // jika menggunakan regiyer type, harus di pangil disini
    BackEnd{
        id: classKu
    }


    Button{
        id:tombol1
        anchors.centerIn: parent
        text: "Panggil Saya"
        onClicked: {
            classKu.invokeFunc()
            classKu.setStringVar("Halo Dunia")
        }

    }

    Text {
        id: text1
        anchors{
            top: parent.top
            horizontalCenter: parent.horizontalCenter
            topMargin: 20
        }
        font.pixelSize: 24
//        text: classKu.stringVar
        text: classKu.getStringVar()
    }

    Connections{
        target: classKu
        onStringVarChanged:text1.text = classKu.getStringVar()
    }
}
