#include "convfilter3p3.hpp"

ConvFilter3p3::ConvFilter3p3() : DetectionFilter()
{

}

ConvFilter3p3::ConvFilter3p3(QString _name, std::vector<int> _matrix) : DetectionFilter( _name, _matrix)
{

}

void ConvFilter3p3::process(FastImage *_buffIn, FastImage *_buffOut){
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
                    sumr += get_coef(yy,xx)*_buffIn->Red(y - yy +1, x - xx +1);
                    sumg += get_coef(yy,xx)*_buffIn->Green(y - yy +1, x - xx +1);
                    sumb += get_coef(yy,xx)*_buffIn->Blue(y - yy +1, x - xx +1);
                }
            }
            _buffOut->Red(y,x,sumr);
            _buffOut->Green(y,x,sumg);
            _buffOut->Blue(y,x,sumb);
        }
    }
}

int ConvFilter3p3::convolutionMatrix( std::vector<int> A)
{
    std::vector<int> _matrix(get_mat());
    int result = 0;
    for( int i = 0 ; i < 9 ; i++)
    {
        if (_matrix[i] != 0){
            result += _matrix[8-i] * A[i];
        }
    }

    return result;
}

M2::M2() : ConvFilter3p3( "M2",  { -1, 0, 1, -2, 0, 2, -1, 0, 1})
{
}

M2::M2( QString _name) : ConvFilter3p3( _name,  { -1, 0, 1, -2, 0, 2, -1, 0, 1})
{
}

M3::M3() : ConvFilter3p3( "M2", { -1, 0, 1, -1, 0, 1, -1, 0, 1} )
{
}

M3::M3( QString _name) : ConvFilter3p3( _name,{ -1, 0, 1, -1, 0, 1, -1, 0, 1} )
{
}

M3::M3() : ConvFilter3p3( "M2", { -1, 0, 1, -1, 0, 1, -1, 0, 1} )
{
}

M3::M3( QString _name) : ConvFilter3p3( _name,{ -1, 0, 1, -1, 0, 1, -1, 0, 1} )
{
}

M3::M3() : ConvFilter3p3( "M2", { -1, 0, 1, -1, 0, 1, -1, 0, 1} )
{
}

M3::M3( QString _name) : ConvFilter3p3( _name,{ -1, 0, 1, -1, 0, 1, -1, 0, 1} )
{
}

M6::M6() : ConvFilter3p3( "M6", { -1, 0, 1, -1, 0, 1, -1, 0, 1} )
{
}

M6::M6( QString _name) : ConvFilter3p3( _name,{ -1, 0, 1, -1, 0, 1, -1, 0, 1} )
{
}

M7::M7() : ConvFilter3p3( "M7", { -1, -1, -1, -1, 8, -1, -1, -1, -1} )
{
}

M7::M7( QString _name) : ConvFilter3p3( _name,{ -1, -1, -1, -1, 8, -1, -1, -1, -1} )
{
}

M8::M8() : ConvFilter3p3( "M8", { -1,-2,-1,-2,12,-2,-1,-2,-1} )
{
}

M8::M8( QString _name) : ConvFilter3p3( _name,{ -1,-2,-1,-2,12,-2,-1,-2,-1} )
{
}

M9::M9() : ConvFilter3p3( "M9", { -1, -1, 0, -1, 0, 1, 0, 1, 1} )
{
}

M9::M9( QString _name) : ConvFilter3p3( _name,{ -1, -1, 0, -1, 0, 1, 0, 1, 1} )
{
}
