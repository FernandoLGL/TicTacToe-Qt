#include "TicTacToe.h"
#include "FluxController.h"
#include "Menu.h"
#include "ui_TicTacToe.h"

TicTacToe::TicTacToe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TicTacToe)
{
    ui->setupUi(this);
}

TicTacToe::~TicTacToe()
{
    delete ui;
}

void TicTacToe::on_backToMenuButton_clicked() {
  FluxController::switchScene(this, new Menu);
}
