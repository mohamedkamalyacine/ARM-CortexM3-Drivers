/*********************************************************/
/* Author   : Mohamed Kamal                              */
/* Version  : V01                                        */
/* Date     : 16 Jun 2023                                */
/*********************************************************/

#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H

#define RCC_AHB         0
#define RCC_APB1        1
#define RCC_APB2        2

/*
Options : 
    1- RCC_HSE_CRYSTAL
    2- RCC_HSE_RC
    3- RCC_HSI
    4- RCC_PLL
*/
#define RCC_CLOCK_TYPE  RCC_HSE_CRYSTAL

/*
Options:
    1- RCC_PLL_IN_HSI_DIV_2 (Default)
    2- RCC_PLL_IN_HSE_DIV_2
    3- RCC_PLL_IN_HSE
*/
/* Note: Select this value if only you have PLL as an input Clock Source*/
#if RCC_CLOCK_TYPE == RCC_PLL
    #define RCC_PLL_INPUT   RCC_PLL_IN_HSI_DIV_2
#endif  //RCC_CLOCK_TYPE

/*
Options 2 to 16:
1- RCC_PLL_IN_CLK_MUL_2
2- RCC_PLL_IN_CLK_MUL_3
3- RCC_PLL_IN_CLK_MUL_4
4- RCC_PLL_IN_CLK_MUL_5
5- RCC_PLL_IN_CLK_MUL_6
6- RCC_PLL_IN_CLK_MUL_7
7- RCC_PLL_IN_CLK_MUL_8
8- RCC_PLL_IN_CLK_MUL_9
9- RCC_PLL_IN_CLK_MUL_10
10- RCC_PLL_IN_CLK_MUL_11
11- RCC_PLL_IN_CLK_MUL_12
12- RCC_PLL_IN_CLK_MUL_13
13- RCC_PLL_IN_CLK_MUL_14
14- RCC_PLL_IN_CLK_MUL_15
15- RCC_PLL_IN_CLK_MUL_16
16- RCC_PLL_IN_CLK_MUL_16
*/
/* Note: Select this value if only you have PLL as an input Clock Source*/
#if RCC_CLOCK_TYPE == RCC_PLL
    #define RCC_PLL_MUL_VAL     RCC_PLL_IN_CLK_MUL_2
#endif //RCC_CLOCK_TYPE

#endif // _RCC_CONFIG_H