#ifndef LIABLEGREYFILTER_H
#define LIABLEGREYFILTER_H

#include "greyfilter.hpp"

class LiableGreyFilter : public GreyFilter
{
public:
    LiableGreyFilter(QString _name);
    ~LiableGreyFilter();
};

#endif // LIABLEGREYFILTER_H
