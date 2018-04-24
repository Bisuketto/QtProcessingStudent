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
                _buffOut->Red  (y, x, (int) (_buffIn->Red(y,x)*(((color_values & 0x000000FF) >> 0)/(255.f))));
                _buffOut->Green(y, x, (int) (_buffIn->Green(y,x)*(((color_values & 0x0000FF00) >> 8)/(255.f))));
                _buffOut->Blue (y, x, (int) (_buffIn->Blue(y,x)*(((color_values & 0x00FF0000) >> 16)/(255.f))));
        }
    }
}
