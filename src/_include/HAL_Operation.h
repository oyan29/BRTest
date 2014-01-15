#ifndef _HAL_OPERATION_H_
#define _HAL_OPERATION_H_
/*
************************************************************************
�yFile Name�zHardware Abstraction Layer �I�y���[�V�����w�b�_�[
�yDescription�z
�yRevision History�z
   REV.00 2013-12-19  BY T.OOSAKI
   REV.XX 20XX-XX-XX  BY X.XXXXXX
   REV.XX 20XX-XX-XX  BY X.XXXXXX
   REV.XX 20XX-XX-XX  BY X.XXXXXX

                      (C) 2013 IPL CORPORATION All Rights Reserved
************************************************************************
*/

// �n�[�h�E�F�A�̎��
#define HAL_HW_H836064S (0)
#define HAL_HW_H8XXXXXX (1)

/*******************************************************************************
 �y�R���t�B�M�����[�V�����z
   ���p����n�[�h�E�F�A�ɍ��킹�Ē萔��ݒ肷�� ������
*/
#define HAL_HW_SWITCH  (HAL_HW_H836064S)
/*******************************************************************************/

// �n�[�h�E�F�A�X�C�b�`�ɍ��킹�ăC���N���[�h
#if   ( HAL_HW_SWITCH == HAL_HW_H836064S )
//	#include "36064s.h"
#elif ( HAL_HW_SWITCH == HAL_HW_H8XXXXXX )
//	#include "XXXXXX.h"
#endif

#endif /* _HAL_OPERATION_H_ */
