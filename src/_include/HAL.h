#ifndef _HAL_H_
#define _HAL_H_
/*
************************************************************************
�yFile Name�zHardware Abstraction Layer ���ʃw�b�_�[
�yDescription�z
�yRevision History�z
   REV.00 2013-11-04  BY T.OOSAKI
   REV.XX 20XX-XX-XX  BY X.XXXXXX
   REV.XX 20XX-XX-XX  BY X.XXXXXX
   REV.XX 20XX-XX-XX  BY X.XXXXXX

                      (C) 2013 IPL CORPORATION All Rights Reserved
************************************************************************
*/

#include "PF_Common.h"

// ���荞�݋֎~�Ƌ֎~��Ԃ��猳��Ԃɕ��A
extern UB   HAL_DisableIr( void );
extern void HAL_ReturnIr( UB ubCCR );

#endif /* _HAL_H_ */
