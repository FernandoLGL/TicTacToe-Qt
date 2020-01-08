#include "include/Menu.h"
#include "FluxController.h"
#include "TicTacToe.h"
#include "ui_Menu.h"

Menu::Menu(QWidget *parent) :
                              QMainWindow(parent),
                              ui(new Ui::Menu)
{
  ui->setupUi(this);
}

Menu::~Menu()
{
  delete ui;
}

void Menu::on_playButton_clicked() {
  FluxController::switchScene(this, new TicTacToe);
}

void Menu::on_quitButton_clicked() { this->close(); }
