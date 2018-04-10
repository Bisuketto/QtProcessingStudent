#include "src/Filter/filtermanager.hpp"

FilterManager::FilterManager()
{

}

Filter* FilterManager::getFilterAt(int i){
    return filters.at(i);
}

void FilterManager::addFilter(Filter *_ftoadd){
    filters.push_back(_ftoadd);
}
