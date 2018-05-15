#ifndef FILTERMANAGER_HPP
#define FILTERMANAGER_HPP

#include "src/Filter/filter.hpp"

#include <vector>

class FilterManager
{
public:
    FilterManager();
    Filter* getFilterAt(int i);
    void addFilter(Filter* _ftoadd);
    int amount();
private:
    std::vector<Filter* > filters;
};

#endif // FILTERMANAGER_HPP
