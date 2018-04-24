#include "simplegreyfilter.hpp"

SimpleGreyFilter::SimpleGreyFilter(QString _name) : GreyFilter::GreyFilter( _name, (85 << 16) | (85 << 8) | (85 << 0))
{

}

SimpleGreyFilter::~SimpleGreyFilter()
{
}
