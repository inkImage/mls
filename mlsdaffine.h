#include "mlsdeformation.h"

class MLSDAffine : public MLSD
{
public:
    MLSDAffine() {}
    ~MLSDAffine(){}
    void calcDelta();

private:
    Point_<double> getMLSDelta(int x, int y);
};
