#include "src/Filter/detectionfilter3p3.hpp"

DetectionFilter3p3::DetectionFilter3p3() : DetectionFilter()
{

}

DetectionFilter3p3::DetectionFilter3p3(QString _name, std::vector<int> _matrix) : DetectionFilter( _name, _matrix)
{

}

void DetectionFilter3p3::process(FastImage *_buffIn, FastImage *_buffOut){
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
            _buffOut->Red(y,x,sumr);
            _buffOut->Green(y,x,sumg);
            _buffOut->Blue(y,x,sumb);
        }
    }
}

M2::M2() : DetectionFilter3p3( "M2",  { -1, 0, 1, -2, 0, 2, -1, 0, 1})
{
}

M2::M2( QString _name) : DetectionFilter3p3( _name,  { -1, 0, 1, -2, 0, 2, -1, 0, 1})
{
}

M3::M3() : DetectionFilter3p3( "M3", { -1, 0, 1, -1, 0, 1, -1, 0, 1} )
{
}

M3::M3( QString _name) : DetectionFilter3p3( _name,{ -1, 0, 1, -1, 0, 1, -1, 0, 1} )
{
}

M4::M4() : DetectionFilter3p3( "M4", { -1, -2, -1, 0, 0, 0, 1, 2, 1} )
{
}

M4::M4( QString _name) : DetectionFilter3p3( _name,{ -1, -2, -1, 0, 0, 0, 1, 2, 1} )
{
}

M5::M5() : DetectionFilter3p3( "M5", { -1, -1, -1, 0, 0, 0, 1, 1, 1} )
{
}

M5::M5( QString _name) : DetectionFilter3p3( _name,{ -1, -1, -1, 0, 0, 0, 1, 1, 1} )
{
}

M6::M6() : DetectionFilter3p3( "M6", { 0, -1, 0, -1, 4, -1, 0, -1, 0} )
{
}

M6::M6( QString _name) : DetectionFilter3p3( _name,{ 0, -1, 0, -1, 4, -1, 0, -1, 0} )
{
}

M7::M7() : DetectionFilter3p3( "M7", { -1, -1, -1, -1, 8, -1, -1, -1, -1} )
{
}

M7::M7( QString _name) : DetectionFilter3p3( _name,{ -1, -1, -1, -1, 8, -1, -1, -1, -1} )
{
}

M8::M8() : DetectionFilter3p3( "M8", { -1,-2,-1,-2,12,-2,-1,-2,-1} )
{
}

M8::M8( QString _name) : DetectionFilter3p3( _name,{ -1,-2,-1,-2,12,-2,-1,-2,-1} )
{
}

M9::M9() : DetectionFilter3p3( "M9", { -1, -1, 0, -1, 0, 1, 0, 1, 1} )
{
}

M9::M9( QString _name) : DetectionFilter3p3( _name,{ -1, -1, 0, -1, 0, 1, 0, 1, 1} )
{
}
