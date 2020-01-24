#include "WindowController.h"
#include "MainWindow.h"
#include "ui_MainWindow.h"


void WindowController::switchToPage(MainWindow * window, int pageIndex)
{
	window->ui->stackedWidget->setCurrentIndex(pageIndex);
	switch(pageIndex){
	case 0: resetPage(window->ui->gamePage); break;
	default: resetPage(window->ui->menuPage);
	}
}

void WindowController::resetPage(QWidget *page)
{

}
