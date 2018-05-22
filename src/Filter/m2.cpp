#include "m2.hpp"

//std::vector<int> m2();

M2::M2() : ConvFilter3p3( "M2", { -1, 0, 1, -2, 0, 2, -1, 0, 1} )
{
}

M2::M2( QString _name) : ConvFilter3p3( _name,{ -1, 0, 1, -2, 0, 2, -1, 0, 1} )
{
}
