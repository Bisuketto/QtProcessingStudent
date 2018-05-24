#ifndef DETECTIONFILTER3P1_HPP
#define DETECTIONFILTER3P1_HPP

#include "convolutionfilter.hpp"

class DetectionFilter3p1 : public DetectionFilter
{
public:
    DetectionFilter3p1();
    DetectionFilter3p1( QString _name, std::vector<int> _matrix);
    void process(FastImage* _buffIn, FastImage* _buffOut);
};

class M1 : public DetectionFilter3p1
{
public:
    M1();
    M1( QString _name);
};

#endif // DETECTIONFILTER3P1_HPP
