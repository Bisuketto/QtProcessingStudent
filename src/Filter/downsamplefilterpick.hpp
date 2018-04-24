#ifndef DOWNSAMPLEFILTERPICK_HPP
#define DOWNSAMPLEFILTERPICK_HPP

#include "filter.hpp"

class DownSampleFilterPick : public Filter
{
public:
    DownSampleFilterPick(QString _name);
    void process(FastImage* _buffIn, FastImage* _buffOut);
};

#endif // DOWNSAMPLEFILTERPICK_HPP
