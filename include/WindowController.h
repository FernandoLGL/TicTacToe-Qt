#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H


class QWidget;
class MainWindow;

class WindowController
{
public:
	WindowController() = delete;

public:
	static void switchToPage(MainWindow * window, int pageIndex);
private:
	static void resetPage(QWidget * page);
};

#endif // WINDOWCONTROLLER_H
