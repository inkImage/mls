#include "mainwindow.h"
//#include <QtWidgets>
#include <QImage>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);

    setGeometry(300, 150, 800, 450);

    imagewidget_ = new ImageWidget();
    setCentralWidget(imagewidget_);

    CreateActions();
    CreateMenus();
    CreateToolBars();
    CreateStatusBar();
}

MainWindow::~MainWindow()
{
}

//void MainWindow::closeEvent(QCloseEvent *e)
//{
//}

//void MainWindow::paintEvent(QPaintEvent* paintevent)
//{
//}

void MainWindow::CreateActions()
{
    action_new_ = new QAction(QIcon("/home/yzchen/work/Qt/mlsdeform/Resources/images/new.png"), tr("&New"), this);
    action_new_->setShortcut(QKeySequence::New);
    action_new_->setStatusTip(tr("Create a new file"));

    action_open_ = new QAction(QIcon("/home/yzchen/work/Qt/mlsdeform/Resources/images/open.png"), tr("&Open..."), this);
    action_open_->setShortcuts(QKeySequence::Open);
    action_open_->setStatusTip(tr("Open an existing file"));
    connect(action_open_, SIGNAL(triggered()), imagewidget_, SLOT(Open()));

    action_save_ = new QAction(QIcon("/home/yzchen/work/Qt/mlsdeform/Resources/images/save.png"), tr("&Save"), this);
    action_save_->setShortcuts(QKeySequence::Save);
    action_save_->setStatusTip(tr("Save the document to disk"));

    action_saveas_ = new QAction(tr("Save &As..."), this);
    action_saveas_->setShortcuts(QKeySequence::SaveAs);
    action_saveas_->setStatusTip(tr("Save the document under a new name"));
    connect(action_saveas_, SIGNAL(triggered()), imagewidget_, SLOT(SaveAs()));

    action_invert_ = new QAction(tr("Inverse"), this);
    action_invert_->setStatusTip(tr("Invert all pixel value in the image"));
    connect(action_invert_, SIGNAL(triggered()), imagewidget_, SLOT(Invert()));

    action_mirror_ = new QAction(tr("Mirror"), this);
    action_mirror_->setStatusTip(tr("Mirror image vertically or horizontally"));
    connect(action_mirror_, SIGNAL(triggered()), imagewidget_, SLOT(Mirror()));

    action_gray_ = new QAction(tr("Grayscale"), this);
    action_gray_->setStatusTip(tr("Gray-scale map"));
    connect(action_gray_, SIGNAL(triggered()), imagewidget_, SLOT(TurnGray()));

    action_restore_ = new QAction(tr("Restore"), this);
    action_restore_->setStatusTip(tr("Show origin image"));
    connect(action_restore_, SIGNAL(triggered()), imagewidget_, SLOT(Restore()));

    action_affine_ = new QAction(tr("Affine"), this);
    connect(action_affine_, SIGNAL(triggered()), imagewidget_, SLOT(setKtype_to_Affine()));

    action_similarity_ = new QAction(tr("Similarity"), this);
    connect(action_similarity_, SIGNAL(triggered()), imagewidget_, SLOT(setKtype_to_Similarity()));

    action_rigid_ = new QAction(tr("Rigid"), this);
    connect(action_rigid_, SIGNAL(triggered()), imagewidget_, SLOT(setKtype_to_Rigid()));
}

void MainWindow::CreateMenus()
{
    menu_file_ = menuBar()->addMenu(tr("&File"));
    menu_file_->setStatusTip(tr("File menu"));
    menu_file_->addAction(action_new_);
    menu_file_->addAction(action_open_);
    menu_file_->addAction(action_save_);
    menu_file_->addAction(action_saveas_);

    menu_edit_ = menuBar()->addMenu(tr("&Edit"));
    menu_edit_->setStatusTip(tr("Edit menu"));
    menu_edit_->addAction(action_invert_);
    menu_edit_->addAction(action_mirror_);
    menu_edit_->addAction(action_gray_);
    menu_edit_->addAction(action_restore_);
}

void MainWindow::CreateToolBars()
{
    toolbar_file_ = addToolBar(tr("File"));
    toolbar_file_->addAction(action_new_);
    toolbar_file_->addAction(action_open_);
    toolbar_file_->addAction(action_save_);

    // Add separator in toolbar
    toolbar_file_->addSeparator();
    toolbar_file_->addAction(action_invert_);
    toolbar_file_->addAction(action_mirror_);
    toolbar_file_->addAction(action_gray_);
    toolbar_file_->addAction(action_restore_);

    toolbar_deform_ = addToolBar(tr("Deform"));
    toolbar_deform_->addAction(action_affine_);
    toolbar_deform_->addAction(action_similarity_);
    toolbar_deform_->addAction(action_rigid_);
}

void MainWindow::CreateStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}
