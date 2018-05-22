#include "convfilter3p3.hpp"

ConvFilter3p3::ConvFilter3p3() : DetectionFilter()
{

}

ConvFilter3p3::ConvFilter3p3(QString _name, std::vector<int> _matrix) : DetectionFilter( _name, _matrix)
{

}

void ConvFilter3p3::process(FastImage *_buffIn, FastImage *_buffOut){
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

int ConvFilter3p3::convolutionMatrix( std::vector<int> A)
{
    std::vector<int> _matrix(get_mat());
    int result = 0;
    for( int i = 0 ; i < 9 ; i++)
    {
        if (A[i] != 0){
            result += _matrix[i] * A[i];
        }
    }

    return result;
}
