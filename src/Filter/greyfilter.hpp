#ifndef GREYFILTER_H
#define GREYFILTER_H

#include "filter.hpp"


class GreyFilter : public Filter
{
public:
    GreyFilter(QString _name, unsigned int _color_values);
    ~GreyFilter();
    void process(FastImage *_buffIn, FastImage *_buffOut);

private:
    unsigned int color_values;
};

#endif // GREYFILTER_H
