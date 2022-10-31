// License       : License.txt
// Specifications: Spec-00000058.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : AD22100A_00000058.cpp
// BSL              : 00000058
// Model number     : Analog devices AD22100A
// Spec               Component type       : ADC
//                    OS                   : Mbed
//                    Calculation          : Floating-point
//                    Conversion type      : Linear
//                    Moving average filter: Moving average filter select
//                    Diagnosis            : Range (Min to Max)
// Reason for change: 01.00.00 : 04/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include "AD22100A.h"

AnalogIn AD22100A_adc( iAD22100A_pin , iVref );         // AnalogIn object

// Main Function
pp2ap_adc_t AD22100A_00000058( void )
{
        pp2ap_adc_t res = pp_00000058( AD22100A_adc , tbl_AD22100A );
        return( res );
}
