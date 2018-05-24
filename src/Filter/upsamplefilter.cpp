#include "upsamplefilter.hpp"

UpSampleFilter::UpSampleFilter(QString _name) : Filter(_name)
{

}

UpSampleFilter::~UpSampleFilter(){

}

void UpSampleFilter::process(FastImage* _buffIn, FastImage* _buffOut){
    if( _buffOut->width() != _buffIn->width()*2 || _buffOut->height() != _buffIn->height()*2 ){
        _buffOut->resize(_buffIn->height()*2, _buffIn->width()*2);
    }

    for(int y=0; y<_buffIn->height(); y++){
        for(int x=0; x<_buffIn->width(); x++){
            _buffOut->Red  (2*y, 2*x, _buffIn->Red(y,x));
            _buffOut->Red  (2*y+1, 2*x, _buffIn->Red(y,x));
            _buffOut->Red  (2*y, 2*x+1, _buffIn->Red(y,x));
            _buffOut->Red  (2*y+1, 2*x+1, _buffIn->Red(y,x));
            _buffOut->Green(2*y, 2*x, _buffIn->Green(y,x));
            _buffOut->Green(2*y+1, 2*x, _buffIn->Green(y,x));
            _buffOut->Green(2*y, 2*x+1, _buffIn->Green(y,x));
            _buffOut->Green(2*y+1, 2*x+1, _buffIn->Green(y,x));
            _buffOut->Blue (2*y, 2*x, _buffIn->Blue(y,x));
            _buffOut->Blue (2*y+1, 2*x, _buffIn->Blue(y,x));
            _buffOut->Blue (2*y, 2*x+1, _buffIn->Blue(y,x));
            _buffOut->Blue (2*y+1, 2*x+1, _buffIn->Blue(y,x));
        }
    }
}
