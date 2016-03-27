#ifndef MLSD_H
#define MLSD_H

#include "opencv2/opencv.hpp"
#include <iostream>
#include <cmath>
#include <vector>

using namespace  cv;
using namespace  std;

class MLSD{
public:
    MLSD();
    virtual ~MLSD();

    Mat Initialize(const Mat &oriImg, const vector<Point2d> &qsrc, const vector<Point2d> &qdst,
                   const int outW, const int outH, const int grid_size = 5, const double al_pha = 1.0);

    Mat genNewImg(const Mat &oriImg);

    virtual void calcDelta() = 0;           //need to implement by this son class

    void setSrcPoints(const vector<Point2d> &qsrc);
    void setDstPoints(const vector<Point2d> &qdst);
    void setSize(int w, int h){
        srcW = w;srcH = h;
    }
    void setOutSize(int w, int h){
        tarW = w; tarH = h;
    }

protected:
    double alpha;
    int gridsize;

    vector<Point2d> oldDotL, newDotL;             //old : srcPoint  new : dstPoint

    int nPoint;

    Mat_<double> rDx, rDy;          //deltax and deltay

    int srcW, srcH;
    int tarW, tarH;

};

#endif
