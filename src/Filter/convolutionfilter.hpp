#ifndef CONVOLUTIONFILTER_HPP
#define CONVOLUTIONFILTER_HPP

#include "filter.hpp"

class ConvolutionFilter : public Filter
{
public:
    ConvolutionFilter();
    ConvolutionFilter( QString _name, std::vector<int> _matrix);
    ~ConvolutionFilter();
    virtual std::vector<int> convolutionMatrix( std::vector<int> A, std::vector<int> B);
    void process(FastImage* _buffIn, FastImage* _buffOut);
private:
    std::vector<int> matrix;
    void set_mat( std::vector<int> _matrix);

};
#endif // CONVOLUTIONFILTER_HPP
