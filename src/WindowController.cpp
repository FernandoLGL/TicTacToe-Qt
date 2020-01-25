#include "WindowController.h"

#include "MainWindow.h"
#include "ui_MainWindow.h"

void WindowController::switchToPage(MainWindow *window, int pageIndex)
{
  window->ui->stackedWidget->setCurrentIndex(pageIndex);
  reset(window);
}

void WindowController::reset(MainWindow *window)
{
  window->ui->firstButton->setText(QString());
  window->ui->secondButton->setText(QString());
  window->ui->thirdButton->setText(QString());
  window->ui->fourthButton->setText(QString());
  window->ui->fifthButton->setText(QString());
  window->ui->sixthButton->setText(QString());
  window->ui->seventhButton->setText(QString());
  window->ui->eighthButton->setText(QString());
  window->ui->ninethButton->setText(QString());

  window->ui->player1NameWidget->setText(QString());
  window->ui->player2NameWidget->setText(QString());

  QList<QPushButton *> buttons = window->ui->gamePage->findChildren<QPushButton *>();
  foreach (const auto &button, buttons)
  {
    button->setDisabled(false);
  }
}
