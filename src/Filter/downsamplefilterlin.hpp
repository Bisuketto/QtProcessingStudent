#ifndef DOWNSAMPLEFILTERLIN_HPP
#define DOWNSAMPLEFILTERLIN_HPP

#include "filter.hpp"


class DownSampleFilterLin : public Filter
{
public:
    DownSampleFilterLin(QString _name);
    void process(FastImage* _buffIn, FastImage* _buffOut);
};

#endif // DOWNSAMPLEFILTERLIN_HPP
