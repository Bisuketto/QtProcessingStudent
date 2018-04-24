#include "downsamplefiltersqr.hpp"

DownSampleFilterSqr::DownSampleFilterSqr(QString _name) : Filter(_name)
{

}

void DownSampleFilterSqr::process(FastImage* _buffIn, FastImage* _buffOut){
    if( _buffOut->width() != _buffIn->width()/2 || _buffOut->height() != _buffIn->height()/2 ){
        _buffOut->resize(_buffIn->height()/2, _buffIn->width()/2);
    }

    for(int y=0; y<_buffOut->height(); y++){
        for(int x=0; x<_buffOut->width(); x++){
            _buffOut->Red  (y, x, (int) sqrt((pow(_buffIn->Red(  2*y,2*x), 2) + pow(_buffIn->Red(  2*y+1,2*x), 2) + pow(_buffIn->Red(  2*y,2*x+1), 2) + pow(_buffIn->Red(  2*y+1,2*x+1), 2))/4));
            _buffOut->Green(y, x, (int) sqrt((pow(_buffIn->Green(2*y,2*x), 2) + pow(_buffIn->Green(2*y+1,2*x), 2) + pow(_buffIn->Green(2*y,2*x+1), 2) + pow(_buffIn->Green(2*y+1,2*x+1), 2))/4));
            _buffOut->Blue (y, x, (int) sqrt((pow(_buffIn->Blue( 2*y,2*x), 2) + pow(_buffIn->Blue( 2*y+1,2*x), 2) + pow(_buffIn->Blue( 2*y,2*x+1), 2) + pow(_buffIn->Blue( 2*y+1,2*x+1), 2))/4));
        }
    }

}
