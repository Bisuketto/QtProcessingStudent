#ifndef UPSAMPLEFILTER_HPP
#define UPSAMPLEFILTER_HPP

#include "filter.hpp"

class UpSampleFilter : public Filter
{
public:
    UpSampleFilter(QString _name);
    void process(FastImage* _buffIn, FastImage* _buffOut);
};

#endif // UPSAMPLEFILTER_HPP
