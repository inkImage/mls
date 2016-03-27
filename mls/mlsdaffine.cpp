#include "mlsdaffine.h"
#define delta 0.000001

Point2d MLSDAffine::getMLSDelta(int x, int y){      //given a point with x and y, get delta
    Point2d pstar, qstar, dv;
    double sw;

    vector<double> w;
    w.resize(nPoint);

    int k;

    sw = 0;                                 //clear
    pstar.x = pstar.y = 0;
    qstar.x = qstar.y = 0;

    for(k = 0; k < nPoint; k++){                //calc w
        if(x == oldDotL[k].x && y == oldDotL[k].y)
            continue;

        w[k] = 1 / pow(sqrt(pow(x-oldDotL[k].x, 2.0)+pow(y-oldDotL[k].y, 2.0)), 2 * alpha);
        sw += w[k];
        pstar += w[k] * oldDotL[k];
        qstar += w[k] * newDotL[k];
    }
    pstar /= sw;                                        //calc pstar and qstar
    qstar /= sw;

    Mat M = Mat::zeros(2, 2, CV_64FC1);
    Mat P(1, 2, CV_64FC1), Q(1, 2, CV_64FC1);
    Mat A = Mat::zeros(2, 2, CV_64FC1), B = Mat::zeros(2, 2, CV_64FC1);
    for(k = 0; k < nPoint; k++){
        if(x == oldDotL[k].x && y == oldDotL[k].y)
            continue;

        P.at<double>(0) = oldDotL[k].x - pstar.x;
        P.at<double>(1) = oldDotL[k].y - pstar.y;
        Q.at<double>(0) = newDotL[k].x - qstar.x;
        Q.at<double>(1) = newDotL[k].y - qstar.y;

        Mat T = P.t() * P;
        A += w[k] * T;
        T = P.t() * Q;
        B += w[k] * T;
    }

    if(determinant(A) <= delta){
        dv.x = pstar.x - qstar.x;
        dv.y = pstar.y - qstar.y;
        return dv;
    }

    M = A.inv() * B;
    Mat V(1, 2, CV_64FC1);
    V.at<double>(0) = x - pstar.x;
    V.at<double>(1) = y - pstar.y;
    Mat R = V * M;

    dv.x = R.at<double>(0) + qstar.x - x;
    dv.y = R.at<double>(1) + qstar.y - y;
    return dv;
}

void MLSDAffine::calcDelta(){
    rDx = rDx.zeros(tarH, tarW); rDy = rDy.zeros(tarH, tarW);

    for(int i = 0;i < nPoint; i++){
        if(newDotL[i].x < 0)
            newDotL[i].x = 0;
        if(newDotL[i].y < 0)
            newDotL[i].y = 0;
        if(newDotL[i].x >= tarW)
            newDotL[i].x = tarW - 1;
        if(newDotL[i].y >= tarH)
            newDotL[i].y = tarH - 1;
    }

    for(int i = 0; ; i += gridsize){              //i : y
        if(i >= tarH && i < tarH + gridsize - 1)
            i = tarH - 1;
        else if(i >= tarH)
            break;
        for(int j = 0; ; j += gridsize){          //j : x
            if(j >= tarW && j < tarW + gridsize - 1)
                j = tarW - 1;
            else if(j >= tarW)
                break;

            Point_<double> dv = getMLSDelta(j, i);
            rDx.at<double>(i, j) = dv.x;
            rDy.at<double>(i, j) = dv.y;
        }
    }
}
