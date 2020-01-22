#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

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

  private:
  Ui::MainWindow *ui;
};

#endif  // APPLICATION_WINDOW_H
