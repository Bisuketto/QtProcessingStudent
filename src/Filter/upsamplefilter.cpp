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
    int red, green, blue;
    for(int y=0; y<_buffIn->height(); y++){
        for(int x=0; x<_buffIn->width(); x++){
            red = _buffIn->Red(y,x);
            green = _buffIn->Green(y,x);
            blue = _buffIn->Blue(y,x);
            _buffOut->Red  (2*y, 2*x, red);
            _buffOut->Red  (2*y+1, 2*x, red);
            _buffOut->Red  (2*y, 2*x+1, red);
            _buffOut->Red  (2*y+1, 2*x+1, red);
            _buffOut->Green(2*y, 2*x, green);
            _buffOut->Green(2*y+1, 2*x, green);
            _buffOut->Green(2*y, 2*x+1, green);
            _buffOut->Green(2*y+1, 2*x+1, green);
            _buffOut->Blue (2*y, 2*x, blue);
            _buffOut->Blue (2*y+1, 2*x, blue);
            _buffOut->Blue (2*y, 2*x+1, blue);
            _buffOut->Blue (2*y+1, 2*x+1, blue);
        }
    }
}
