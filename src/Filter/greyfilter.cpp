#include "src/Filter/greyfilter.hpp"

GreyFilter::GreyFilter(QString _name, unsigned int _color_values) : Filter::Filter(_name)
{
    color_values = _color_values; // XXRRGGBB
}

GreyFilter::~GreyFilter(){

}

void GreyFilter::process(FastImage *_buffIn, FastImage *_buffOut){

    if( _buffOut->width() != _buffIn->width() || _buffOut->height() != _buffIn->height() ){
        _buffOut->resize(_buffIn->height(), _buffIn->width());
    }

    int R_coef = ((color_values & 0x00FF0000) >> 16) << 8; // Static point
    int G_coef = ((color_values & 0x0000FF00) >> 8 ) << 8;
    int B_coef = ((color_values & 0x000000FF) >> 0 ) << 8;
    int grey_value = 0;
    for (int x = 0; x < _buffIn->width(); x++){
        for (int y = 0; y < _buffIn->height(); y++){
            grey_value = ((_buffIn->Red(y,x)*R_coef) >> 8) + ((_buffIn->Green(y,x)*G_coef) >> 8) + ((_buffIn->Blue(y,x)*B_coef) >> 8);
            _buffOut->RGB(y,x,grey_value, grey_value, grey_value);
        }
    }
}
