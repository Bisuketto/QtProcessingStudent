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

int BlurFilter::get_norm(){
    return *norm;
}

int BlurFilter::calc_norm(){
    int _n = 0;
    for ( int i = 0 ; i < 3 ; i++){
        for( int j = 0 ; i < 3 ; j++){
            _n += get_coef( j, i);
        }
    }
    return _n;
}

void BlurFilter::set_norm(int _n){
    *norm = _n;
}

void BlurFilter::calc_set_norm(){
    int _n = 0;
    _n = calc_norm();
    set_norm( _n);
}

BlurFilter::BlurFilter() : ConvolutionFilter(){
    norm = new int;
}

BlurFilter::BlurFilter(QString _name, std::vector<int> _matrix) : ConvolutionFilter(_name, _matrix){
    norm = new int;
    calc_set_norm();
}

BlurFilter::BlurFilter( QString _name, std::vector<int> _matrix, int _norm) : ConvolutionFilter(_name, _matrix){
    norm = new int;
    set_norm( _norm);
}

BlurFilter::~BlurFilter(){
    delete norm;
}

std::vector<int> ConvolutionFilter::get_mat(){
    return *matrix;
}

void ConvolutionFilter::set_mat(const std::vector<int> _matrix)
{
    matrix->clear();
    *matrix = _matrix;
}

int ConvolutionFilter::get_coef(int y, int x){
    return matrix->at(3*y+x);
}

void ConvolutionFilter::process(FastImage *_buffIn, FastImage *_buffOut)
{

}

