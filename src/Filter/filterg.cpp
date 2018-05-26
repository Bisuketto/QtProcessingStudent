#include "src/Filter/filterg.hpp"

FilterG::FilterG(QString _name) : CanalFilter(_name, 0x0000FF00)
{

}

FilterG::FilterG() : CanalFilter( "GreenCanal", 0x0000FF00){

}
