#include "mlsdrigid.h"

void MLSDRigid::calcDelta(){
    int i, j, k;
    Point2d pstar, qstar;
    double sw = 0.0, ur = 0.0;
    double *w = new double[nPoint];

    rDx = rDx.zeros(tarH, tarW); rDy = rDy.zeros(tarH, tarW);       //alloc space

    for(i = 0; ; i += gridsize){                            //i : y
        if(i >= tarH && i < tarH + gridsize - 1)
            i = tarH - 1;
        else if(i >= tarH)
            break;
        for(j = 0; ; j += gridsize){                        //j : x
            if(j >= tarW && j < tarW + gridsize - 1)
                j = tarW - 1;
            else if(j >= tarW)
                break;

            pstar.x = pstar.y = 0;
            qstar.x = qstar.y = 0;

            for(k = 0; k < nPoint; k++){
                if((j == oldDotL[k].x) && (i == oldDotL[k].y))
                    continue;

                w[k] = 1 / pow(sqrt(pow(j-oldDotL[k].x, 2.0)+pow(i-oldDotL[k].y, 2.0)), 2 * alpha);
                sw += w[k];
                pstar += w[k] * oldDotL[k];
                qstar += w[k] * newDotL[k];
            }

            pstar /= sw;
            qstar /= sw;

            Mat M = Mat::zeros(2, 2, CV_64FC1);
            Mat P(1, 2, CV_64FC1), Q(1, 2, CV_64FC1);		//pi = p - pstar, qi = q - qstar
            Mat W = Mat::zeros(2, 2, CV_64FC1);
            double upq = 0, uqp = 0;

            for(k = 0; k < nPoint; k++){
                if (j == oldDotL[k].x && i == oldDotL[k].y)
                    continue;
                P.at<double>(0) = oldDotL[k].x - pstar.x;
                P.at<double>(1) = oldDotL[k].y - pstar.y;
                Q.at<double>(0) = newDotL[k].x - qstar.x;
                Q.at<double>(1) = newDotL[k].y- qstar.y;

                Mat DP(2, 2, CV_64FC1);
                DP.at<double>(0, 0) = -P.at<double>(0);
                DP.at<double>(0, 1) = P.at<double>(1);
                DP.at<double>(1, 0) = P.at<double>(1);
                DP.at<double>(1, 1) = P.at<double>(0);
                Mat DQ(2, 2, CV_64FC1);
                DQ.at<double>(0, 0) = -Q.at<double>(0);
                DQ.at<double>(0, 1) = Q.at<double>(1);
                DQ.at<double>(1, 0) = Q.at<double>(1);
                DQ.at<double>(1, 1) = Q.at<double>(0);

                upq += w[k] * Q.dot(P);
                P.at<double>(0) = -(oldDotL[k].y - pstar.y);
                P.at<double>(1) = oldDotL[k].x - pstar.x;
                uqp += w[k] * Q.dot(P);
                W += w[k] * (DP * DQ);
            }

            ur = sqrt(pow(upq, 2.0) + pow(uqp, 2.0));
            M = W / ur;
            ur = 0.0;
            Mat V(1, 2, CV_64FC1);
            V.at<double>(0) = j - pstar.x;
            V.at<double>(1) = i - pstar.y;
            Mat R = V * M;

            rDx.at<double>(i, j) = R.at<double>(0) + qstar.x - j;
            rDy.at<double>(i, j) = R.at<double>(1) + qstar.y - i;
        }
    }
}
