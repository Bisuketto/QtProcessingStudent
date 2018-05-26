#include "detectionfilter2p1.hpp"

DetectionFilter2p1::DetectionFilter2p1() : DetectionFilter()
{
}

DetectionFilter2p1::DetectionFilter2p1(QString _name, std::vector<int> _matrix) : DetectionFilter( _name, _matrix)
{
}

void DetectionFilter2p1::process(FastImage *_buffIn, FastImage *_buffOut)
{
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
            for(int xx = 0; xx < 2; xx++){
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

DetectionM0::DetectionM0() : DetectionFilter2p1( "DetectionM0", { -1, 1})
{

}

DetectionM0::DetectionM0( QString _name) : DetectionFilter2p1( _name, { -1, 1})
{

}
