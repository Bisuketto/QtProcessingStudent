#include "pow2normblurfilter.hpp"

int Pow2NormBlurFilter::get_shift()
{
    return shift;
}

void Pow2NormBlurFilter::set_shift()
{
    shift = 0;
    int buff = get_norm();
    while (buff > 1){
        buff >>= 1;
        shift += 1;
    }
}

Pow2NormBlurFilter::Pow2NormBlurFilter() : BlurFilter()
{
    shift = 0;
}

Pow2NormBlurFilter::Pow2NormBlurFilter( QString _name, std::vector<int> _matrix) : BlurFilter( _name, _matrix)
{
    set_shift();
}

Pow2NormBlurFilter::Pow2NormBlurFilter( QString _name, std::vector<int> _matrix, int _norm) : BlurFilter( _name, _matrix, _norm)
{
    set_shift();
}

void Pow2NormBlurFilter::process(FastImage *_buffIn, FastImage *_buffOut)
{
    int w = _buffIn->width(), h = _buffIn->height();
    if( _buffOut->width() != w || _buffOut->height() != h ){
        _buffOut->resize(h, w);
    }

    int sumr = 0, sumb = 0, sumg = 0;

    for(int y = 1; y < h - 1; y++){
        for(int x = 1; x < w - 1; x++){
            sumr = 0;
            sumb = 0;
            sumg = 0;
            for(int xx = 0; xx < 3; xx++){
                for(int yy = 0; yy < 3; yy++){
                    int coef = get_coef( yy, xx);
                    if ( coef == 1 ){
                        sumr += _buffIn->Red(y - yy +1, x - xx +1);
                        sumg += _buffIn->Green(y - yy +1, x - xx +1);
                        sumb += _buffIn->Blue(y - yy +1, x - xx +1);
                    }else if ( coef == -1){
                        sumr -= _buffIn->Red(y - yy +1, x - xx +1);
                        sumg -= _buffIn->Green(y - yy +1, x - xx +1);
                        sumb -= _buffIn->Blue(y - yy +1, x - xx +1);
                    }else if (coef != 0 ){
                        sumr += coef*_buffIn->Red(y - yy +1, x - xx +1);
                        sumg += coef*_buffIn->Green(y - yy +1, x - xx +1);
                        sumb += coef*_buffIn->Blue(y - yy +1, x - xx +1);
                    }
                }
            }

            sumr >>= shift;
            sumb >>= shift;
            sumg >>= shift;

            /*
            sumr = (int)( ((double)sumr)/((double)get_norm()) );
            sumb = (int)( ((double)sumb)/((double)get_norm()) );
            sumg = (int)( ((double)sumg)/((double)get_norm()) );
            */
            _buffOut->Red(y,x,sumr);
            _buffOut->Green(y,x,sumg);
            _buffOut->Blue(y,x,sumb);
        }
    }
}

BlurB0::BlurB0() : Pow2NormBlurFilter( "BlurB0", { 0, 1, 0, 1, 4, 1, 0, 1, 0}, 8)
{
}

BlurB0::BlurB0( QString _name) : Pow2NormBlurFilter( _name, { 0, 1, 0, 1, 4, 1, 0, 1, 0}, 8)
{
}

BlurB1::BlurB1() : Pow2NormBlurFilter( "BlurB1", { 1, 2, 1, 2, 8, 2, 1, 2, 1}, 16)
{
}

BlurB1::BlurB1( QString _name) : Pow2NormBlurFilter( _name, { 1, 2, 1, 2, 8, 2, 1, 2, 1}, 16)
{
}

BlurB3::BlurB3() : Pow2NormBlurFilter( "BlurB3", { 1, 1, 1, 1, 0, 1, 1, 1, 1}, 8)
{
}

BlurB3::BlurB3( QString _name) : Pow2NormBlurFilter( _name, { 1, 1, 1, 1, 0, 1, 1, 1, 1}, 8)
{
}











