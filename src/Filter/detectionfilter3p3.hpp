#ifndef DETECTIONFILTER3P3_HPP
#define DETECTIONFILTER3P3_HPP

#include "convolutionfilter.hpp"

class DetectionFilter3p3 : public DetectionFilter
{
public:
    DetectionFilter3p3();
    DetectionFilter3p3(QString _name, std::vector<int> _matrix);
    void process(FastImage *_buffIn, FastImage *_buffOut);
private:
    int convolutionMatrix(std::vector<int> A);
};

class M2 : public DetectionFilter3p3
{
public:
    M2();
    M2( QString _name);
};

class M3 : public DetectionFilter3p3
{
public:
    M3();
    M3( QString _name);
};

class M4 : public DetectionFilter3p3
{
public:
    M4();
    M4( QString _name);
};

class M5 : public DetectionFilter3p3
{
public:
    M5();
    M5( QString _name);
};

class M6 : public DetectionFilter3p3
{
public:
    M6();
    M6( QString _name);
};

class M7 : public DetectionFilter3p3
{
public:
    M7();
    M7( QString _name);
};

class M8 : public DetectionFilter3p3
{
public:
    M8();
    M8( QString _name);
};

class M9 : public DetectionFilter3p3
{
public:
    M9();
    M9( QString _name);
};

#endif // DETECTIONFILTER3P3_HPP
