#include "TicTacToe.h"

#include <QPushButton>

#include "MainWindow.h"

TicTacToe::Player TicTacToe::m_turnPlayer = PLAYER1;
QString TicTacToe::m_player1Name;
QString TicTacToe::m_player2Name;
TicTacToe::Player TicTacToe::m_startingPlayer;

// TODO: Change the Board to a QVariantHash or something like that

void TicTacToe::togglePlayer()
{
  if (m_turnPlayer == PLAYER1)
    m_turnPlayer = PLAYER2;
  else
    m_turnPlayer = PLAYER1;
}

void TicTacToe::initializeNames(const QString &player1Name, const QString &player2Name)
{
  m_player1Name = player1Name;
  m_player2Name = player2Name;
}

bool TicTacToe::draw(QList<QPushButton *> board)
{
  // There is no need to check if there isn't a winner here. Because we only call this method when
  // we are already checked that.
  foreach (const auto &button, board)
  {
    if (button->text().isNull()) return false;
  }
  return true;
}

bool TicTacToe::rowWin(QList<QPushButton *> board)
{
  QString firstButton = board[0]->text();
  QString secondButton = board[1]->text();
  QString thirdButton = board[2]->text();
  QString fourthButton = board[3]->text();
  QString fifthButton = board[4]->text();
  QString sixthButton = board[5]->text();
  QString seventhButton = board[6]->text();
  QString eigthButton = board[7]->text();
  QString ninethButton = board[8]->text();

  bool firstRowWin = threeButtonComparison(firstButton, secondButton, thirdButton);
  bool secondRowWin = threeButtonComparison(fourthButton, fifthButton, sixthButton);
  bool thirdRowWin = threeButtonComparison(seventhButton, eigthButton, ninethButton);
  return firstRowWin || secondRowWin || thirdRowWin;
}

bool TicTacToe::threeButtonComparison(QString first, QString second, QString third)
{
  return (!first.isNull() && !second.isNull() && !third.isNull()) && (first == second)
         && (second == third);
}

bool TicTacToe::diagonalWin(QList<QPushButton *> board)
{
  QString firstButton = board[0]->text();
  QString fifthButton = board[4]->text();
  QString ninethButton = board[8]->text();
  QString thirdButton = board[2]->text();
  QString seventhButton = board[6]->text();

  bool firstDiagonalWin = threeButtonComparison(firstButton, fifthButton, ninethButton);

  bool secondDiagonalWin = threeButtonComparison(thirdButton, fifthButton, seventhButton);

  return firstDiagonalWin || secondDiagonalWin;
}

// This is called whenever the user plays (clicks a square)
void TicTacToe::markPosition(QPushButton *square)
{
  if (!square->text().isNull()) return;
  if (m_turnPlayer == PLAYER1)
  {
    square->setStyleSheet(square->styleSheet() + "color: rgb(170, 0, 0);");
    square->setText("X");
  }
  else
  {
    square->setStyleSheet(square->styleSheet() + "color: rgb(0, 85, 127);");
    square->setText("O");
  }
}

bool TicTacToe::columnWin(QList<QPushButton *> board)
{
  QString firstButton = board[0]->text();
  QString secondButton = board[1]->text();
  QString thirdButton = board[2]->text();
  QString fourthButton = board[3]->text();
  QString fifthButton = board[4]->text();
  QString sixthButton = board[5]->text();
  QString seventhButton = board[6]->text();
  QString eigthButton = board[7]->text();
  QString ninethButton = board[8]->text();

  bool firstColumnWin = threeButtonComparison(firstButton, fourthButton, seventhButton);
  bool secondColumnWin = threeButtonComparison(secondButton, fifthButton, eigthButton);
  bool thirdColumnWin = threeButtonComparison(thirdButton, sixthButton, ninethButton);

  return firstColumnWin || secondColumnWin || thirdColumnWin;
}
