#include "src/Filter/filterr.hpp"

FilterR::FilterR(QString _name) : CanalFilter(_name, 0x000000FF)
{

}

FilterR::FilterR() : CanalFilter( "RedCanal", 0x000000FF){

}
