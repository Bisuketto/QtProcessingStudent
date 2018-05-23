#ifndef DOWNSAMPLEFILTERSQR_HPP
#define DOWNSAMPLEFILTERSQR_HPP

#include "filter.hpp"

class DownSampleFilterSqr : public Filter
{
public:
    DownSampleFilterSqr(QString _name);
    ~DownSampleFilterSqr();
    void process(FastImage* _buffIn, FastImage* _buffOut);
};

#endif // DOWNSAMPLEFILTERSQR_HPP
