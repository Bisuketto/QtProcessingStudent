#ifndef NOFILTER_HPP
#define NOFILTER_HPP

#include "src/Filter/filter.hpp"

class NoFilter : public Filter
{
public:
    NoFilter(QString _name);
    void process(FastImage* _buffIn, FastImage* _buffOut);
};

#endif // NOFILTER_HPP
