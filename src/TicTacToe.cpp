#include "TicTacToe.h"

#include "MainWindow.h"

TicTacToe::TicTacToe(QString player1Name, QString player2Name) :
    m_player1Name(player1Name), m_player2Name(player2Name), m_turnPlayer(PLAYER1)
{
}

void TicTacToe::togglePlayer()
{
  if (m_turnPlayer == PLAYER1)
    m_turnPlayer = PLAYER2;
  else
    m_turnPlayer = PLAYER1;
}

// void TicTacToe::disableAllButtons()
//{
//  QList<QPushButton *> buttons = this->findChildren<QPushButton *>();
//  foreach (const auto &button, buttons)
//  {
//    button->setDisabled(true);
//  }
//}
//
// bool TicTacToe::draw()
//{
//  // There is no need to check if there isn't a winner here. Because we only call this method when
//  // we are already checked that.
//  QList<QPushButton *> buttons = this->findChildren<QPushButton *>();
//  foreach (const auto &button, buttons)
//  {
//    if (button->text().isNull()) return false;
//  }
//  return true;
//}
//
// bool TicTacToe::rowWin()
//{
//  QString firstButton = ui->firstButton->text();
//  QString secondButton = ui->secondButton->text();
//  QString thirdButton = ui->thirdButton->text();
//  QString fourthButton = ui->fourthButton->text();
//  QString fifthButton = ui->fifthButton->text();
//  QString sixthButton = ui->sixthButton->text();
//  QString seventhButton = ui->seventhButton->text();
//  QString eigthButton = ui->eigthButton->text();
//  QString ninethButton = ui->ninethButton->text();
//
//  bool firstRowWin = threeButtonComparison(firstButton, secondButton, thirdButton);
//  bool secondRowWin = threeButtonComparison(fourthButton, fifthButton, sixthButton);
//  bool thirdRowWin = threeButtonComparison(seventhButton, eigthButton, ninethButton);
//  return firstRowWin || secondRowWin || thirdRowWin;
//}
//
// bool TicTacToe::threeButtonComparison(QString first, QString second, QString third)
//{
//  return (!first.isNull() && !second.isNull() && !third.isNull()) && (first == second)
//         && (second == third);
//}
//
// bool TicTacToe::diagonalWin()
//{
//  QString firstButton = ui->firstButton->text();
//  QString fifthButton = ui->fifthButton->text();
//  QString ninethButton = ui->ninethButton->text();
//  QString thirdButton = ui->thirdButton->text();
//  QString seventhButton = ui->seventhButton->text();
//
//  bool firstDiagonalWin = threeButtonComparison(firstButton, fifthButton, ninethButton);
//
//  bool secondDiagonalWin = threeButtonComparison(thirdButton, fifthButton, seventhButton);
//
//  return firstDiagonalWin || secondDiagonalWin;
//}
//
//// This is called whenever the user plays (clicks a square)
// void TicTacToe::play(QPushButton *square)
//{
//  if (!square->text().isNull()) return;
//  if (m_turnPlayer == PLAYER1)
//  {
//    square->setStyleSheet(square->styleSheet() + "color: rgb(170, 0, 0);");
//    square->setText("X");
//  }
//  else
//  {
//    square->setStyleSheet(square->styleSheet() + "color: rgb(0, 85, 127);");
//    square->setText("O");
//  }
//  // Before toggling the player we have to check if there is a winner
//  if (diagonalWin() || rowWin() || columnWin())
//  {
//    ui->turnAnnouncement->setText(getTurnPlayer() + " wins!");
//    // Disabling so that the user can't click the buttons anymore once there is a winner
//    disableAllButtons();
//    // For now just return
//    return;
//  }
//  if (draw())
//  {
//    ui->turnAnnouncement->setText("The game ends in a draw!");
//    disableAllButtons();
//    return;
//  }
//  togglePlayer();
//  ui->turnAnnouncement->setText(getTurnPlayer() + "'s turn!");
//}
//
// bool TicTacToe::columnWin()
//{
//  QString firstButton = ui->firstButton->text();
//  QString secondButton = ui->secondButton->text();
//  QString thirdButton = ui->thirdButton->text();
//  QString fourthButton = ui->fourthButton->text();
//  QString fifthButton = ui->fifthButton->text();
//  QString sixthButton = ui->sixthButton->text();
//  QString seventhButton = ui->seventhButton->text();
//  QString eigthButton = ui->eigthButton->text();
//  QString ninethButton = ui->ninethButton->text();
//
//  bool firstColumnWin = threeButtonComparison(firstButton, fourthButton, seventhButton);
//  bool secondColumnWin = threeButtonComparison(secondButton, fifthButton, eigthButton);
//  bool thirdColumnWin = threeButtonComparison(thirdButton, sixthButton, ninethButton);
//
//  return firstColumnWin || secondColumnWin || thirdColumnWin;
//}
//
// void TicTacToe::on_backToMenuButton_clicked() { FluxController::switchScene(this, new Menu); }
//
// void TicTacToe::on_firstButton_clicked() { play(ui->firstButton); }
//
// void TicTacToe::on_secondButton_clicked() { play(ui->secondButton); }
//
// void TicTacToe::on_thirdButton_clicked() { play(ui->thirdButton); }
//
// void TicTacToe::on_fourthButton_clicked() { play(ui->fourthButton); }
//
// void TicTacToe::on_fifthButton_clicked() { play(ui->fifthButton); }
//
// void TicTacToe::on_sixthButton_clicked() { play(ui->sixthButton); }
//
// void TicTacToe::on_seventhButton_clicked() { play(ui->seventhButton); }
//
// void TicTacToe::on_eigthButton_clicked() { play(ui->eigthButton); }
//
// void TicTacToe::on_ninethButton_clicked() { play(ui->ninethButton); }
