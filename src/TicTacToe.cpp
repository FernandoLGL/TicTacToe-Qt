#include "TicTacToe.h"
#include "ui_TicTacToe.h"

TicTacToe::TicTacToe(QWidget *parent)
    : QMainWindow(parent)
    , player(PLAYER1)
    , ui(new Ui::TicTacToe)
{
    ui->setupUi(this);
}

TicTacToe::~TicTacToe()
{
    delete ui;
}

void TicTacToe::togglePlayer(){
    if(player == PLAYER1){
        player = PLAYER2;
        return;
    }
    player = PLAYER1;
}

void TicTacToe::pressButton(QPushButton &button){
    if(player == PLAYER1)
        button.setText("X");
    else
        button.setText("O");
}

void TicTacToe::on_pushButton_1_clicked()
{
    pressButton(*(ui->pushButton_1));
}
