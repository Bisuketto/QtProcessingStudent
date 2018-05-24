#ifndef NOTPOW2NORMBLURFILTER_H
#define NOTPOW2NORMBLURFILTER_H

#include "convolutionfilter.hpp"

class NotPow2NormBlurFilter : public BlurFilter
{
public:
    NotPow2NormBlurFilter();
    NotPow2NormBlurFilter( QString _name, std::vector<int> _matrix);
    NotPow2NormBlurFilter( QString _name, std::vector<int> _matrix, int _norm);
    void process(FastImage* _buffIn, FastImage* _buffOut);
};

class B2 : public NotPow2NormBlurFilter
{
public:
    B2();
    B2( QString _name);
};

#endif // NOTPOW2NORMBLURFILTER_H
