#ifdef __cplusplus
extern "C" {
void abort(void);
#endif
void main(void);
#ifdef __cplusplus
}
#endif

/*�C���N���[�h***********************************************************/
#include<36064s.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "vs-wrc003lv.h"
#include "ixbus.h"

/*�}�N��***********************************************************/

/*�O���[�o���ϐ�***********************************************************/

/*���C���֐�***********************************************************/
/*
���̃T���v���ɂ�IX010�����������C���g���[�X�T���v���ł��B
�ő�̒l���������Z���T�l�ɂ���āA���[�^�̑��x��ύX���A���C���g���[�X���s���܂��B

*/


/*���C���֐�***********************************************************/

void main (void)
{
	//��������̐ݒ�[�P�ʁFHz�@�͈́F30.0~]
	const unsigned short MainCycle = 60;
	unsigned int data[8];

	Init(MainCycle);		//CPU�̏����ݒ�
	I2C_init();				//IXBUS������

	LED(3);

	//���[�v
	while(1){
		int i;			//���[�v�p�ϐ�
		unsigned int max_param = 0;	//�ő�̃Z���T�l���L�^����ϐ�
		int s = 0;		//�ő�̃Z���T�l�̔ԍ����L�^����ϐ�
		short mot_L = 0 , mot_R = 0;	//���[�^�o�͗p�ϐ�

		Sync();

		//addr = 0x90�A8�̒l����M
		if(Get_IX008(0x90,data) != 0){	//����Ɏ�M������
			for(i=0;i<8;i++){
				//���݊m�F���Ă���Z���T�̒l��,����܂ł̍ő�l�����傫���Ƃ�
				if(data[i] > max_param){
					max_param = data[i];	//�ő�l���X�V
					s = i;					//���݂̃Z���T�̔ԍ����L�^
				}
			}
		}

		//�ő�l���������l�ȏゾ������
		if(max_param < 3000){

			LED(1);
			//�擾�����Z���T�ԍ��ɉ����ă��[�^�̑��x��ݒ�
			switch(s){
			case 0:								//S1�̏ꍇ
				mot_R = -3000; mot_L = -10000;
				break;
			case 1:								//S2�̏ꍇ
				mot_R = 0; mot_L = -10000;
				break;
			case 2:								//S3�̏ꍇ
				mot_R = 3000; mot_L = -10000;
				break;
			case 3:								//S4�̏ꍇ
				mot_R = 7000; mot_L = -10000;
				break;
			case 4:								//S5�̏ꍇ
				mot_R = 10000; mot_L = -7000;
				break;
			case 5:								//S6�̏ꍇ
				mot_R = 10000; mot_L = -3000;
				break;
			case 6:								//S7�̏ꍇ
				mot_R = 10000; mot_L = 0;
				break;
			case 7:								//S8�̏ꍇ
				mot_R = 10000; mot_L = 3000;
				break;
			}

			Mtr_Run_lv(mot_R,mot_L,0,0,0,0);	//���[�^���x���X�V
		}
		//�������l�ȉ����������~
		else {
			LED(2);
			Mtr_Run_lv(0,0,0,0,0,0);	//���[�^���~
		}
	}
}


#ifdef __cplusplus
void abort(void)
{
	
}
#endif
