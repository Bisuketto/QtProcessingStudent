#ifndef DETECTIONFILTER2P1_HPP
#define DETECTIONFILTER2P1_HPP

#include "convolutionfilter.hpp"

class DetectionFilter2p1 : public DetectionFilter
{
public:
    DetectionFilter2p1();
    DetectionFilter2p1( QString _name, std::vector<int> _matrix);
    void process(FastImage *_buffIn, FastImage *_buffOut);
};

class DetectionM0 : public DetectionFilter2p1
{
public:
    DetectionM0();
    DetectionM0( QString _name);
};

#endif // DETECTIONFILTER2P1_HPP
