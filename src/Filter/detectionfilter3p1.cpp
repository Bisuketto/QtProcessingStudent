#include "detectionfilter3p1.hpp"

DetectionFilter3p1::DetectionFilter3p1() : DetectionFilter()
{
}

DetectionFilter3p1::DetectionFilter3p1( QString _name, std::vector<int> _matrix) : DetectionFilter( _name, _matrix)
{
}

void DetectionFilter3p1::process(FastImage* _buffIn, FastImage* _buffOut){
    int w = _buffIn->width(), h = _buffIn->height();
    if( _buffOut->width() != w || _buffOut->height() != h ){
        _buffOut->resize(h, w);
    }

    int sumr = 0, sumb = 0, sumg = 0;

    for(int y = 1; y < h - 1; y++){
        for(int x = 1; x < w - 1; x++){
            sumr = 0;
            sumb = 0;
            sumg = 0;
            for(int xx = 0; xx < 3; xx++){
                int yy = 0;
                sumr += get_coef(yy,xx)*_buffIn->Red(y - yy +1, x - xx +1);
                sumg += get_coef(yy,xx)*_buffIn->Green(y - yy +1, x - xx +1);
                sumb += get_coef(yy,xx)*_buffIn->Blue(y - yy +1, x - xx +1);
            }
            _buffOut->Red(y,x,sumr);
            _buffOut->Green(y,x,sumg);
            _buffOut->Blue(y,x,sumb);
        }
    }
}

M1::M1() : DetectionFilter3p1( "M1", { -1, 2, -1})
{
}

M1::M1(QString _name) : DetectionFilter3p1( _name, { -1, 2, -1})
{
}
