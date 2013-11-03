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

/*
 * �C���N���[�h
 */
#include "HAL_Common.h"

/*
 * �萔��`
 */
#define PF_NULL  (void *)0
#define PF_FALSE (0)
#define PF_TRUE  (1)

/*
 * �^��`
 */
typedef	char			B;
typedef	short			H;
typedef	long			W;
typedef unsigned char   UB;
typedef	unsigned short	UH;
typedef	unsigned long	UW;


/*
 * �O���֐��錾
 */
extern UB   PF_DisableIr( void );		// ���荞�݋֎~
extern void PF_ReturnIr( UB ucCCR );	// �֎~��Ԃ��猳��Ԃɕ��A

#endif /* _PF_COMMON_H_ */
