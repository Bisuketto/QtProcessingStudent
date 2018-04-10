#ifndef FILTER_HPP
#define FILTER_HPP

#include <QString>
#include "src/Image/CVideo.h"

class Filter
{
public:
    Filter(QString _name);
    ~Filter();
    virtual void process(FastImage* _buffIn, FastImage* _buffOut);
    QString getFilterName();
private:
    QString name;
};

#endif // FILTER_HPP
