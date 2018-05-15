#include "mat3p3_D.hpp"

Mat3p3_D::Mat3p3_D() : ConvolutionFilter()
{

}

Mat3p3_D::Mat3p3_D(QString _name, std::vector<int> _matrix) : ConvolutionFilter( _name, _matrix)
{

}

int Mat3p3_D::convolutionMatrix( std::vector<int> A)
{
    std::vector<int> _matrix(get_mat());
    int result = 0;
    for( int i = 0 ; i < 9 ; i++)
    {
        if (A[i] != 0){
            result += _matrix[i] * A[i];
        }
    }

    return result;
}
