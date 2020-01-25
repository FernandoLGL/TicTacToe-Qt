#include "MainWindow.h"

#include "TicTacToe.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->backToMenuButton->hide();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_playButton_clicked()
{
  QString player1Name;
  QString player2Name;
  // Random names if blank
  if (ui->player1NameWidget->text() == "") { player1Name = "Foo"; }
  else
  {
    player1Name = ui->player1NameWidget->text();
  }
  if (ui->player2NameWidget->text() == "") { player2Name = "Bar"; }
  else
  {
    player2Name = ui->player2NameWidget->text();
  }
  TicTacToe::initializeNames(player1Name, player2Name);
  // Setting the turn player to be who the user chose to be
  checkForStartingPlayer();
  ui->turnAnnouncement->setText(TicTacToe::getTurnPlayer() + "'s turn!");
  // 1 is the game page itself
  WindowController::switchToPage(this, 1);
  ui->backToMenuButton->show();
}

void MainWindow::on_quitButton_clicked() { this->close(); }

void MainWindow::on_firstButton_clicked() { play(ui->firstButton); }

void MainWindow::on_secondButton_clicked() { play(ui->secondButton); }

void MainWindow::on_thirdButton_clicked() { play(ui->thirdButton); }

void MainWindow::on_fourthButton_clicked() { play(ui->fourthButton); }

void MainWindow::on_fifthButton_clicked() { play(ui->fifthButton); }

void MainWindow::on_sixthButton_clicked() { play(ui->sixthButton); }

void MainWindow::on_seventhButton_clicked() { play(ui->seventhButton); }

void MainWindow::on_eighthButton_clicked() { play(ui->eighthButton); }

void MainWindow::on_ninethButton_clicked() { play(ui->ninethButton); }

void MainWindow::play(QPushButton *button)
{
  // If the button has already been played
  if (!button->text().isNull()) return;
  QList<QPushButton *> playableButtons{ ui->firstButton,   ui->secondButton, ui->thirdButton,
                                        ui->fourthButton,  ui->fifthButton,  ui->sixthButton,
                                        ui->seventhButton, ui->eighthButton, ui->ninethButton };
  TicTacToe::markPosition(button);
  // Before toggling the player we have to check if there is a winner
  if (TicTacToe::columnWin(playableButtons) || TicTacToe::rowWin(playableButtons)
      || TicTacToe::diagonalWin(playableButtons))
  {
    ui->turnAnnouncement->setText(TicTacToe::getTurnPlayer() + " wins!");
    // Disabling so that the user can't click the buttons anymore once there is a winner
    disableAllPlayableButtons();
    // For now just return
    return;
  }
  if (TicTacToe::draw(playableButtons))
  {
    ui->turnAnnouncement->setText("The game ends in a draw!");
    disableAllPlayableButtons();
    return;
  }
  TicTacToe::togglePlayer();
  ui->turnAnnouncement->setText(TicTacToe::getTurnPlayer() + "'s turn!");
}

void MainWindow::disableAllPlayableButtons()
{
  QList<QPushButton *> buttons = ui->gamePage->findChildren<QPushButton *>();
  foreach (const auto &button, buttons)
  {
    button->setDisabled(true);
  }
}

void MainWindow::checkForStartingPlayer()
{
  if (ui->player1First->isChecked())
    TicTacToe::setTurnPlayer(TicTacToe::PLAYER1);
  else
    TicTacToe::setTurnPlayer(TicTacToe::PLAYER2);
}

void MainWindow::on_backToMenuButton_clicked()
{
  WindowController::switchToPage(this, 0);
  ui->backToMenuButton->hide();
}
