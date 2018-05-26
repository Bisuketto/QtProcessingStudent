#include "complexfilterex2.hpp"

ComplexFilterEx2::ComplexFilterEx2(QString _name) : ComplexFilter(_name)
{
    DownSampleFilterPick* dspick = new DownSampleFilterPick("DownSample");
    DetectionM9* contour = new DetectionM9("DetectionM9");
    this->addFilter(dspick);
    this->addFilter(contour);
}

ComplexFilterEx2::~ComplexFilterEx2(){

}
