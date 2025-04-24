// app/qml/screens/RecipePage.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import Mist 1.0  // Critical: Must match your CMake URI

Page {
    property int recipeId
    property var recipe: ({})

    Column {
        anchors.fill: parent
        spacing: 15
        padding: 20

        Image {
            source: recipe.imagePath || ""  // Handle null case
            width: parent.width
            height: 200
            fillMode: Image.PreserveAspectFit
            visible: source.toString() !== ""  // Hide if no image
        }

        Label {
            text: recipe.name || "Loading..."
            font {
                pixelSize: 24
                bold: true
            }
            width: parent.width
            wrapMode: Text.Wrap
        }

        Repeater {
            model: recipe.steps || []
            delegate: Text {
                text: (index + 1) + ". " + modelData  // Add step numbers
                font.pixelSize: 18
                width: parent.width - 40  // Account for padding
                wrapMode: Text.WordWrap
                topPadding: 5
            }
        }
    }

    Connections {
        target: db
        function onRecipeLoaded(recipeData) {
            recipe = recipeData
        }
    }

    RecipeDatabase {
        id: db
        Component.onCompleted: loadRecipe(recipeId)
    }
}

