#ifndef POW2NORMBLURFILTER_H
#define POW2NORMBLURFILTER_H

#include "convolutionfilter.hpp"

class Pow2NormBlurFilter : public BlurFilter
{
public:
    Pow2NormBlurFilter();
    Pow2NormBlurFilter( QString _name, std::vector<int> _matrix);
    Pow2NormBlurFilter( QString _name, std::vector<int> _matrix, int _norm);
    void process(FastImage* _buffIn, FastImage* _buffOut);
    int get_shift();
private:
    int shift;
protected:
    void set_shift();
};

class BlurB0 : public Pow2NormBlurFilter
{
public:
    BlurB0();
    BlurB0( QString _name);
};

class BlurB1 : public Pow2NormBlurFilter
{
public:
    BlurB1();
    BlurB1( QString _name);
};

class BlurB3 : public Pow2NormBlurFilter
{
public:
    BlurB3();
    BlurB3( QString _name);
};

#endif // POW2NORMBLURFILTER_H
