#include "downsamplefilterpick.hpp"

DownSampleFilterPick::DownSampleFilterPick(QString _name) : Filter(_name)
{

}

DownSampleFilterPick::~DownSampleFilterPick(){

}

void DownSampleFilterPick::process(FastImage* _buffIn, FastImage* _buffOut){
    if( _buffOut->width() != _buffIn->width()/2 || _buffOut->height() != _buffIn->height()/2 ){
        _buffOut->resize(_buffIn->height()/2, _buffIn->width()/2);
    }

    for(int y=0; y<_buffOut->height(); y++){
        for(int x=0; x<_buffOut->width(); x++){
            _buffOut->Red  (y, x, _buffIn->Red(2*y,2*x));
            _buffOut->Green(y, x, _buffIn->Green(2*y,2*x));
            _buffOut->Blue (y, x, _buffIn->Blue(2*y,2*x));
        }
    }

}
