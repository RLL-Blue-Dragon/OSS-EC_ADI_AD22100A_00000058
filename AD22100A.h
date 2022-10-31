// License       : License.txt
// Specifications: Spec-AD22100A.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : AD22100A.h
// Reason for change: 01.00.00 : 04/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __AD22100A_H__
#define __AD22100A_H__

#include "user_define.h"

// Components number
#define iAD22100A               106U                    // Analog devices AD22100A

// AD22100A System Parts definitions
#define iAD22100A_xoff          ( 1.375F*(iADC_vdd/5.0F) )      // X offset [V]
#define iAD22100A_yoff          0.0F                    // Y offset [degree celsius]
#define iAD22100A_gain          ( 0.0225F*(iADC_vdd/5.0F) )     // Gain [V/degree celsius]
#define iAD22100A_max           85.0F                   // Temperature Max [degree celsius]
#define iAD22100A_min           -40.0F                  // Temperature Min [degree celsius]

extern const tbl_adc_t tbl_AD22100A;

#endif /*__AD22100A_H__*/
