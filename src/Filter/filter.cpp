#include "src/Filter/filter.hpp"

Filter::Filter(QString _name){
    name = _name;
}

Filter::Filter(){

}

Filter::~Filter(){

}

void Filter::setFilterName(QString _name)
{
    name = _name;
}

void Filter::process(FastImage* _buffIn, FastImage* _buffOut){

}

QString Filter::getFilterName(){
    return name;
}
