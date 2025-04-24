import QtQuick 2.15
import QtQuick.Controls 2.15
import Mist 1.0

Page {
    // ... your existing ListView code ...

    footer: Rectangle {
        width: parent.width
        height: 60
        color: "#f0f0f0"

        Row {
            anchors.centerIn: parent
            spacing: 20

            Button {
                text: "Clear All Recipes"
                onClicked: {
                    if (recipeDatabase.clearDatabase()) {
                        listView.model = [] // Clear the view
                        Qt.callLater(function(){ listView.model = recipeDatabase.getDishes() })
                    }
                }
                background: Rectangle {
                    color: "#ff4444"
                    radius: 5
                }
            }

            Button {
                text: "Backup Database"
                onClicked: {
                    var backupPath = Qt.resolvedUrl("file:///F:/Mist/backups/")
                    if (recipeDatabase.backupDatabase(backupPath)) {
                        console.log("Backup saved to:", backupPath)
                    }
                }
                background: Rectangle {
                    color: "#44aaff"
                    radius: 5
                }
            }
        }
    }
}
