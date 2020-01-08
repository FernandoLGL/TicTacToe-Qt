#include "FluxController.h"
#include <QMainWindow>

void FluxController::switchScene(QMainWindow *currentWindow,
                                 QMainWindow *nextWindow) {
  currentWindow->hide();
  nextWindow->show();
  currentWindow->close();
}
