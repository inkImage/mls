#include "imagewidget.h"
#include <QImage>
#include <QPainter>
#include <QWidget>
#include <iostream>

#include "mlsdaffine.h"
#include "mlsdsimilarity.h"
#include "mlsdrigid.h"

using namespace std;

ImageWidget::ImageWidget(void)
{
    dmove = false;
    deform = false;
    kType = SIMILARITY;
}


ImageWidget::~ImageWidget(void)
{
}

void ImageWidget::mousePressEvent(QMouseEvent *event){
    if(Qt::LeftButton == event->button()){
        dmove = true;
        startp = endp = event->pos();
    }
    if(Qt::RightButton == event->button()){
        deform = true;
    }
}

void ImageWidget::mouseMoveEvent(QMouseEvent *event){
    if(dmove){
        endp = event->pos();
    }
}

void ImageWidget::mouseReleaseEvent(QMouseEvent *event){
    //cout << this << endl;
    if(!deform){
        p_.push_back(Point2d(startp.x(), startp.y()));
        q_.push_back(Point2d(endp.x(), endp.y()));

        cout<<"p : "<<p_.back().x<<"   "<<p_.back().y<<endl;
        cout<<"q : "<<q_.back().x<<"   "<<q_.back().y<<endl;
    }

    if(deform){
        MLSD *deformobject;
        switch (kType) {
        case AFFINE: {
                deformobject = new MLSDAffine();
                Mat dst_image = deformobject->Initialize(image_mat_, p_,q_,
                                                    image_mat_.cols,image_mat_.rows);
                image_mat_ = dst_image;
                cvtColor( image_mat_, rgb_image_mat_, CV_BGR2RGB );
//                imshow("dst", dst_image);
            }
            break;
        case SIMILARITY:{
                deformobject = new MLSDSimilarity();
                Mat dst_image = deformobject->Initialize(image_mat_, p_,q_,
                                                    image_mat_.cols,image_mat_.rows);
                image_mat_ = dst_image;
                cvtColor( image_mat_, rgb_image_mat_, CV_BGR2RGB );
//                imshow("dst", dst_image);
            }
            break;
        case RIGID:{
                deformobject = new MLSDRigid();
                Mat dst_image = deformobject->Initialize(image_mat_, p_,q_,
                                                    image_mat_.cols,image_mat_.rows);
                image_mat_ = dst_image;
                cvtColor( image_mat_, rgb_image_mat_, CV_BGR2RGB );
//                imshow("dst", dst_image);
            }
            break;
        default:
            break;
        }
        p_.clear();
        q_.clear();
    }

    dmove = false;
    deform = false;
    update();
}

void ImageWidget::paintEvent(QPaintEvent *paintevent)
{
    QPainter painter;
    painter.begin(this);

    // Draw background
    painter.setBrush(Qt::lightGray);
    QRect back_rect(0, 0, width(), height());
    painter.drawRect(back_rect);

    // Draw image
    QImage image_show = QImage( (unsigned char *)(rgb_image_mat_.data), rgb_image_mat_.cols, rgb_image_mat_.rows, rgb_image_mat_.step, QImage::Format_RGB888 );
    QRect rect = QRect(0, 0, image_show.width(), image_show.height());
    painter.drawImage(rect, image_show);

    painter.end();
}

void ImageWidget::Open()
{
    // Open file
    QString fileName = QFileDialog::getOpenFileName(this, tr("Read Image"), ".", tr("Images(*.bmp *.png *.jpg)"));

    // Load file
    if (!fileName.isEmpty())
    {
        image_mat_ = cv::imread( fileName.toLatin1().data() );
        cvtColor( image_mat_, rgb_image_mat_, CV_BGR2RGB );         //bgr to rgb
        image_mat_backup_ = rgb_image_mat_.clone();
    }

    update();
}

void ImageWidget::Save()
{
    SaveAs();
}

void ImageWidget::SaveAs()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save Image"), ".", tr("Images(*.bmp *.png *.jpg)"));
    if (filename.isNull())
    {
        return;
    }

    Mat image_save;
    cvtColor(rgb_image_mat_, image_save, CV_RGB2BGR);
    imwrite(filename.toLatin1().data(), image_save);
}

void ImageWidget::Invert()
{
    MatIterator_<Vec3b> iter, iterend;
    for (iter=image_mat_.begin<Vec3b>(), iterend=image_mat_.end<Vec3b>(); iter != iterend; ++iter)
    {
        (*iter)[0] = 255-(*iter)[0];
        (*iter)[1] = 255-(*iter)[1];
        (*iter)[2] = 255-(*iter)[2];
    }
    cvtColor( image_mat_, rgb_image_mat_, CV_BGR2RGB );
    update();
}

void ImageWidget::Mirror(bool ishorizontal, bool isvertical)
{
    int width = image_mat_.cols;
    int height = image_mat_.rows;

    if (ishorizontal)
    {
        if (isvertical)
        {
            for (int i=0; i<width; i++)
            {
                for (int j=0; j<height; j++)
                {
                    image_mat_.at<Vec3b>(j, i) = image_mat_backup_.at<Vec3b>(height-1-j, width-1-i);
                }
            }
        }
        else
        {
            for (int i=0; i<width; i++)
            {
                for (int j=0; j<height; j++)
                {
                    image_mat_.at<Vec3b>(j, i) = image_mat_backup_.at<Vec3b>(j, width-1-i);
                }
            }
        }

    }
    else
    {
        if (isvertical)
        {
            for (int i=0; i<width; i++)
            {
                for (int j=0; j<height; j++)
                {
                    image_mat_.at<Vec3b>(j, i) = image_mat_backup_.at<Vec3b>(height-1-j, i);
                }
            }
        }
    }
    cvtColor( image_mat_, rgb_image_mat_, CV_BGR2RGB );
    update();
}

void ImageWidget::TurnGray()
{
    MatIterator_<Vec3b> iter, iterend;
    for (iter=image_mat_.begin<Vec3b>(), iterend=image_mat_.end<Vec3b>(); iter != iterend; ++iter)
    {
        int itmp = ((*iter)[0]+(*iter)[1]+(*iter)[2])/3;
        (*iter)[0] = itmp;
        (*iter)[1] = itmp;
        (*iter)[2] = itmp;
    }
    cvtColor( image_mat_, rgb_image_mat_, CV_BGR2RGB );
    update();
}

void ImageWidget::Restore()
{
    image_mat_ = image_mat_backup_.clone();
    cvtColor( image_mat_, rgb_image_mat_, CV_BGR2RGB );
    update();
}

void ImageWidget::setKtype_to_Affine(){
    kType = AFFINE;
}

void ImageWidget::setKtype_to_Similarity(){
    kType = SIMILARITY;
}

void ImageWidget::setKtype_to_Rigid(){
    kType = RIGID;
}
