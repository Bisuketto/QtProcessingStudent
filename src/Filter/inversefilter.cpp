#include "src/Filter/inversefilter.hpp"

InverseFilter::InverseFilter(QString _name) : Filter(_name)
{

}

void InverseFilter::process(FastImage* _buffIn, FastImage* _buffOut){
    if( _buffOut->width() != _buffIn->width() || _buffOut->height() != _buffIn->height() ){
        _buffOut->resize(_buffIn->height(), _buffIn->width());
    }

    for(int y=0; y<_buffIn->height(); y++){
        for(int x=0; x<_buffIn->width(); x++){
                _buffOut->Red  (y, x, 255 - _buffIn->Red(y,x) );
                _buffOut->Green(y, x, 255 - _buffIn->Green(y,x) );
                _buffOut->Blue (y, x, 255 - _buffIn->Blue(y,x) );
        }
    }
}
