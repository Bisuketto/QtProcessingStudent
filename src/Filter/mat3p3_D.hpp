#ifndef MAT3P3_D_HPP
#define MAT3P3_D_HPP

#include "convolutionfilter.hpp"

class Mat3p3_D : public ConvolutionFilter
{
public:
    Mat3p3_D();
    Mat3p3_D(QString _name, std::vector<int> _matrix);
private:
    int convolutionMatrix(std::vector<int> A);
};

#endif // MAT3P3_D_HPP
