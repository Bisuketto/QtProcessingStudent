#include "notpow2normblurfilter.hpp"

NotPow2NormBlurFilter::NotPow2NormBlurFilter() : BlurFilter()
{
}

NotPow2NormBlurFilter::NotPow2NormBlurFilter( QString _name, std::vector<int> _matrix) : BlurFilter( _name, _matrix)
{
}

NotPow2NormBlurFilter::NotPow2NormBlurFilter( QString _name, std::vector<int> _matrix, int _norm) : BlurFilter( _name, _matrix, _norm)
{
}

void NotPow2NormBlurFilter::process(FastImage *_buffIn, FastImage *_buffOut)
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

            sumr = (int)( ((double)sumr)/((double)get_norm()) );
            sumb = (int)( ((double)sumb)/((double)get_norm()) );
            sumg = (int)( ((double)sumg)/((double)get_norm()) );

            _buffOut->Red(y,x,sumr);
            _buffOut->Green(y,x,sumg);
            _buffOut->Blue(y,x,sumb);
        }
    }
}

B2::B2() : NotPow2NormBlurFilter( "B2", { 1, 1, 1, 1, 1, 1, 1, 1, 1}, 9)
{
}

B2::B2( QString _name) : NotPow2NormBlurFilter( _name, { 1, 1, 1, 1, 1, 1, 1, 1, 1}, 9)
{
}

void B2::process(FastImage *_buffIn, FastImage *_buffOut)
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
                    sumr += _buffIn->Red(y - yy +1, x - xx +1);
                    sumg += _buffIn->Green(y - yy +1, x - xx +1);
                    sumb += _buffIn->Blue(y - yy +1, x - xx +1);
                }
            }

            sumr = (int)( ((double)sumr)/((double)get_norm()) );
            sumb = (int)( ((double)sumb)/((double)get_norm()) );
            sumg = (int)( ((double)sumg)/((double)get_norm()) );

            _buffOut->Red(y,x,sumr);
            _buffOut->Green(y,x,sumg);
            _buffOut->Blue(y,x,sumb);
        }
    }
}
