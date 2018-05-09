#ifndef MATVPAR_HPP
#define MATVPAR_HPP

#include "convolutionfilter.hpp"

class MatVPar : public ConvolutionFilter
{
public:
    MatVPar();
    MatVPar(QString _name, std::vector<int> _matrix);
    int convolutionMatrix(std::vector<int> A);
};

#endif // MATVPAR_HPP
