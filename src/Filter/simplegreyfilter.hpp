#ifndef SIMPLEGREYFILTER_H
#define SIMPLEGREYFILTER_H

#include "greyfilter.hpp"

class SimpleGreyFilter : public GreyFilter
{
public:
    SimpleGreyFilter(QString _name);
    ~SimpleGreyFilter();
};

#endif // SIMPLEGREYFILTER_H
