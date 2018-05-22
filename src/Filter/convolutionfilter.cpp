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
        std::cout << "set_mat error" << std::endl;
        exit(EXIT_FAILURE);
    }

    matrix->clear();
    *matrix = _matrix;
}

int ConvolutionFilter::get_coef(int y, int x){
    return matrix->at(3*y+x);
}

void ConvolutionFilter::process(FastImage *_buffIn, FastImage *_buffOut)
{

}


int ConvolutionFilter::convolutionMatrix( std::vector<int> A)
{

    return 0;
}
