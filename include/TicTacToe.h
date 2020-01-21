#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QMainWindow>
#include <QString>

class QPushButton;

QT_BEGIN_NAMESPACE
namespace Ui
{
  class TicTacToe;
}
QT_END_NAMESPACE

class TicTacToe : public QMainWindow
{
  Q_OBJECT

  enum Player
  {
    PLAYER1,
    PLAYER2
  };

  public:
  QString getTurnPlayer()
  {
    if (m_turnPlayer == PLAYER1)
      return m_player1Name;
    else
      return m_player2Name;
  }

  public:
  TicTacToe(QString player1Name, QString player2Name, QWidget *parent = nullptr);
  ~TicTacToe();

  private slots:
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

  private:
  void togglePlayer();
  void play(QPushButton *square);
  // There are three win cases
  bool columnWin();
  bool diagonalWin();
  bool rowWin();
  void disableAllButtons();
  bool threeButtonComparison(QString first, QString second, QString third);
  bool draw();

  private:
  Ui::TicTacToe *ui;
  QString m_player1Name;
  QString m_player2Name;
  Player m_turnPlayer;
};
#endif  // TICTACTOE_H
