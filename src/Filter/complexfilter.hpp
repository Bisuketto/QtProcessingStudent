#ifndef COMPLEXFILTER_HPP
#define COMPLEXFILTER_HPP

#include "filter.hpp"
#include <vector>

class ComplexFilter : public Filter
{
public:
    ComplexFilter(QString _name);
    void process(FastImage* _buffIn, FastImage* _buffOut);
    void addFilter(Filter* _toAdd);
private:
    std::vector<Filter* > filters;
    FastImage* tmp1;
    FastImage* tmp2;
};

#endif // COMPLEXFILTER_HPP
