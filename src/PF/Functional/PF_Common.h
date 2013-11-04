#ifndef _PF_COMMON_H_
#define _PF_COMMON_H_
/*
************************************************************************
�yFile Name�z�W���^��`
�yDescription�z
�yRevision History�z
   REV.00 2013-11-04  BY T.OOSAKI
   REV.XX 20XX-XX-XX  BY X.XXXXXX
   REV.XX 20XX-XX-XX  BY X.XXXXXX
   REV.XX 20XX-XX-XX  BY X.XXXXXX

                      (C) 2013 IPL CORPORATION All Rights Reserved
************************************************************************
*/

#include "HAL_Common.h"

// �W���^��`
typedef	char			B;
typedef	short			H;
typedef	long			W;
typedef unsigned char   UB;
typedef	unsigned short	UH;
typedef	unsigned long	UW;

#define PF_NULL  (void *)0
#define PF_FALSE (0)
#define PF_TRUE  (1)

// ���荞�݋֎~�Ƌ֎~��Ԃ��猳��Ԃɕ��A
extern UB   PF_DisableIr( void );
extern void PF_ReturnIr( UB ucCCR );

#endif /* _PF_COMMON_H_ */
