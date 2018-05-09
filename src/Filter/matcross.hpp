#ifndef MATCROSS_HPP
#define MATCROSS_HPP

#include "convolutionfilter.hpp"

class MatCross : public ConvolutionFilter
{
public:
    MatCross();
    MatCross(QString _name, std::vector<int> _matrix);
    int convolutionMatrix(std::vector<int> A);
};

#endif // MATCROSS_HPP
