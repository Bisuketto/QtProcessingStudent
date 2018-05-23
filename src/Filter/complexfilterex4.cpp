#include "complexfilterex4.hpp"

ComplexFilterEx4::ComplexFilterEx4(QString _name) : ComplexFilter(_name)
{
    LiableGreyFilter* lgf = new LiableGreyFilter("Grey");
    this->addFilter(lgf);
}

ComplexFilterEx4::~ComplexFilterEx4(){

}
