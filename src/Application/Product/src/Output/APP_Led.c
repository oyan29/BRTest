/*
************************************************************************
�yFile Name�zLED����֐�(�A�v���P�[�V������)
�yDescription�z
�yRevision History�z
   REV.00 2014-02-11  BY R.ISHIKAWA
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

/*
 * �O���֐��錾
 */

/*
 * �����֐��錾
 */

/*
 * �O���[�o���ϐ��錾
 */

/******************************************************************************
�y���́zLED����֐�
�y�ē��z�񃊃G���g�����g
�y���́zLED1(�I�����W)��ԁALED2(��)���
�y�o�́z�Ȃ�
�y�ߒl�z�Ȃ�
�y�����zLED1�A2�̏�Ԃ������Ŏw�肵����ԂɕύX����
******************************************************************************/
void APP_LED_Set(UB ubLed1, UB ubLed2)
{
	// �n�[�h�E�F�A�ʂ�LED����֐����Ăяo��
	HAL_LED1_Set(ubLed1);
	// �n�[�h�E�F�A�ʂ�LED����֐����Ăяo��
	HAL_LED2_Set(ubLed2);
}

