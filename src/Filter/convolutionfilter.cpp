#include "src/Filter/convolutionfilter.hpp"

ConvolutionFilter::ConvolutionFilter()
{

}

ConvolutionFilter::ConvolutionFilter( QString _name, std::vector<int> _matrix) : Filter( _name)
{
    set_mat( _matrix);
}

ConvolutionFilter::~ConvolutionFilter()
{

}

void ConvolutionFilter::set_mat(std::vector<int> _matrix)
{
    matrix = _matrix;
}

void ConvolutionFilter::process(FastImage *_buffIn, FastImage *_buffOut)
{
    if( _buffOut->width() != _buffIn->width() || _buffOut->height() != _buffIn->height() ){
        _buffOut->resize(_buffIn->height(), _buffIn->width());
    }

    for(int y=0; y<_buffOut->height(); y++){
        for(int x=0; x<_buffOut->width(); x++){
            _buffOut->Red  (y, x, (_buffIn->Red(  2*y,2*x) + _buffIn->Red(  2*y+1,2*x) + _buffIn->Red(  2*y,2*x+1) + _buffIn->Red(  2*y+1,2*x+1))/4);
            _buffOut->Green(y, x, (_buffIn->Green(2*y,2*x) + _buffIn->Green(2*y+1,2*x) + _buffIn->Green(2*y,2*x+1) + _buffIn->Green(2*y+1,2*x+1))/4);
            _buffOut->Blue (y, x, (_buffIn->Blue( 2*y,2*x) + _buffIn->Blue( 2*y+1,2*x) + _buffIn->Blue( 2*y,2*x+1) + _buffIn->Blue( 2*y+1,2*x+1))/4);
        }
    }
}

std::vector<int> ConvolutionFilter::convolutionMatrix( std::vector<int> A, std::vector<int> B)
{

}
