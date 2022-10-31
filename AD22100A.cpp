// License       : License.txt
// Specifications: Spec-AD22100A.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : AD22100A.cpp
// Reason for change: 01.00.00 : 04/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "AD22100A.h"

#if     iAD22100A_ma == iSMA                            // Simple moving average filter
static float32 AD22100A_sma_buf[iAD22100A_SMA_num];
static sma_f32_t AD22100A_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iAD22100A_SMA_num ,                             // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &AD22100A_sma_buf[0]                            // buffer
};

#elif   iAD22100A_ma == iEMA                            // Exponential moving average filter
static ema_f32_t AD22100A_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iAD22100A_EMA_K                                 // Exponential smoothing factor
};

#elif   iAD22100A_ma == iWMA                            // Weighted moving average filter
static float32 AD22100A_wma_buf[iAD22100A_WMA_num];
static wma_f32_t AD22100A_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iAD22100A_WMA_num ,                             // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iAD22100A_WMA_num * (iAD22100A_WMA_num + 1)/2 , // kn sum
        &AD22100A_wma_buf[0]                            // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_AD22100A =
{
        iAD22100A               ,
        iAD22100A_pin           ,
        iAD22100A_xoff          ,
        iAD22100A_yoff          ,
        iAD22100A_gain          ,
        iAD22100A_max           ,
        iAD22100A_min           ,
        iAD22100A_ma            ,
        
#if     iAD22100A_ma == iSMA                            // Simple moving average filter
        &AD22100A_Phy_SMA       ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iAD22100A_ma == iEMA                            // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &AD22100A_Phy_EMA       ,
        (wma_f32_t*)iDummy_adr
#elif   iAD22100A_ma == iWMA                            // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &AD22100A_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
