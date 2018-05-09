#include "matcross.hpp"

MatCross::MatCross() : ConvolutionFilter()
{

}

MatCross::MatCross(QString _name, std::vector<int> _matrix) : ConvolutionFilter( _name, _matrix)
{

}

int MatCross::convolutionMatrix( std::vector<int> A)
{
    int result = 0;
    std::vector<int> _matrix = get_mat();
    if (A[1] != 0)
       result += _matrix[1] * A[1];

    for( int i = 3 ; i < 6 ; i++)
    {
        if (A[i] != 0)
           result += _matrix[i] * A[i];
    }

    if (A[7] != 0)
       result += _matrix[7] * A[7];

    return result;
}
