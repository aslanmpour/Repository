#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamebored.h"
#include <QMediaPlayer>


namespace Ui {
class MainWindow;
}



/** @class MainWindow
@brief represents the main menu

contains instructions and a button that draws
the game (class GameBored)

*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void easy_game_begin();

private:
    Ui::MainWindow *ui;
    //GameBored* Board;
    QMediaPlayer* menusong;
};

#endif // MAINWINDOW_H
