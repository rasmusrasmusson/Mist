/********************************************************************************
** Form generated from reading UI file 'recipepage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECIPEPAGE_H
#define UI_RECIPEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecipePage
{
public:
    QFrame *containerFrame;
    QVBoxLayout *verticalLayout;
    QWidget *headerWidget;
    QHBoxLayout *headerLayout;
    QPushButton *backButton;
    QLabel *titleLabel;
    QWidget *contentWidget;
    QHBoxLayout *contentLayout;
    QLabel *imageLabel;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *instructionsLayout;
    QTextEdit *instructionsText;

    void setupUi(QWidget *RecipePage)
    {
        if (RecipePage->objectName().isEmpty())
            RecipePage->setObjectName("RecipePage");
        RecipePage->resize(1920, 1080);
        RecipePage->setStyleSheet(QString::fromUtf8("background-color: #222;"));
        containerFrame = new QFrame(RecipePage);
        containerFrame->setObjectName("containerFrame");
        containerFrame->setGeometry(QRect(15, 10, 1890, 1060));
        containerFrame->setStyleSheet(QString::fromUtf8("background-color: #f0f0f0;\n"
"border-radius: 8px;\n"
"border: 2px solid #d0d0d0;"));
        verticalLayout = new QVBoxLayout(containerFrame);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName("verticalLayout");
        headerWidget = new QWidget(containerFrame);
        headerWidget->setObjectName("headerWidget");
        headerLayout = new QHBoxLayout(headerWidget);
        headerLayout->setSpacing(10);
        headerLayout->setObjectName("headerLayout");
        backButton = new QPushButton(headerWidget);
        backButton->setObjectName("backButton");
        backButton->setMinimumSize(QSize(150, 60));

        headerLayout->addWidget(backButton);

        titleLabel = new QLabel(headerWidget);
        titleLabel->setObjectName("titleLabel");

        headerLayout->addWidget(titleLabel);


        verticalLayout->addWidget(headerWidget);

        contentWidget = new QWidget(containerFrame);
        contentWidget->setObjectName("contentWidget");
        contentLayout = new QHBoxLayout(contentWidget);
        contentLayout->setSpacing(15);
        contentLayout->setObjectName("contentLayout");
        imageLabel = new QLabel(contentWidget);
        imageLabel->setObjectName("imageLabel");
        imageLabel->setMinimumSize(QSize(600, 400));

        contentLayout->addWidget(imageLabel);

        scrollArea = new QScrollArea(contentWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        instructionsLayout = new QVBoxLayout(scrollAreaWidgetContents);
        instructionsLayout->setObjectName("instructionsLayout");
        instructionsText = new QTextEdit(scrollAreaWidgetContents);
        instructionsText->setObjectName("instructionsText");
        instructionsText->setReadOnly(true);

        instructionsLayout->addWidget(instructionsText);

        scrollArea->setWidget(scrollAreaWidgetContents);

        contentLayout->addWidget(scrollArea);


        verticalLayout->addWidget(contentWidget);


        retranslateUi(RecipePage);

        QMetaObject::connectSlotsByName(RecipePage);
    } // setupUi

    void retranslateUi(QWidget *RecipePage)
    {
        backButton->setText(QCoreApplication::translate("RecipePage", "Back", nullptr));
        titleLabel->setText(QCoreApplication::translate("RecipePage", "Recipe Name", nullptr));
        imageLabel->setText(QCoreApplication::translate("RecipePage", "(Image)", nullptr));
        (void)RecipePage;
    } // retranslateUi

};

namespace Ui {
    class RecipePage: public Ui_RecipePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECIPEPAGE_H
