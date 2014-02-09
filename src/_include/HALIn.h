#ifndef _HAL_IN_H_
#define _HAL_IN_H_
/*
************************************************************************
�yFile Name�zHardware Abstraction Layer ���ʃw�b�_�[(�����B���p)
�yDescription�z
�yRevision History�z
   REV.00 2013-11-04  BY T.OOSAKI
   REV.XX 20XX-XX-XX  BY X.XXXXXX
   REV.XX 20XX-XX-XX  BY X.XXXXXX
   REV.XX 20XX-XX-XX  BY X.XXXXXX

                      (C) 2013 IPL CORPORATION All Rights Reserved
************************************************************************
*/

#include "HAL.h"
#include "HAL_Operation.h"

/*
 * �֐��|�C���^�錾
 */

// 1ms�^�C�}�[���荞�݊֐��|�C���^�錾
typedef	void (*HAL_TIMER_IR_1MS)(void);
extern	HAL_TIMER_IR_1MS	fpHAL_TIMER_IR_1MS;

// �^�X�N�X�P�W���[���֐��|�C���^�錾
typedef	void (*HAL_TASKMAIN_1MS)(void);
extern	HAL_TASKMAIN_1MS	fpHAL_TASKMAIN_1MS;

/*
 * �֐�
 */


#endif /* _HAL_IN_H_ */
