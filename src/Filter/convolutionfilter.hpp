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
    std::vector<int>* matrix; // /!\ matrix est de dimension (9,1) m(1,1) = matrix(1), m(3,3) = matrix(9). De plus, matrix est la version retourné de la vrai matrice.
protected:
    void set_mat( std::vector<int> _matrix);
    std::vector<int> get_mat();
    virtual int convolutionMatrix( std::vector<int> A);
    inline void set_buff_k(std::vector<int>  buff_img[3], FastImage *_buffIn, int y, int x, int k);
    inline void reset_buff( std::vector<int>  buff_img[3]);
};

inline void ConvolutionFilter::set_buff_k(std::vector<int>  buff_img[3], FastImage *_buffIn, int y, int x, int k){
    buff_img[R][k]=_buffIn->Red(y,x);
    buff_img[G][k]=_buffIn->Green(y,x);
    buff_img[B][k]=_buffIn->Blue(y,x);
}

inline void ConvolutionFilter::reset_buff( std::vector<int>  buff_img[3]){
    buff_img[R] = std::vector<int>(9, 0);
    buff_img[G] = std::vector<int>(9, 0);
    buff_img[B] = std::vector<int>(9, 0);// buff_img => (0,0,0,0,0,0,0,0,0)*3
}

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
  ~BlurFilter();
};
#endif // CONVOLUTIONFILTER_HPP
