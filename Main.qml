import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 400
    height: 600
    visible: true
    title: "Velocity"

    ColumnLayout {
        anchors.fill: parent

        ListView {
            id: messageList
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: ListModel { id: chatModel }
            delegate: Text { text: model.sender + ": " + model.content }
        }

        RowLayout {
            TextField {
                id: inputField
                placeholderText: "Type a message..."
                Layout.fillWidth: true
            }
            Button {
                text: "Send"
                onClicked: {
                    VelocityManager.sendMessage("User", inputField.text)
                    inputField.clear()
                }
            }
        }
    }

    Connections {
        target: VelocityManager
        function onNewMessageReceived(messageData) {
            chatModel.append({
                "sender": messageData.sender,
                "content": messageData.content
            })
        }
    }
}
