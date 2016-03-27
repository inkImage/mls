#include "mlsdeformation.h"
#include <cstdio>

MLSD::MLSD(){

}

MLSD::~MLSD(){

}

inline double bilinear_interp(double x, double y, double v11, double v12,
                              double v21, double v22) {
    return (v11 * (1 - y) + v12 * y) * (1 - x) + (v21 * (1 - y) + v22 * y) * x;
}

Mat MLSD::Initialize(const Mat &oriImg, const vector<Point2d> &qsrc, const vector<Point2d> &qdst,
                     const int outW, const int outH, const int grid_size, const double al_pha){
    gridsize = grid_size;
    alpha = al_pha;

    setSize(oriImg.cols, oriImg.rows);
    setOutSize(outW, outH);

    setSrcPoints(qsrc);
    setDstPoints(qdst);

    cout<<"done"<<endl;
    calcDelta();                //get rDx and rDy to apply bilinear interplation
    return genNewImg(oriImg);
}

void MLSD::setSrcPoints(const vector<Point2d> &qsrc){
    nPoint = qsrc.size();
    oldDotL.clear();
    for(int i = 0; i < nPoint; i++)
        oldDotL.push_back(qsrc[i]);         //reverse, but has no influence
}

void MLSD::setDstPoints(const vector<Point2d> &qdst){
    nPoint = qdst.size();
    newDotL.clear();
    for(int i = 0; i < nPoint; i++)
        newDotL.push_back(qdst[i]);
}

Mat MLSD::genNewImg(const Mat &oriImg) {
    int i, j;
    double di, dj;
    double nx, ny;
    int nxi, nyi, nxi1, nyi1;
    double deltaX, deltaY;
    double w, h;
    int ni, nj;

    Mat newImg(tarH, tarW, oriImg.type());
    for (i = 0; i < tarH; i += gridsize)                //i : y
        for (j = 0; j < tarW; j += gridsize) {         //j : x
            ni = i + gridsize, nj = j + gridsize;
            w = h = gridsize;
            if (ni >= tarH)     ni = tarH - 1, h = ni - i + 1;
            if (nj >= tarW)     nj = tarW - 1, w = nj - j + 1;
            for (di = 0; di < h; di++)
                for (dj = 0; dj < w; dj++) {
                    deltaX =
                        bilinear_interp(di / h, dj / w, rDx(i, j), rDx(i, nj),
                                        rDx(ni, j), rDx(ni, nj));
                    deltaY =
                        bilinear_interp(di / h, dj / w, rDy(i, j), rDy(i, nj),
                                        rDy(ni, j), rDy(ni, nj));
                    nx = j + dj + deltaX;
                    ny = i + di + deltaY;
                    if (nx > srcW - 1)      nx = srcW - 1;
                    if (ny > srcH - 1)       ny = srcH - 1;
                    if (nx < 0)     nx = 0;
                    if (ny < 0)     ny = 0;
                    nxi = int(nx);
                    nyi = int(ny);
                    nxi1 = ceil(nx);
                    nyi1 = ceil(ny);

                    if (oriImg.channels() == 1)
                        newImg.at<uchar>(i + di, j + dj) = bilinear_interp(
                            ny - nyi, nx - nxi, oriImg.at<uchar>(nyi, nxi),
                            oriImg.at<uchar>(nyi, nxi1),
                            oriImg.at<uchar>(nyi1, nxi),
                            oriImg.at<uchar>(nyi1, nxi1));
                    else {
                        for (int ll = 0; ll < 3; ll++)
                            newImg.at<Vec3b>(i + di, j + dj)[ll] =
                                bilinear_interp(
                                    ny - nyi, nx - nxi,
                                    oriImg.at<Vec3b>(nyi, nxi)[ll],
                                    oriImg.at<Vec3b>(nyi, nxi1)[ll],
                                    oriImg.at<Vec3b>(nyi1, nxi)[ll],
                                    oriImg.at<Vec3b>(nyi1, nxi1)[ll]);
                    }
                }
        }

    for(int i = 0; i < nPoint; i++){
        circle( newImg, oldDotL[i], 3 , CV_RGB(0, 255, 0), FILLED, LINE_8, 0 );
    }

    for(int i = 0; i < nPoint; i++){
        circle( newImg, newDotL[i], 3 , CV_RGB(0, 0, 255), FILLED, LINE_8, 0 );
    }

    return newImg;
}
