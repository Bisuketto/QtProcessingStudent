#ifndef CONVFILTER3P3_HPP
#define CONVFILTER3P3_HPP

#include "convolutionfilter.hpp"

class ConvFilter3p3 : public DetectionFilter
{
public:
    ConvFilter3p3();
    ConvFilter3p3(QString _name, std::vector<int> _matrix);
    void process(FastImage *_buffIn, FastImage *_buffOut);
private:
    int convolutionMatrix(std::vector<int> A);
};

#endif // CONVFILTER3P3_HPP
