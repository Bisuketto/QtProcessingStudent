#ifndef COMPLEXFILTER_HPP
#define COMPLEXFILTER_HPP

#include "filter.hpp"

class ComplexFilter : public Filter
{
public:
    ComplexFilter(QString _name);
    ComplexFilter(QString _name, Filter **_filters, int _n);
    void addFilter(Filter* _toadd);
    void process(FastImage* _buffIn, FastImage* _buffOut);
private:
    std::vector<Filter* > filters;
    FastImage* tmp1;
    FastImage* tmp2;
};

#endif // COMPLEXFILTER_HPP
