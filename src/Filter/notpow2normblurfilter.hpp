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

class BlurB2 : public NotPow2NormBlurFilter
{
public:
    BlurB2();
    BlurB2( QString _name);
    void process(FastImage *_buffIn, FastImage *_buffOut);
};

#endif // NOTPOW2NORMBLURFILTER_H
