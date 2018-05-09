#include "mathpar.hpp"


MatHPar::MatHPar() : ConvolutionFilter()
{

}

MatHPar::MatHPar(QString _name, std::vector<int> _matrix) : ConvolutionFilter( _name, _matrix)
{

}

int MatHPar::convolutionMatrix( std::vector<int> A)
{
    int result = 0;
    std::vector<int> _matrix = get_mat();


    for( int i = 0 ; i < 3 ; i++)
    {
        if (A[i] != 0)
           result += _matrix[i] * A[i];
    }
    for( int i = 7 ; i < 9 ; i++)
    {
        if (A[i] != 0)
           result += _matrix[i] * A[i];
    }
    return result;
}
