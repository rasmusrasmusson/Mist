#include "recipepage.h"
#include "ui_recipepage.h"

RecipePage::RecipePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecipePage)
{
    ui->setupUi(this);
}

RecipePage::~RecipePage()
{
    delete ui;
}
