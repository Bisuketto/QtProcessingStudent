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

class B0 : public Pow2NormBlurFilter
{
public:
    B0();
    B0( QString _name);
};

class B1 : public Pow2NormBlurFilter
{
public:
    B1();
    B1( QString _name);
};

class B3 : public Pow2NormBlurFilter
{
public:
    B3();
    B3( QString _name);
};

#endif // POW2NORMBLURFILTER_H
