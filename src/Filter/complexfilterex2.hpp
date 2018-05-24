#ifndef COMPLEXFILTEREX2_HPP
#define COMPLEXFILTEREX2_HPP

#include "complexfilter.hpp"
#include "downsamplefilterpick.hpp"
#include "detectionfilter3p3.hpp"

class ComplexFilterEx2 : public ComplexFilter
{
public:
    ComplexFilterEx2(QString _name);
    ~ComplexFilterEx2();
};

#endif // COMPLEXFILTEREX2_HPP
