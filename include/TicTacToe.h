#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class TicTacToe; }
QT_END_NAMESPACE

class TicTacToe : public QMainWindow
{
    Q_OBJECT

public:
    enum Player{
        PLAYER1,
        PLAYER2
    };

    Player player;

public:
    TicTacToe(QWidget *parent = nullptr);
    ~TicTacToe();

private slots:
    void on_pushButton_1_clicked();

private:
    Ui::TicTacToe *ui;
    void pressButton(QPushButton& button);
    void togglePlayer();
};
#endif // TICTACTOE_H
