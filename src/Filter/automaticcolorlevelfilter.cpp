#include "automaticcolorlevelfilter.hpp"

AutomaticColorLevelFilter::AutomaticColorLevelFilter(QString _name) : Filter(_name)
{

}

AutomaticColorLevelFilter::~AutomaticColorLevelFilter(){

}

void AutomaticColorLevelFilter::process(FastImage* _buffIn, FastImage* _buffOut){
    if( _buffOut->width() != _buffIn->width() || _buffOut->height() != _buffIn->height() ){
        _buffOut->resize(_buffIn->height(), _buffIn->width());
    }

    int MaxR = 0, MaxG = 0, MaxB = 0;
    int minR = 255, minG = 255, minB = 255;

    for(int y = 0; y < _buffIn->height(); y++){
        for(int x = 0; x < _buffIn->width(); x++){
            MaxR = (_buffIn->Red(y, x) > MaxR) ? _buffIn->Red(y, x) : MaxR;
            MaxG = (_buffIn->Green(y, x) > MaxG) ? _buffIn->Green(y, x) : MaxG;
            MaxB = (_buffIn->Blue(y, x) > MaxB) ? _buffIn->Blue(y, x) : MaxB;

            minR = (_buffIn->Red(y, x) < minR) ? _buffIn->Red(y, x) : minR;
            minG = (_buffIn->Green(y, x) < minG) ? _buffIn->Green(y, x) : minG;
            minB = (_buffIn->Blue(y, x) < minB) ? _buffIn->Blue(y, x) : minB;
        }
    }

    float Cr = 255.f/(MaxR - minR);
    float Cg = 255.f/(MaxG - minG);
    float Cb = 255.f/(MaxB - minB);

    for(int y=0; y<_buffIn->height(); y++){
        for(int x=0; x<_buffIn->width(); x++){
                _buffOut->Red  (y, x, (int) (Cr*(_buffIn->Red(y,x)-minR)));
                _buffOut->Green(y, x, (int) (Cg*(_buffIn->Green(y,x)-minG)));
                _buffOut->Blue (y, x, (int) (Cb*(_buffIn->Blue(y,x)-minB)));
        }
    }

}
