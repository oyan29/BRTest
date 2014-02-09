/*
************************************************************************
�yFile Name�z�v���b�g�t�H�[���@�\�֐�
�yDescription�z
�yRevision History�z
   REV.00 2014-02-02  BY R.ISHIKAWA
   REV.XX 20XX-XX-XX  BY X.XXXXXX
   REV.XX 20XX-XX-XX  BY X.XXXXXX
   REV.XX 20XX-XX-XX  BY X.XXXXXX

                      (C) 2013 IPL CORPORATION All Rights Reserved
************************************************************************
*/

/*
 * �C���N���[�h
 */
#include "HAL.h"
#include "PF_Common.h"

/*
 * �萔��`
 */

#define PF_TIMER_MAX (1000)// �^�C�}�J�E���g����l

/*
 * �O���֐��錾
 */

/*
 * �����֐��錾
 */

/******************************************************************************
�y���́z
******************************************************************************/
extern void PF_TimerIR(void); // 1�~���b�^�C�}���荞�݊֐�

/******************************************************************************
�y���́z�^�X�N���C���֐�
******************************************************************************/
extern void PF_TaskMain(void);


/*
 * �O���[�o���ϐ��錾
 */

static UH PF_TimerCnt;// �^�C�}���荞�݃J�E���g��

/******************************************************************************
�y���́z�v���b�g�t�H�[���@�\�������֐�
�y�ē��z�񃊃G���g�����g
�y���́z�Ȃ�
�y�o�́z�Ȃ�
�y�ߒl�z�Ȃ�
�y�����zHAL �I�y���[�V�����i�^�p���ʁj�Ŋ֐��̃G���g���[���s��
******************************************************************************/
void PF_Init(void)
{
	// �ϐ�������
	PF_TimerCnt = 0;
	// �^�C�}���荞�݊֐��o�^
	HAL_OPE_EntryTmrIR_1MS(PF_TimerIR);
	// ���C���^�X�N�֐��o�^
	HAL_OPE_EntryTaskMain(PF_TaskMain);
}

/******************************************************************************
�y���́z1�~���b�^�C�}���荞�݊֐�
�y�ē��z�񃊃G���g�����g
�y���́z�Ȃ�
�y�o�́z�Ȃ�
�y�ߒl�z�Ȃ�
�y�����z�^�C�}���荞�ݎ��̏������s��
******************************************************************************/
void PF_TimerIR(void)
{
	// �^�C�}�J�E���^�C���N�������g
	PF_TimerCnt++;
	// �^�C�}�J�E���^������ɒB���Ă���ꍇ�̓��Z�b�g����
	if(PF_TimerCnt >= PF_TIMER_MAX)
	{
		PF_TimerCnt = 0;
	}
}

/******************************************************************************
�y���́z�^�X�N���C���֐�
�y�ē��z�񃊃G���g�����g
�y���́z�Ȃ�
�y�o�́z�Ȃ�
�y�ߒl�z�Ȃ�
�y�����z�^�N�X�����֐�
******************************************************************************/
void PF_TaskMain(void)
{
	
	// �^�X�N���C���֐��͖������[�v�Ƃ���
	while(1)
	{
		switch(PF_TimerCnt)
		{
			// �����ɁA�^�X�N�X�P�W���[�����O�ɂ��Ăяo����鏈�����L�q���܂�
			case 0:
				break;
			default:
				break;
		}
	}
}