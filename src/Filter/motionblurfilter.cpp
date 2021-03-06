#include "motionblurfilter.hpp"

MotionBlurFilter::MotionBlurFilter(QString _name) : Filter(_name)
{
    buffTemp[0] = new FastImage(2, 2);
    buffTemp[1] = new FastImage(2, 2);
}

MotionBlurFilter::~MotionBlurFilter(){
    delete buffTemp[0];
    delete buffTemp[1];
}

void MotionBlurFilter::process(FastImage* _buffIn, FastImage* _buffOut){
    if( _buffOut->width() != _buffIn->width() || _buffOut->height() != _buffIn->height() ){
        _buffOut->resize(_buffIn->height(), _buffIn->width());
    }

    if(buffTemp[0]->width() != _buffIn->width() || buffTemp[0]->height() != _buffIn->height()){
        buffTemp[0]->resize(_buffIn->height(), _buffIn->width());
        buffTemp[1]->resize(_buffIn->height(), _buffIn->width());
        buffTemp[0]->FastCopyTo(_buffIn);
        buffTemp[1]->FastCopyTo(_buffIn);
    }
    else{
        for(int y=0; y<_buffIn->height(); y++){
            for(int x=0; x<_buffIn->width(); x++){
                    _buffOut->Red  (y, x, (_buffIn->Red(y, x) >> 1) + ((77*buffTemp[0]->Red(y, x)) >> 8) + ((51*buffTemp[1]->Red(y, x)) >> 8));
                    _buffOut->Green(y, x, (_buffIn->Green(y, x) >> 1) + ((77*buffTemp[0]->Green(y, x)) >> 8) + ((51*buffTemp[1]->Green(y, x)) >> 8));
                    _buffOut->Blue (y, x, (_buffIn->Blue(y, x) >> 1) + ((77*buffTemp[0]->Blue(y, x)) >> 8) + ((51*buffTemp[1]->Blue(y, x)) >> 8));
            }
        }

        buffTemp[1]->FastCopyTo(buffTemp[0]);
        buffTemp[0]->FastCopyTo(_buffIn);
    }
}
