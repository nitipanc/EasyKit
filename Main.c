/******************************************************************************/
/* @Driver       Pin Toggle                             					  */
/*                                                           	              */                                                                
/* @Controller   Infineon XC164CM-8FF                                         */
/*                                                                            */                                                                
/* @Compiler     Keil                  										  */
/*                                                                            */                                                                
/* @Module       User C-File                                                  */                                                                       
/*                                                                            */                                                                
/* @File         main.c             	                                      */
/*                                                                            */                                                                
/* @Version      1.0                                                          */
/*                                                                            */                                                                
/* @Description  Pin P1L.0 toggles countinously       						  */
/*																			  */
/* @Debugger	                                                			  */ 
/*     																		  */                                                           
/* @Date         26 June-2005                                                 */
/******************************************************************************/

//****************************************************************************
// @Typedefs
//****************************************************************************

typedef unsigned char  ubyte;    // 1 byte unsigned; prefix: ub 
typedef signed char    sbyte;    // 1 byte signed;   prefix: sb 
typedef unsigned int   uword;    // 2 byte unsigned; prefix: uw 
typedef signed int     sword;    // 2 byte signed;   prefix: sw 
typedef unsigned long  ulong;    // 4 byte unsigned; prefix: ul 
typedef signed long    slong;    // 4 byte signed;   prefix: sl 

//*****************************************************************************
// Global: includes and defines
//*****************************************************************************
#include <XC164.h>				  /* standard I/O .h-file              */

//*****************************************************************************
// Global: variables
//*****************************************************************************

volatile uword	counter1 = 0;
volatile uword	counter2 = 0;
volatile uword	counter3 = 0;
 
//*****************************************************************************
//             main program
//***************************************************************************** 
void main(void)
{
/************************************************************************/
/*                        Local Declarations                            */
/************************************************************************/	
 
/************************************************************************/
/*                        Main function  		                        */
/************************************************************************/

   //DP1L = (DP1L & ~(uword)0x3333) | 0x3333;	   // Set direction register Port P1L.0 as output        
	DP1L = (DP1L & ~(uword)0x0013) ;
	DP1L = (DP1L | 0x0013) ;
	while (1) 
	{
	 P1L_P0  = ~P1L_P0;	    // Toggle yellow LED
	 P1L_P1  = P1L_P1;
	 P1L_P3  = ~P1L_P3;		
	 


	 counter1 = 0x8;
	 while (counter1 > 0)
	 {
		counter1--;
		counter2 = 0xFFFF;
		while (counter2 > 0)
		{
			counter2--;
		}
	 }
	}
 }


//*****************************************************************************
//             end of program
//*****************************************************************************

