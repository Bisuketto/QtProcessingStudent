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

class M2 : public ConvFilter3p3
{
public:
    M2();
    M2( QString _name);
};

class M3 : public ConvFilter3p3
{
public:
    M3();
    M3( QString _name);
};

class M4 : public ConvFilter3p3
{
public:
    M4();
    M4( QString _name);
};

class M5 : public ConvFilter3p3
{
public:
    M5();
    M5( QString _name);
};

class M6 : public ConvFilter3p3
{
public:
    M6();
    M6( QString _name);
};

class M7 : public ConvFilter3p3
{
public:
    M7();
    M7( QString _name);
};

class M8 : public ConvFilter3p3
{
public:
    M8();
    M8( QString _name);
};

class M9 : public ConvFilter3p3
{
public:
    M9();
    M9( QString _name);
};

#endif // CONVFILTER3P3_HPP
