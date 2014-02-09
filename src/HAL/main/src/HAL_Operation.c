/*
************************************************************************
�yFile Name�zHAL �I�y���[�V�����i�^�p���ʁj
�yDescription�z
�yRevision History�z
   REV.00 2013-12-19  BY T.OOSAKI
   REV.01 2014-01-25  BY R.ISHIKAWA
   REV.XX 20XX-XX-XX  BY X.XXXXXX
   REV.XX 20XX-XX-XX  BY X.XXXXXX

                      (C) 2013 IPL CORPORATION All Rights Reserved
************************************************************************
*/

/*
 * �C���N���[�h
 */
#include "HALIn.h"

/*
 * �萔��`
 */

/*
 * �O���֐��錾
 */

/*
 * �����֐��錾
 */

/*
 * �O���[�o���ϐ��錾
 */

// 1ms�^�C�}�[���荞�݊֐��|�C���^
HAL_TIMER_IR_1MS	fpHAL_TIMER_IR_1MS = PF_NULL;
// �^�X�N�X�P�W���[���֐��|�C���^�錾
HAL_TASKMAIN_1MS	fpHAL_TASKMAIN_1MS = PF_NULL;

/******************************************************************************
�y���́z1�~���b�^�C�}���荞�݊֐��o�^
�y�ē��z�񃊃G���g�����g
�y���́z1�~���b�^�C�}���荞�݂ŌĂяo�����֐��|�C���^
�y�o�́z�Ȃ�
�y�ߒl�z�Ȃ�
�y�����z�^�C�}���荞�݊֐���o�^����
******************************************************************************/
void HAL_OPE_EntryTmrIR_1MS(HAL_TIMER_IR_1MS fpEntryIR )
{
	// ������null�łȂ��ꍇ�A�O���[�o���ϐ��ɓo�^����
	if(fpEntryIR != PF_NULL)
	{
		fpHAL_TIMER_IR_1MS = fpEntryIR;
	}
}

/******************************************************************************
�y���́z�^�X�N���C���֐��o�^
�y�ē��z�񃊃G���g�����g
�y���́z�^�X�N�����֐��|�C���^
�y�o�́z�Ȃ�
�y�ߒl�z�Ȃ�
�y�����z�^�N�X�����֐���o�^����
******************************************************************************/
void HAL_OPE_EntryTaskMain(HAL_TASKMAIN_1MS fpEntryTASK )
{
	// ������null�łȂ��ꍇ�A�^�X�N�����֐����O���[�o���ϐ��ɓo�^����
	if(fpEntryTASK != PF_NULL)
	{
		fpHAL_TASKMAIN_1MS = fpEntryTASK;
	}
}

