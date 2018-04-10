#include "src/Filter/filter.hpp"

Filter::Filter(QString _name){
    name = _name;
}

Filter::~Filter(){

}

void Filter::process(FastImage* _buffIn, FastImage* _buffOut){

}

QString Filter::getFilterName(){
    return name;
}
