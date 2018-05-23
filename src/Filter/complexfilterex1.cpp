#include "complexfilterex1.hpp"

ComplexFilterEx1::ComplexFilterEx1(QString _name) : ComplexFilter(_name)
{
    DownSampleFilterSqr* dssqr = new DownSampleFilterSqr("DownSample");
    this->addFilter(dssqr);
    this->addFilter(dssqr);
}

ComplexFilterEx1::~ComplexFilterEx1()
{

}
