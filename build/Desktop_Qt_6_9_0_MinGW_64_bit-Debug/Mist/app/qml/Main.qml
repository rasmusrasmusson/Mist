// qml/Main.qml
import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 1024  // Match your touchscreen resolution
    height: 600

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: "DishesPage.qml"
    }
}
