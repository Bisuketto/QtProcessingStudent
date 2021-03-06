#ifndef COMPLEXFILTEREX4_HPP
#define COMPLEXFILTEREX4_HPP

#include "complexfilter.hpp"
#include "liablegreyfilter.hpp"
#include "detectionfilter3p3.hpp"
#include "pow2normblurfilter.hpp"

class ComplexFilterEx4 : public ComplexFilter
{
public:
    ComplexFilterEx4(QString _name);
    ~ComplexFilterEx4();
};

#endif // COMPLEXFILTEREX4_HPP
