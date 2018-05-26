#ifndef DETECTIONFILTER3P3_HPP
#define DETECTIONFILTER3P3_HPP

#include "convolutionfilter.hpp"

class DetectionFilter3p3 : public DetectionFilter
{
public:
    DetectionFilter3p3();
    DetectionFilter3p3(QString _name, std::vector<int> _matrix);
    void process(FastImage *_buffIn, FastImage *_buffOut);
};

class DetectionM2 : public DetectionFilter3p3
{
public:
    DetectionM2();
    DetectionM2( QString _name);
};

class DetectionM3 : public DetectionFilter3p3
{
public:
    DetectionM3();
    DetectionM3( QString _name);
};

class DetectionM4 : public DetectionFilter3p3
{
public:
    DetectionM4();
    DetectionM4( QString _name);
};

class DetectionM5 : public DetectionFilter3p3
{
public:
    DetectionM5();
    DetectionM5( QString _name);
};

class DetectionM6 : public DetectionFilter3p3
{
public:
    DetectionM6();
    DetectionM6( QString _name);
};

class DetectionM7 : public DetectionFilter3p3
{
public:
    DetectionM7();
    DetectionM7( QString _name);
};

class DetectionM8 : public DetectionFilter3p3
{
public:
    DetectionM8();
    DetectionM8( QString _name);
};

class DetectionM9 : public DetectionFilter3p3
{
public:
    DetectionM9();
    DetectionM9( QString _name);
};

#endif // DETECTIONFILTER3P3_HPP
