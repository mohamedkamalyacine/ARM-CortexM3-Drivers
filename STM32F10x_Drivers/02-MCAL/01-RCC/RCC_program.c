/*********************************************************/
/* Author   : Mohamed Kamal                              */
/* Version  : V01                                        */
/* Date     : 16 Jun 2023                                */
/*********************************************************/

#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void)
{
    /* Options : 
        1- RCC_HSE_CRYSTAL
        2- RCC_HSE_RC
        3- RCC_HSI
        4- RCC_PLL
    */

    #if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
        RCC_CR   = 0x00010000;      /* Enable HSE with no bypass --> bit16(HSE ON) = 1, bit18(HSE BYP) = 0*/
        RCC_CFGR = 0x00000001;      /* 01: HSE selected as system clock */
    #elif RCC_CLOCK_TYPE == RCC_HSE_RC
        RCC_CR   = 0x00050000;      /* Enable HSE with bypass (RC CLOCK) --> bit16(HSE ON) = 1, bit18(HSE BYP) = 1*/
        RCC_CFGR = 0x00000001;      /* 01: HSE selected as system clock */
    #elif RCC_CLOCK_TYPE == RCC_HSI
        RCC_CR   = 0x00000081;      /* Enable HSI + Trimming --> bit1(HSION) = 1*/
        RCC_CFGR = 0x00000000;      /* 00: HSI selected as system clock */
    #elif RCC_CLOCK_TYPE == RCC_PLL
        #if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
            RCC_CR   = 0x01000081;      /* Enable bit24(PLLON) + Enable HSI + Trimming */
            RCC_CFGR = 0x00000002;      /* Enable HSI input source of PLL and divided by 2*/
        #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
            RCC_CR   = 0x01010000;      /* Enable bit24(PLLON) + Enable HSE with no bypass*/
            RCC_CFGR = 0x00030002;      /* Enable HSE input source of PLL and divided by 2*/
        #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
            RCC_CR   = 0x01010000;      /* Enable bit24(PLLON) + Enable HSE with no bypass*/
            RCC_CFGR = 0x00010002;      /* Enable HSE input source of PLL and NOT divided */
        #endif
    #else
        #error("Wrong Clock Type has been choosen")
    #endif
}

/* Copy_u8BusId --> bus Number,  Copy_u8PerId --> Peripheral Number*/
/* Copy_u8PerId Must be in range 0:31 */
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
    if (Copy_u8PerId <= 31)
    {
        switch (Copy_u8BusId)
        {
            case RCC_AHB:
                SET_BIT(RCC_AHBENR, Copy_u8PerId);
            break;

            case RCC_APB1:
                SET_BIT(RCC_APB1ENR, Copy_u8PerId);
            break;

            case RCC_APB2:
                SET_BIT(RCC_APB2ENR, Copy_u8PerId);
            break;
            
            default:
                /* Return Error */
            break;
        }
    }
    else
    {
        /* Return Error */
    }
}

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
    if (Copy_u8PerId <= 31)
    {
        switch (Copy_u8BusId)
        {
            case RCC_AHB:
                CLR_BIT(RCC_AHBENR, Copy_u8PerId);
            break;

            case RCC_APB1:
                CLR_BIT(RCC_APB1ENR, Copy_u8PerId);
            break;

            case RCC_APB2:
                CLR_BIT(RCC_APB2ENR, Copy_u8PerId);
            break;
            
            default:
                /* Return Error */
            break;
        }
    }
    else
    {
        /* Return Error */
    }
}