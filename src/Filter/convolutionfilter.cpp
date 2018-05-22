#include "src/Filter/convolutionfilter.hpp"
#define R 0
#define G 1
#define B 2

ConvolutionFilter::ConvolutionFilter() : Filter()
{
    matrix.clear();
}

ConvolutionFilter::ConvolutionFilter( QString _name, std::vector<int> _matrix) : Filter( _name)
{
    set_mat( _matrix);
}

ConvolutionFilter::~ConvolutionFilter()
{

}

std::vector<int> ConvolutionFilter::get_mat(){
    return matrix;
}

void ConvolutionFilter::set_mat(const std::vector<int> _matrix)
{
    if (_matrix.size() != 9){
        exit(EXIT_FAILURE);
    }

    std::vector<int> buff(_matrix);
    if (buff.size() != 9){
        exit(EXIT_FAILURE);
    }
    matrix.clear();
    while( matrix.size() < 9 )
    {
        matrix.push_back(buff.back());
        buff.pop_back();
    }

}

inline void set_buff_k(std::vector<int>  buff_img[3], FastImage *_buffIn, int y, int x, int k){
    buff_img[R][k]=_buffIn->Red(y,x);
    buff_img[G][k]=_buffIn->Green(y,x);
    buff_img[B][k]=_buffIn->Blue(y,x);
}

inline void reset_buff( std::vector<int>  buff_img[3]){
    buff_img[R] = std::vector<int>(9, 0);
    buff_img[G] = std::vector<int>(9, 0);
    buff_img[B] = std::vector<int>(9, 0);// buff_img => (0,0,0,0,0,0,0,0,0)*3
}

