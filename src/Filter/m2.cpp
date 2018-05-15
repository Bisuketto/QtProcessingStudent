#include "m2.hpp"

std::vector<int> m2({ -1, 0, 1, -2, 0, 2, -1, 0, 1});

M2::M2() : MatVPar( "M2", m2 )
{
}

M2::M2( QString _name) : MatVPar( _name, m2 )
{
}
