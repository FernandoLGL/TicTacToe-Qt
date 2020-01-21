#include "include/Menu.h"

#include "FluxController.h"
#include "TicTacToe.h"
#include "ui_Menu.h"

Menu::Menu(QWidget *parent) : QMainWindow(parent), ui(new Ui::Menu) { ui->setupUi(this); }

Menu::~Menu() { delete ui; }

void Menu::on_playButton_clicked()
{
  // Random names if blank
  if (ui->firstPlayerName->text() == "") { ui->firstPlayerName->setText("Foo"); }
  if (ui->secondPlayerName->text() == "") { ui->secondPlayerName->setText("Bar"); }

  FluxController::switchScene(
      this, new TicTacToe(ui->firstPlayerName->text(), ui->secondPlayerName->text()));
}

void Menu::on_quitButton_clicked() { this->close(); }
