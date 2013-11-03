/***********************************************************************/
/*                                                                     */
/*  FILE        :dbsct.c                                               */
/*  DATE        :Mon, Jun 11, 2007                                     */
/*  DESCRIPTION :Setting of B,R Section                                */
/*  CPU TYPE    :H8/36064                                              */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.5).     */
/*                                                                     */
/***********************************************************************/
                  


#include "vs-wrc003lv.h"

#pragma section $DSEC
static const struct {
	UBYTE *rom_s;       /* Start address of the initialized data section in ROM */
	UBYTE *rom_e;       /* End address of the initialized data section in ROM   */
	UBYTE *ram_s;       /* Start address of the initialized data section in RAM */
}DTBL[]= {
	{__sectop("D"), __secend("D"), __sectop("R")},
//	{__sectop("$ABS8D"), __secend("$ABS8D"), __sectop("$ABS8R")},
//	{__sectop("$ABS16D") , __secend("$ABS16D") , __sectop("$ABS16R") }
};
#pragma section $BSEC
static const struct {
	UBYTE *b_s;         /* Start address of non-initialized data section */
	UBYTE *b_e;         /* End address of non-initialized data section */
}BTBL[]= {
	{__sectop("B"), __secend("B")},
//	{__sectop("$ABS8B"), __secend("$ABS8B")},
//	{__sectop("$ABS16B"), __secend("$ABS16B")}
};
