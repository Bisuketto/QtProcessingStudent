#ifndef INVERSEFILTER_HPP
#define INVERSEFILTER_HPP

#include "src/Filter/filter.hpp"

class InverseFilter : public Filter
{
public:
    InverseFilter(QString _name);
    ~InverseFilter();
    void process(FastImage* _buffIn, FastImage* _buffOut);
};

#endif // INVERSEFILTER_HPP
