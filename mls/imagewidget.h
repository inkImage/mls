#pragma once
#include <QWidget>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <vector>
#include <QAction>
#include <QToolBar>
#include <QMessageBox>
#include <QMenu>
#include <QRect>
#include <QMenuBar>
#include <QStatusBar>
#include <QMouseEvent>
#include <QFileDialog>

using namespace cv;
using namespace std;

QT_BEGIN_NAMESPACE
class QImage;
class QPainter;
QT_END_NAMESPACE

enum type{
    AFFINE,
    SIMILARITY,
    RIGID
};

class ImageWidget :
    public QWidget
{
    Q_OBJECT

public:
    ImageWidget(void);
    ~ImageWidget(void);

protected:
    void paintEvent(QPaintEvent *paintevent);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

public slots:
    // File IO
    void Open();												// Open an image file, support ".bmp, .png, .jpg" format
    void Save();												// Save image to current file
    void SaveAs();												// Save image to another file

    // Image processing
    void Invert();												// Invert pixel value in image
    void Mirror(bool horizontal=false, bool vertical=true);		// Mirror image vertically or horizontally
    void TurnGray();											// Turn image to gray-scale map
    void Restore();												// Restore image to origin

    void setKtype_to_Affine();
    void setKtype_to_Similarity();
    void setKtype_to_Rigid();

private:
    Mat										image_mat_;
    Mat                                      rgb_image_mat_;
    Mat										image_mat_backup_;
    bool                                    dmove;
    QPoint                                startp;
    QPoint                                endp;
    int                                       kType;

private:
    vector<Point2d>                    p_;
    vector<Point2d>                    q_;
    bool                                    deform;
};

