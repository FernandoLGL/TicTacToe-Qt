#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QString>

class QPushButton;
class QWidget;

class TicTacToe
{
  enum Player
  {
    PLAYER1,
    PLAYER2
  };

  public:
  void on_backToMenuButton_clicked();

  void on_firstButton_clicked();

  void on_secondButton_clicked();

  void on_thirdButton_clicked();

  void on_fourthButton_clicked();

  void on_fifthButton_clicked();

  void on_sixthButton_clicked();

  void on_seventhButton_clicked();

  void on_eigthButton_clicked();

  void on_ninethButton_clicked();

  public:
  static void markPosition(QPushButton *square);
  // There are three win cases
  static bool columnWin(QList<QPushButton *> board);
  static bool diagonalWin(QList<QPushButton *> board);
  static bool rowWin(QList<QPushButton *> board);
  static bool draw(QList<QPushButton *> board);
  static void togglePlayer();

  public:
  static void initializeNames(const QString &player1Name, const QString &player2Name);
  static QString getPlayer1Name() { return m_player1Name; }
  static QString getPlayer2Name() { return m_player2Name; }
  static QString getTurnPlayer()
  {
    if (m_turnPlayer == PLAYER1)
      return m_player1Name;
    else
      return m_player2Name;
  }

  private:
  static bool threeButtonComparison(QString first, QString second, QString third);

  private:
  static QString m_player1Name;
  static QString m_player2Name;
  static Player m_turnPlayer;
};
#endif  // TICTACTOE_H
