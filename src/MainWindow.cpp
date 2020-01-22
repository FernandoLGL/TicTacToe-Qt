#include "MainWindow.h"

#include "TicTacToe.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_playButton_clicked()
{
  // Random names if blank
  if (ui->player1NameWidget->text() == "") { ui->player1NameWidget->setText("Foo"); }
  if (ui->player2NameWidget->text() == "") { ui->player2NameWidget->setText("Bar"); }
  // 1 is the game page itself
  ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_quitButton_clicked() { this->close(); }
