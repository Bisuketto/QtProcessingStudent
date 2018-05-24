#include "complexfilterex2.hpp"

ComplexFilterEx2::ComplexFilterEx2(QString _name) : ComplexFilter(_name)
{
    DownSampleFilterPick* dspick = new DownSampleFilterPick("DownSample");
    M9* contour = new M9("ContourM9");
    this->addFilter(dspick);
    this->addFilter(contour);
}

ComplexFilterEx2::~ComplexFilterEx2(){

}
