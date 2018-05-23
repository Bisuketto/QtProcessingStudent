#include "complexfilterex2.hpp"

ComplexFilterEx2::ComplexFilterEx2(QString _name) : ComplexFilter(_name)
{
    DownSampleFilterPick* dspick = new DownSampleFilterPick("DownSample");
    this->addFilter(dspick);
}

ComplexFilterEx2::~ComplexFilterEx2(){

}