void ConvolutionFilter::process(FastImage *_buffIn, FastImage *_buffOut)
{
    int w = _buffIn->width(), h = _buffIn->height();
    if( _buffOut->width() != w || _buffOut->height() != h ){
        _buffOut->resize(h, w);
    }

    std::vector<int>  buff_img[3]; // DIM(buff_img) = (9,3)

    ///* Cas y = 0 *///-------------------------------------------------------------------------------------------------------
    int y = 0;

    // Cas x = 0 -------------------------------------------------------------------------------------------------------------
    int x = 0;

    reset_buff( buff_img);

    int k = 4;
    while( k < 9 )
    {
        if ( k==5){
            set_buff_k( buff_img, _buffIn, y, x, k);
            k+=2;
        } else {
            set_buff_k( buff_img, _buffIn, y, x, k);
            k++;
        }
    }

    _buffOut->RGB( y, x, convolutionMatrix( buff_img[R]), convolutionMatrix( buff_img[G]), convolutionMatrix( buff_img[B]));
    // Fin cas x = 0 ---------------------------------------------------------------------------------------------------------

    // Cas général pour x ----------------------------------------------------------------------------------------------------
    for(x=1; x<(w-1); x++){

        reset_buff( buff_img);

        for ( k = 3; k < 9; k++){

            set_buff_k( buff_img, _buffIn, y, x, k);
        }
        _buffOut->RGB( y, x, convolutionMatrix( buff_img[R]), convolutionMatrix( buff_img[G]), convolutionMatrix( buff_img[B]));
    }
    // Fin cas général pour x ------------------------------------------------------------------------------------------------

    // Cas x = w-1 -----------------------------------------------------------------------------------------------------------
    k=3;
    reset_buff( buff_img);

    while( k < 8 )
    {
        if ( k==4){
            set_buff_k( buff_img, _buffIn, y, x, k);
            k+=2;
        } else {
            set_buff_k( buff_img, _buffIn, y, x, k);
            k++;
        }
    }
    _buffOut->RGB( y, x, convolutionMatrix( buff_img[R]), convolutionMatrix( buff_img[G]), convolutionMatrix( buff_img[B]));
    // Fin cas x = w-1 -------------------------------------------------------------------------------------------------------

    ///* Fin cas y = 0 */// --------------------------------------------------------------------------------------------------

    ///* Début cas général pour y */// ---------------------------------------------------------------------------------------
    for( y=1; y<(h-1); y++){

    // Cas x = 0 -------------------------------------------------------------------------------------------------------------
        int x = 0;
        reset_buff( buff_img);

        int k = 1;
        while( k < 9 )
        {
            if (k == 2 || k==5){
                set_buff_k( buff_img, _buffIn, y, x, k);
                k+=2;
            } else {
                set_buff_k( buff_img, _buffIn, y, x, k);
                k++;
            }
        }

        _buffOut->RGB( y, x, convolutionMatrix( buff_img[R]), convolutionMatrix( buff_img[G]), convolutionMatrix( buff_img[B]));
    // Fin cas x = 0 ---------------------------------------------------------------------------------------------------------

    // Cas général pour x ----------------------------------------------------------------------------------------------------
        for(x=1; x<(w-1); x++){

            reset_buff( buff_img);

            for ( k=0; k < 9; k++){

                set_buff_k( buff_img, _buffIn, y, x, k);
            }
            _buffOut->RGB( y, x, convolutionMatrix( buff_img[R]), convolutionMatrix( buff_img[G]), convolutionMatrix( buff_img[B]));
        }
    // Fin cas général pour x ------------------------------------------------------------------------------------------------

    // Cas x = w-1 -----------------------------------------------------------------------------------------------------------
        k=0;
        reset_buff( buff_img);

        while( k < 8 )
        {
            if (k == 1 || k==4){
                set_buff_k( buff_img, _buffIn, y, x, k);
                k+=2;
            } else {
                set_buff_k( buff_img, _buffIn, y, x, k);
                k++;
            }
        }
    // Fin cas x = w-1 -------------------------------------------------------------------------------------------------------

    }
    ///* Fin cas général pour y */// -----------------------------------------------------------------------------------------

    ///* Cas y = h-1 */// ----------------------------------------------------------------------------------------------------

    // Cas x = 0 -------------------------------------------------------------------------------------------------------------
    x = 0;

    reset_buff( buff_img);

    k = 1;
    while( k < 6 )
    {
        if ( k==2){
            set_buff_k( buff_img, _buffIn, y, x, k);
            k+=2;
        } else {
            set_buff_k( buff_img, _buffIn, y, x, k);
            k++;
        }
    }

    _buffOut->RGB( y, x, convolutionMatrix( buff_img[R]), convolutionMatrix( buff_img[G]), convolutionMatrix( buff_img[B]));
    // Fin cas x = 0 ---------------------------------------------------------------------------------------------------------

    // Cas général pour x ----------------------------------------------------------------------------------------------------
    for(x=1; x<(w-1); x++){

        reset_buff( buff_img);

        for ( k = 0; k < 6; k++){

            set_buff_k( buff_img, _buffIn, y, x, k);
        }
        _buffOut->RGB( y, x, convolutionMatrix( buff_img[R]), convolutionMatrix( buff_img[G]), convolutionMatrix( buff_img[B]));
    }
    // Fin cas général pour x ------------------------------------------------------------------------------------------------

    // Cas x = w-1 -----------------------------------------------------------------------------------------------------------
    k = 0;
    reset_buff( buff_img);

    while( k < 5 )
    {
        if ( k == 1){
            set_buff_k( buff_img, _buffIn, y, x, k);
            k += 2;
        } else {
            set_buff_k( buff_img, _buffIn, y, x, k);
            k++;
        }
    }
    _buffOut->RGB( y, x, convolutionMatrix( buff_img[R]), convolutionMatrix( buff_img[G]), convolutionMatrix( buff_img[B]));
    // Fin cas x = w-1 -------------------------------------------------------------------------------------------------------

    ///* Fin cas y = h-1 */// ------------------------------------------------------------------------------------------------

}


int ConvolutionFilter::convolutionMatrix( std::vector<int> A)
{

    return 0;
}
