#include "complexfilterex3.hpp"

ComplexFilterEx3::ComplexFilterEx3(QString _name) : ComplexFilter(_name)
{
    UpSampleFilter* upsf = new UpSampleFilter("UpSample");
    this->addFilter(upsf);
}
