#ifndef MOTIONBLURFILTER_HPP
#define MOTIONBLURFILTER_HPP

#include "filter.hpp"

class MotionBlurFilter : public Filter
{
public:
    MotionBlurFilter(QString _name);
    ~MotionBlurFilter();
    void process(FastImage* _buffIn, FastImage* _buffOut);
    FastImage* buffTemp[2];
};

#endif // MOTIONBLURFILTER_HPP
