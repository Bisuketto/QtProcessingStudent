#include "liablegreyfilter.hpp"

LiableGreyFilter::LiableGreyFilter(QString _name) : GreyFilter(_name, (77 << 16) | (150 << 8) | (29 << 0))
{
}

LiableGreyFilter::LiableGreyFilter() : GreyFilter( "LiableGrey", (77 << 16) | (150 << 8) | (29 << 0))
{
}
