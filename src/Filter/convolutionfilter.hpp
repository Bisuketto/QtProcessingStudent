#ifndef CONVOLUTIONFILTER_HPP
#define CONVOLUTIONFILTER_HPP

#include "filter.hpp"

class ConvolutionFilter : public Filter
{
public:
    ConvolutionFilter();
    ConvolutionFilter( QString _name, std::vector<int> _matrix);
    ~ConvolutionFilter();
    virtual int convolutionMatrix( std::vector<int> A);
    virtual void process(FastImage* _buffIn, FastImage* _buffOut);
private:
    std::vector<int> matrix; // /!\ matrix est de dimension (9,1) m(1,1) = matrix(1), m(3,3) = matrix(9). De plus, matrix est la version retourné de la vrai matrice.
protected:
    void set_mat( std::vector<int> _matrix);
    std::vector<int> get_mat();
    virtual int convolutionMatrix( std::vector<int> A);s
};
#endif // CONVOLUTIONFILTER_HPP
