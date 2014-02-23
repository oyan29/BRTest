/*
************************************************************************
�yFile Name�z�E�H�b�`�h�b�O�^�C�}
�yDescription�z
�yRevision History�z
   REV.00 2014-02-23  BY R.ISHIKAWA
   REV.XX 20XX-XX-XX  BY X.XXXXXX
   REV.XX 20XX-XX-XX  BY X.XXXXXX
   REV.XX 20XX-XX-XX  BY X.XXXXXX

                      (C) 2013 IPL CORPORATION All Rights Reserved
************************************************************************
*/

/*
 * �C���N���[�h
 */
#include "HALIn.h"
#include "36064s.h"
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


#if ( HAL_HW_SWITCH == HAL_HW_H836064S )
/******************************************************************************
�y���́z�E�H�b�`�h�b�O�^�C�}������
�y�ē��z�񃊃G���g�����g
�y���́z�Ȃ�
�y�o�́z�Ȃ�
�y�ߒl�z�Ȃ�
�y�����zWDT���W�X�^�̏�����
        ���E�H�b�`�h�b�O�^�C�}�͏����l�ł͓��삵�Ȃ��悤�ɂ���
******************************************************************************/
void WDT_Init( void )
{
	WDT.TCSRWD.BYTE=0x92;	
	WDT.TCSRWD.BYTE=0x92;
	
	WDT.TCSRWD.BIT.B4WI = 0;
	WDT.TCSRWD.BIT.TCSRWE=1;

	WDT.TCSRWD.BIT.B2WI=0;
	WDT.TCSRWD.BIT.WDON=0;
	
	WDT.TMWD.BYTE=0xFF;
	WDT.TCSRWD.BIT.B6WI = 1;
	WDT.TCSRWD.BIT.TCWE = 1;
	WDT.TCWD=0x00;
}

#endif
