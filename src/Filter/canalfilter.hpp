#ifndef CANALFILTER_HPP
#define CANALFILTER_HPP

#include "src/Filter/filter.hpp"
#include <QDebug>

class CanalFilter : public Filter
{
public:
    CanalFilter(QString _name, unsigned int _color_values);
    ~CanalFilter();
    void process(FastImage* _buffIn, FastImage* _buffOut);
private:
    unsigned int color_values;
};

#endif // CANALFILTER_HPP
