#include "complexfilter.hpp"

ComplexFilter::ComplexFilter(QString _name) : Filter(_name)
{

}

void ComplexFilter::process(FastImage* _buffIn, FastImage* _buffOut){
    for(int i = 0; i < filters.size(); i++){
        filters.at(i)->process(_buffIn, _buffOut);
        tmp1 = _buffOut;
        _buffOut = _buffIn;
        _buffIn = tmp1;
    }
}

void ComplexFilter::addFilter(Filter *_toAdd){
    filters.push_back(_toAdd);
}
