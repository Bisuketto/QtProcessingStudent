#ifndef MATHPAR_HPP
#define MATHPAR_HPP

#include "convolutionfilter.hpp"

class MatHPar : public ConvolutionFilter
{
public:
    MatHPar();
    MatHPar(QString _name, std::vector<int> _matrix);
    int convolutionMatrix(std::vector<int> A);
};

#endif // MATHPAR_HPP
