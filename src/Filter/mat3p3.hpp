#ifndef MAT3P3_HPP
#define MAT3P3_HPP

#include "convolutionfilter.hpp"

class Mat3p3 : public ConvolutionFilter
{
public:
    Mat3p3();
    Mat3p3(QString _name, std::vector<int> _matrix);
private:
    int convolutionMatrix(std::vector<int> A);
};

#endif // MAT3P3_HPP
