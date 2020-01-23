#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

class QPushButton;

namespace Ui
{
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

  public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  private slots:
  void on_playButton_clicked();

  void on_quitButton_clicked();

  void on_firstButton_clicked();

  void on_secondButton_clicked();

  void on_thirdButton_clicked();

  void on_fourthButton_clicked();

  void on_fifthButton_clicked();

  void on_sixthButton_clicked();

  void on_seventhButton_clicked();

  void on_eighthButton_clicked();

  void on_ninethButton_clicked();

  void on_backToMenuButton_clicked();

  private:
  void play(QPushButton *button);
  void disableAllPlayableButtons();

  private:
  Ui::MainWindow *ui;
};

#endif  // APPLICATION_WINDOW_H
