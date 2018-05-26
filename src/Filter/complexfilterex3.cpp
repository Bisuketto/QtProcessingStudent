#include "complexfilterex3.hpp"

ComplexFilterEx3::ComplexFilterEx3(QString _name) : ComplexFilter(_name)
{
    SimpleGreyFilter* sgf = new SimpleGreyFilter("Grey");
    this->addFilter(sgf);
    BlurB3* blur = new BlurB3("Blur");
    this->addFilter(blur);
    UpSampleFilter* upsf = new UpSampleFilter("UpSample");
    this->addFilter(upsf);
}
