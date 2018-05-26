#include "complexfilterex4.hpp"

ComplexFilterEx4::ComplexFilterEx4(QString _name) : ComplexFilter(_name)
{
    BlurB3* blur = new BlurB3("Blur");
    this->addFilter(blur);
    LiableGreyFilter* lgf = new LiableGreyFilter("Grey");
    this->addFilter(lgf);
    DetectionM9* contour = new DetectionM9("DetectM9");
    this->addFilter(contour);
}

ComplexFilterEx4::~ComplexFilterEx4(){

}
