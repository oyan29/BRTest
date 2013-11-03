#ifndef  _VSWRC003_H
#define _VSWRC003_H

typedef signed char SBYTE;
typedef unsigned char UBYTE;
typedef unsigned char BYTE;
typedef signed short SWORD;
typedef unsigned short UWORD;
typedef signed int SINT;
typedef unsigned int UINT;
typedef signed long SDWORD;
typedef unsigned long UDWORD;


//�ėp********************************************************************/
/*
CPU������
CPU�S�̂̏������֐��BSync()�֐��ŗ��p������g����^����B
�����FSync�֐��̓������g���i�P�ʂ�Hz�A30Hz�ȏ�)
�߂�l�F����
*/
void Init(BYTE MainCycle);

/*
�{�^����Ԏ擾
CPU�{�[�h��̉����{�^���̏�Ԃ��擾����@
�����F�@����
�߂�l�F�@0:off�@1:on
*/
BYTE getSW();

/*
LED����
CPU�{�[�h��̂Q��LED�𐧌䂷��֐�
�����F�@0:�����@1:�΁@2:�I�����W�@3�F����
�߂�l�F�@����
*/
void LED(BYTE LedOn);

/*
���ԑ҂��@
�����F�@�҂����ԁi�P�ʁFmsec�j
�߂�l�F�@����
*/
void Wait(int msec);

/*
�����֐�
Init()�֐��Őݒ肵�����g���œ������A������߂��֐��B
��FMaincycle ��60Hz�ɐݒ肵���ꍇ�A�ȉ��̃\�[�X�ł́A����A��60Hz�Ŏ��s�����B
�������A����A��1/60sec�ȏォ����ꍇ�͈Ӗ��𐬂��Ȃ��B
while(1){
	Sync();
	����A;
}

�����F�@����
�߂�l�F�@�����ő҂����J�E���g�i�P�ʖ����j�B�O�̏ꍇ�A�ݒ肵�����g���œ����ł��Ă��Ȃ��B
			
*/
UINT Sync();

/*
Sync�֐��̓������g���擾
Init�Őݒ肵���������g�����擾����
�����F�@����
�߂�l�F�@�������g���iHz�j
*/
BYTE getMainCycle();


//���[�^********************************************************************/

/*
���[�^�̋쓮
�ݒ肵�����x�Ń��[�^���쓮�B�Ăяo������͂��̏�Ԃ�ێ����A����l��0��^����܂Œ�~���Ȃ��B

�����F�@���[�^�̐���l
		0		�F�t���[	
		0x8000	�F�t���[
		CW_MAX	�F0x7FFF�@(32767)
		CCW_MAX	�F0x8001�@(-32767)
�߂�l�F�@����
*/
void Mtr_Run_lv(int mt1,int mt2,int mt3,int mt4,int mt5,int mt6);

//VS-WRC003�Ƃ̌݊����m�ۂ̂��ߎg�p
/*
���[�^�̋쓮
�ݒ肵�����x�Ń��[�^���쓮�B�Ăяo������͂��̏�Ԃ�ێ����A����l��0��^����܂Œ�~���Ȃ��B

�����F�@���[�^�̐���l
		0		�F�t���[
		0x80	�F�t���[
		CW_MAX	�F0x7F�@(127)
		CCW_MAX	�F0x81�@(-127)
�߂�l�F�@����
*/
void Mtr_Run(BYTE mt1,BYTE mt2,BYTE mt3,BYTE mt4);


//AD���͒l�擾�@0�`7�`�����l��*****************************************************/
//#define AD_SCANMODE

/*
AD���͒l�擾
A/D�ϊ��̓��͒l���擾�B
�����F�@�`�����l���i0�`7�@=�@1�`8)
�߂�l�F�@A/D�ϊ��̒l(0�`1023)
*/
UINT AdRead(BYTE ch);


//�V���A���ʐM********************************************************************/
#define SCI_RB_SIZE 60	//��M�o�b�t�@
#define SCI_TX_SIZE 128	//���M�o�b�t�@

//���M�Ɋ��荞�݂��g�p���Ȃ��ꍇ�A�R�����g�A�E�g���邱�ƁB
//�킩��Ȃ��ꍇ�A���̂܂܂ł�OK�ł��B
//#define SCI_TX_INTERRUPT

//�{�[���[�g vs-wrc003lv 12MHz
enum brd{
CBR_115200 = 2,
CBR_57600 = 6,
CBR_38400 = 9,
CBR_31250 = 11,
CBR_19200 = 19,
CBR_14400 = 25,
CBR_9600 = 38,
CBR_4800 = 77,
CBR_2400 = 155,
};

/*�p���e�B*/
enum Parity{
even,
odd,
non
};

/*
������
�V���A���ʐM���g�p����O�ɏ��������K�v�B
�����F�@baudrate�@�F�@�{�[���[�g�̎w��i��L�񋓎q����w��j
		parity�@�F�@�p���e�B�̐ݒ�i��L�񋓎q����w��j
		stop�@�F�@�X�g�b�v�r�b�g���̐ݒ�i0�`2�j
�߂�l�F����
*/
void InitSci3(BYTE baudrate,BYTE parity ,BYTE stop);

