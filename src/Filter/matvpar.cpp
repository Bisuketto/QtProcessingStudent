#include "matvpar.hpp"


MatVPar::MatVPar() : ConvolutionFilter()
{

}

MatVPar::MatVPar(QString _name, std::vector<int> _matrix) : ConvolutionFilter( _name, _matrix)
{

}

int MatVPar::convolutionMatrix( std::vector<int> A)
{
    int result = 0;
    std::vector<int> _matrix = get_mat();

    if (A[0] != 0)
       result += _matrix[0] * A[0];

    for( int i = 2 ; i < 4 ; i++)
    {
        if (A[i] != 0)
           result += _matrix[i] * A[i];
    }

    for( int i = 5 ; i < 7 ; i++)
    {
        if (A[i] != 0)
           result += _matrix[i] * A[i];
    }

    if (A[8] != 0)
       result += _matrix[8] * A[8];

    return result;
}
