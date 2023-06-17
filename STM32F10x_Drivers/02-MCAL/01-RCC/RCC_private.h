/*********************************************************/
/* Author   : Mohamed Kamal                              */
/* Version  : V01                                        */
/* Date     : 16 Jun 2023                                */
/*********************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/* Register Definitions */
/* RCC Base Address = 0x4002 1000 */
/* Address of any Register = Peripheral Base Address + Offset */

#define RCC_CR               *((volatile u32*)0x40021000)
#define RCC_CFGR             *((volatile u32*)0x40021004)
#define RCC_CIR              *((volatile u32*)0x40021008)
#define RCC_APB2RSTR         *((volatile u32*)0x4002100C)
#define RCC_APB1RSTR         *((volatile u32*)0x40021010)
#define RCC_AHBENR           *((volatile u32*)0x40021014)
#define RCC_APB2ENR          *((volatile u32*)0x40021018)
#define RCC_APB1ENR          *((volatile u32*)0x4002101C)
#define RCC_BDCR             *((volatile u32*)0x40021020)
#define RCC_CSR              *((volatile u32*)0x40021024)

/* Clock Types : 
        1- RCC_HSE_CRYSTAL
        2- RCC_HSE_RC
        3- RCC_HSI
        4- RCC_PLL
*/
#define RCC_HSE_CRYSTAL         0
#define RCC_HSE_RC              1
#define RCC_HSI                 2
#define RCC_PLL                 3

/*
PLL Options:
    1- RCC_PLL_IN_HSI_DIV_2
    2- RCC_PLL_IN_HSE_DIV_2
    3- RCC_PLL_IN_HSE
*/
#define RCC_PLL_IN_HSI_DIV_2    0
#define RCC_PLL_IN_HSE_DIV_2    1
#define RCC_PLL_IN_HSE          2

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
#define RCC_PLL_IN_CLK_MUL_2        0
#define RCC_PLL_IN_CLK_MUL_3        1
#define RCC_PLL_IN_CLK_MUL_4        2
#define RCC_PLL_IN_CLK_MUL_5        3
#define RCC_PLL_IN_CLK_MUL_6        4
#define RCC_PLL_IN_CLK_MUL_7        5
#define RCC_PLL_IN_CLK_MUL_8        6
#define RCC_PLL_IN_CLK_MUL_9        7
#define RCC_PLL_IN_CLK_MUL_10       8
#define RCC_PLL_IN_CLK_MUL_11       9
#define RCC_PLL_IN_CLK_MUL_12       10
#define RCC_PLL_IN_CLK_MUL_13       11
#define RCC_PLL_IN_CLK_MUL_14       12
#define RCC_PLL_IN_CLK_MUL_15       13
#define RCC_PLL_IN_CLK_MUL_16       14
//#define RCC_PLL_IN_CLK_MUL_16       15

#endif