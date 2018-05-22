#include "src/Filter/convolutionfilter.hpp"

ConvolutionFilter::ConvolutionFilter() : Filter()
{
    matrix = new vector<int>();
    matrix->clear();
}

ConvolutionFilter::ConvolutionFilter( QString _name, std::vector<int> _matrix) : Filter( _name)
{
    matrix = new vector<int>();
    matrix->clear();
    set_mat( _matrix);
}

ConvolutionFilter::~ConvolutionFilter()
{
    delete matrix;
}

DetectionFilter::DetectionFilter() : ConvolutionFilter(){}

DetectionFilter::DetectionFilter(QString _name, std::vector<int> _matrix) : ConvolutionFilter(_name, _matrix){}

DetectionFilter::~DetectionFilter() {}

BlurFilter::BlurFilter() : ConvolutionFilter(){}

BlurFilter::BlurFilter(QString _name, std::vector<int> _matrix) : ConvolutionFilter(_name, _matrix){}

BlurFilter::~BlurFilter(){}

std::vector<int> ConvolutionFilter::get_mat(){
    return *matrix;
}

void ConvolutionFilter::set_mat(const std::vector<int> _matrix)
{
    if (_matrix.size() != 9){
        exit(EXIT_FAILURE);
    }

    std::vector<int> buff(_matrix);
    if (buff.size() != 9){
        exit(EXIT_FAILURE);
    }
    matrix->clear();
    while( matrix->size() < 9 )
    {
        matrix->push_back(buff.back());
        buff.pop_back();
    }

}

void ConvolutionFilter::process(FastImage *_buffIn, FastImage *_buffOut)
{

}


int ConvolutionFilter::convolutionMatrix( std::vector<int> A)
{

    return 0;
}
