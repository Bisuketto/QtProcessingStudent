#ifndef MATCROSS_D_HPP
#define MATCROSS_D_HPP

#include "convolutionfilter.hpp"

class MatCross_D: public ConvolutionFilter
{
public:
    MatCross_D();
    MatCross_D(QString _name, std::vector<int> _matrix);
    int convolutionMatrix(std::vector<int> A);
};

#endif // MATCROSS_D_HPP
