#ifndef CANALFILTER_HPP
#define CANALFILTER_HPP

#include "src/Filter/filter.hpp"

class CanalFilter : public Filter
{
public:
    CanalFilter(QString _name, unsigned int _color_values);
    void process(FastImage* _buffIn, FastImage* _buffOut);
private:
    unsigned int color_values;
};

#endif // CANALFILTER_HPP
