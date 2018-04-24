#ifndef AUTOMATICCOLORLEVELFILTER_HPP
#define AUTOMATICCOLORLEVELFILTER_HPP

#include "filter.hpp"

class AutomaticColorLevelFilter : public Filter
{
public:
    AutomaticColorLevelFilter(QString _name);
    void process(FastImage* _buffIn, FastImage* _buffOut);
};

#endif // AUTOMATICCOLORLEVELFILTER_HPP
