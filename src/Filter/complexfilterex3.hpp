#ifndef COMPLEXFILTEREX3_HPP
#define COMPLEXFILTEREX3_HPP

#include "complexfilter.hpp"
#include "upsamplefilter.hpp"
#include "simplegreyfilter.hpp"
#include "pow2normblurfilter.hpp"

class ComplexFilterEx3 : public ComplexFilter
{
public:
    ComplexFilterEx3(QString _name);
    ~ComplexFilterEx3();
};

#endif // COMPLEXFILTEREX3_HPP
