#ifndef CONVOLUTIONFILTER_HPP
#define CONVOLUTIONFILTER_HPP

#include "filter.hpp"
#define R 0
#define G 1
#define B 2

class ConvolutionFilter : public Filter
{
public:
    ConvolutionFilter();
    ConvolutionFilter( QString _name, std::vector<int> _matrix);
    ~ConvolutionFilter();
    virtual void process(FastImage* _buffIn, FastImage* _buffOut);
private:
    std::vector<int>* matrix; // /!\ matrix est de dimension (9,1) m(1,1) = matrix(1), m(3,3) = matrix(9).
protected:
    void set_mat( std::vector<int> _matrix);
    std::vector<int> get_mat();
    int get_coef(int y, int x);

};

class DetectionFilter : public ConvolutionFilter{
public:
  DetectionFilter();
  DetectionFilter( QString _name, std::vector<int> _matrix);
  ~DetectionFilter();
};

class BlurFilter : public ConvolutionFilter{
public:
  BlurFilter();
  BlurFilter( QString _name, std::vector<int> _matrix);
  BlurFilter( QString _name, std::vector<int> _matrix, int _norm);
  ~BlurFilter();
  int get_norm();
private:
  int * norm;
protected:
  void set_norm( int _n);
  int calc_norm();
  void calc_set_norm();
};
#endif // CONVOLUTIONFILTER_HPP
