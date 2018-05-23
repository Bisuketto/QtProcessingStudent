#include "complexfilter.hpp"

ComplexFilter::ComplexFilter(QString _name) : Filter(_name)
{
}

ComplexFilter::ComplexFilter(QString _name, Filter **_filters, int _n) : Filter(_name)
{
    for(int i = 0; i < _n; i++){
        addFilter(_filters[i]);
    }
}

ComplexFilter::~ComplexFilter(){
    for(int i = 0; i < filters.size(); i++){
        delete filters.at(i);
    }
}

void ComplexFilter::process(FastImage* _buffIn, FastImage* _buffOut){
    FastImage* out = _buffOut;

    for(int i = 0; i < filters.size(); i++){
        filters.at(i)->process(_buffIn, _buffOut);
        tmp1 = _buffOut;
        _buffOut = _buffIn;
        _buffIn = tmp1;
    }

    if( out->width() != tmp1->width() || out->height() != tmp1->height() ){
        out->resize(tmp1->height(), tmp1->width());
    }

    out->FastCopyTo(tmp1);
}

void ComplexFilter::addFilter(Filter *_toAdd){
    filters.push_back(_toAdd);
}
