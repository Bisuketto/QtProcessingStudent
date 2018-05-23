#ifndef FILTER_HPP
#define FILTER_HPP

#include <QString>
#include "src/Image/CVideo.h"

class Filter
{
public:
    Filter();
    Filter(QString _name);
    ~Filter();
    virtual void process(FastImage* _buffIn, FastImage* _buffOut);
    QString getFilterName();
    void setFilterName(QString _name);
private:
    QString name;
};

#endif // FILTER_HPP
