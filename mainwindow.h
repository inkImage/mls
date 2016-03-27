#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "imagewidget.h"

QT_BEGIN_NAMESPACE
        class QAction;
        class QImage;
        class ViewWidget;
        class QMenu;
        class QPainter;
        class QRect;
        class Deform;
        class ImageWidget;
QT_END_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

//protected:
//    void closeEvent(QCloseEvent *);
//    void paintEvent(QPaintEvent *);

private:
   void CreateActions();
   void CreateMenus();
   void CreateToolBars();
   void CreateStatusBar();

private:
        Ui::MainWindow *ui;

        QMenu		*menu_file_;
        QMenu		*menu_edit_;
        QMenu		*menu_help_;

        QToolBar    	*toolbar_file_;
        QToolBar    	*toolbar_edit_;
        QToolBar    *toolbar_deform_;

        QAction		*action_new_;
        QAction		*action_open_;
        QAction		*action_save_;
        QAction		*action_saveas_;

        QAction		*action_invert_;
        QAction		*action_mirror_;
        QAction		*action_gray_;
        QAction		*action_restore_;

        QAction      *action_affine_;
        QAction      *action_similarity_;
        QAction      *action_rigid_;

        ImageWidget		*imagewidget_;
};

#endif // MAINWINDOW_H
