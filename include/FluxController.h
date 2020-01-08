#ifndef FLUXCONTROLLER_H
#define FLUXCONTROLLER_H

class QMainWindow;

class FluxController {
 public:
  static void switchScene(QMainWindow* currentWindow, QMainWindow* nextWindow);
};

#endif // FLUXCONTROLLER_H