/*
1�o�C�g��M
�V���A���ʐM��1�o�C�g��M����֐��B
�i���ۂɂ̓o�b�t�@����1�o�C�g�̂ݎ����Ă���j
�����F�@��M�f�[�^������ϐ��̃|�C���^
�߂�l�F	0�F�o�b�t�@����
			1�F�o�b�t�@�Ƀf�[�^�L��		
*/
BYTE SciByteRx(BYTE *data);

/*
1�o�C�g���M
�V���A���ʐM��1�o�C�g���M����֐��B
�����F�@���M�f�[�^
�߂�l�F	0�F�o�b�t�@���������ς��A���M�G���[
			1�F���M����	
*/
BYTE SciByteTx(BYTE data);

/*
�����񑗐M
������or�o�C�g�f�[�^�̔z��𑗐M����֐��B
�����F�@*str�F���M���镶����̃|�C���^
		dataleng�F���M���镶����
�߂�l�F	0�F�o�b�t�@���������ς��A���M�G���[
			1�F���M����	
*/
BYTE SciStrTx(BYTE *str,UINT dataleng);


//�u�U�[********************************************************************/


/*
�����A�{�����[���̐ݒ�
�u�U�[��炷�ۂ̉����ƃ{�����[����ݒ�
�����F�@pitch�F�����̐ݒ�i0�`255�A�l���傫���قǒႢ���j
		vol�F�{�����[���̐ݒ�i0�`128�j
�߂�l�F����
*/
void BuzzerSet(BYTE pitch , BYTE vol);

/*
�J�n
�u�U�[��炵�n�߂�BBuzzerStop()�֐����ĂԂ܂łȂ葱����B
�����F����
�߂�l�F����
*/
void BuzzerStart();

/*
��~
�u�U�[���~�߂�B
�����F����
�߂�l�F����
*/
void BuzzerStop();

/*
�u�U�[�����Ă��邩�ǂ����m�F
�����F����
�߂�l�F	0�F���Ă��Ȃ�
			1�F���Ă���	
*/
BYTE isBuzzer();


//PSPAD********************************************************************/
/*
PAD�f�[�^�X�V
getPAD�Ŏ擾����PAD�f�[�^�̃o�b�t�@���ŐV�̏��ɍX�V�B
�Ăяo���Ȃ��ꍇ�AgetPAD�œ����^�C�~���O�̃f�[�^���擾�����B
����I�ɌĂяo�����Ƃ��K�v�B
�����F����
�߂�l�F����
*/
void updatePAD();

/*
�f�[�^�擾
�o�b�t�@����p�b�h�̏�ԃf�[�^���擾����B
�����ɂ͗񋓎qPADDATA����K�v�Ȃ��̂��w��

�����F�@�擾����f�[�^�̔ԍ��i�񋓎q����̎w���OK�j
�߂�l�F�@�p�b�h�̏�ԃf�[�^
*/
char getPAD(BYTE num);


/*
		b7 | b6 | b5 | b4 | b3 | b2 | b1 | b0
PAD_B1�F	�� | �� | �E | �� |����| R3 | L3 |�ڸ�
PAD_B2�F	�� | �~ | �� | �� | R1 | L1 | R2 | L2 
PAD_AN_RX�F	��:00h,���S:80h,�E:FFh
PAD_AN_RY�F	��:00h,���S:80h,��:FFh
PAD_AN_LX�F	��:00h,���S:80h,�E:FFh
PAD_AN_LY�F	��:00h,���S:80h,��:FFh
*/

enum PADDATA{
PAD_B1,			//�{�^��1�o�C�g��
PAD_B2,			//�{�^��2�o�C�g��
PAD_AN_RX,		//�E�A�i���O�X�e�B�b�N���E
PAD_AN_RY,		//�E�A�i���O�X�e�B�b�N�㉺
PAD_AN_LX,		//���A�i���O�X�e�B�b�N���E
PAD_AN_LY		//���A�i���O�X�e�B�b�N�㉺
};


//�G���R�[�_**************************************************/
/*
�G���R�[�_������
�G���R�[�_�g�����g�p����ۂɁAInit()���1�x�������s����K�v������
�����F����
�߂�l�F����
*/
void InitEncoder();

/*
�G���R�[�_�N���A
�G���R�[�_�ŃJ�E���g���Ă���l��0�ɃN���A����
�����F����
�߂�l�F����
*/
void ClearEncoder();

/*
�G���R�[�_�l�擾
�G���R�[�_�ŃJ�E���g���Ă���l�擾����
�����F	*L�F�����̃J�E���g���擾����ϐ��̃|�C���^
		*R�F�E���̃J�E���g���擾����ϐ��̃|�C���^
�߂�l�F����
*/
void GetEncoder(long *L,long *R);



//���[�U�g�p�s��
void intencoder();
BYTE intsci3();

#endif