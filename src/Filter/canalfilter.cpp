#include "src/Filter/canalfilter.hpp"

CanalFilter::CanalFilter(QString _name, unsigned int _color_values) : Filter(_name)
{
    color_values = _color_values;
}

void CanalFilter::process(FastImage* _buffIn, FastImage* _buffOut){
    if( _buffOut->width() != _buffIn->width() || _buffOut->height() != _buffIn->height() ){
        _buffOut->resize(_buffIn->height(), _buffIn->width());
    }

    for(int y=0; y<_buffIn->height(); y++){
        for(int x=0; x<_buffIn->width(); x++){
                _buffOut->Red  (y, x, _buffIn->Red(y,x) );
                _buffOut->Green(y, x, _buffIn->Green(y,x) );
                _buffOut->Blue (y, x, _buffIn->Blue(y,x) );
        }
    }
}
