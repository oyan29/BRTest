
#include<36064s.h>
#include <string.h>
#include <machine.h>
#include "vs-wrc003lv.h"
#include "ixbus.h"


void I2C_waitFree(void);
void I2C_sendStartBit(void);
void I2C_sendStopBit(void);
void I2C_setTransmitMode(BYTE);
BYTE I2C_sendByte(BYTE);
BYTE I2C_receiveByte(BYTE, BYTE);
BYTE I2C_receive008(BYTE *data, BYTE size);

const char cHexString[16] = "0123456789ABCDEF";
unsigned char errcnt;

// I2C������
void I2C_init(void) {
	unsigned temp;

	//I2C���~�A���Z�b�g
    IIC2.ICCR1.BIT.ICE = 0;	
    IIC2.ICCR2.BIT.BBSY = 0;
    IIC2.ICCR2.BIT.SCP = 0;
	Wait(1);
	IIC2.ICCR2.BIT.IICRST = 1;
	temp = IIC2.ICSR.BYTE;
	IIC2.ICSR.BYTE = 0;
	
	//������
	IIC2.ICCR1.BIT.CKS = 0x0F;		// I2C�̓]�����[�g��/128(��=14.7456MHz, 115.2kHz)

	IIC2.ICMR.BIT.MLS = 0;			// MSB First
	IIC2.ICMR.BIT.WAIT = 0;			// WAIT����
	IIC2.ICMR.BIT.BCWP = 0;			// �r�b�g�J�E���^���C�g�v���e�N�g����
	IIC2.ICMR.BIT.BC = 0;			// 9�r�b�g
	IIC2.ICMR.BIT.BCWP = 1;			// �r�b�g�J�E���^���C�g�v���e�N�g�J�n

    IIC2.ICCR1.BIT.ICE = 1;
}

// I2C���󂭂܂ő҂�
void I2C_waitFree() {
	unsigned int i = 0;
    while (IIC2.ICCR2.BIT.BBSY == 1){
		i++;
		if(i > 0xFFFE){
			errcnt++;
			break;
		}
	};
}

// I2C�ɊJ�n�v��
void I2C_sendStartBit() {
    IIC2.ICCR2.BYTE = 0xBD;
}

// I2C�ɒ�~�v��
void I2C_sendStopBit() {
	unsigned int i = 0;
	IIC2.ICSR.BIT.STOP = 0;
	IIC2.ICCR2.BYTE = 0x3D;
	
    while(IIC2.ICSR.BIT.STOP != 1){
		i++;
		if(i > 0xFFFE){
			errcnt++;
			break;
		}		//TimeOut wait
	};
//	while (IIC2.ICSR.BIT.STOP != 1);
}

// I2C����M���[�h�̐ݒ�
//    0: �X���[�u��M
//    1: �X���[�u���M
//    2: �}�X�^��M
//    3: �}�X�^���M
void I2C_setTransmitMode(BYTE mode) {
	mode <<= 4;
	IIC2.ICCR1.BYTE = ((IIC2.ICCR1.BYTE & 0xCF) | mode);	// ����M���[�h�ݒ�
}

// I2C �o�X��1�o�C�g���M
BYTE I2C_sendByte(BYTE data) {
	unsigned int i = 0;
    while (IIC2.ICSR.BIT.TDRE != 1){
		i++;
		if(i > 0xFFFE){
			errcnt++;
			break;
		}
	};
//	while(IIC2.ICSR.BIT.TDRE != 1);
	IIC2.ICDRT = data;
	while (IIC2.ICSR.BIT.TEND != 1){
		i++;
		if(i > 0xFFFE){
			errcnt++;
			break;
		}
	};		// �f�[�^���M
//	while(IIC2.ICSR.BIT.TEND != 1);
	return(IIC2.ICIER.BIT.ACKBR);	// ACK��Ԃ�
}

// I2C �o�X����1�o�C�g��M
//    ack: �f�[�^��M������ɕԂ�ACK�r�b�g
//    rcvd: �ŏI�o�C�g�����[�h����Ƃ���1�ɂ��邱�̌��~�������s�\�ɂȂ�
//          �A�����ăf�[�^��M����ꍇ��0
BYTE I2C_receiveByte(BYTE ack, BYTE rcvd) {
   	unsigned int i = 0;
   
    BYTE rdt;

    IIC2.ICIER.BIT.ACKBT = ack;		// �f�[�^��M��ɑ��M����ACK�t���O��ݒ肷��
    IIC2.ICCR1.BIT.RCVD = rcvd;		// �ŏI�o�C�g�ǂݍ��ݎ���1
    rdt = IIC2.ICDRR;				// ��M�J�n
     while (IIC2.ICSR.BIT.RDRF != 1){
		i++;
		if(i > 0xFFFE){
			errcnt++;
			break;
		}
	}; 
	//while(IIC2.ICSR.BIT.RDRF != 1);	// �f�[�^��8bit�]�������܂ő҂�
    rdt = IIC2.ICDRR;
    return(rdt);
}

BYTE I2C_receive008(BYTE *data, BYTE size) {
    BYTE rdt;
	unsigned int i = 0;
	
	IIC2.ICIER.BIT.ACKBT = 0;		// �f�[�^��M��ɑ��M����ACK�t���O��ݒ肷��
    IIC2.ICCR1.BIT.RCVD = 0;		// �ŏI�o�C�g�ǂݍ��ݎ���1
    rdt = IIC2.ICDRR;				// ��M�J�n
    while (IIC2.ICSR.BIT.RDRF != 1){
		i++;
		if(i > 0xFFFE){
			errcnt++;
			break;
		}
	}; 
//	while(IIC2.ICSR.BIT.RDRF != 1);	// �f�[�^��8bit�]�������܂ő҂�	
	IIC2.ICIER.BIT.ACKBT = 1;		// �f�[�^��M��ɑ��M����ACK�t���O��ݒ肷��
    IIC2.ICCR1.BIT.RCVD = 1;		// �ŏI�o�C�g�ǂݍ��ݎ���1
    data[0] = IIC2.ICDRR;
	i = 0;
    while (IIC2.ICSR.BIT.RDRF != 1){
		i++;
		if(i > 0xFFFE){
			errcnt++;
			break;
		}
	}; 
//	while(IIC2.ICSR.BIT.RDRF != 1);	// �f�[�^��8bit�]�������܂ő҂�	
    data[1] = IIC2.ICDRR;
	
    return 1;
}

//addr = 0x90,0x92,0x94,0x96
char Get_IX008(BYTE Addr,unsigned int *retdata){
	const BYTE commandByte[] = {0x8C,0xCC,0x9C,0xDC,0xAC,0xEC,0xBC,0xFC};
	BYTE data[2];
	unsigned int a;
	BYTE i,j,z;
	
// �A�i���O���́iIXBUS�j
	i = 0;	
	errcnt = 0;
	z = 0;
	while(i < 8){
		I2C_waitFree();					// I2C �o�X�󂫑҂�
		if(errcnt>0){errcnt++;break;}
		
		I2C_setTransmitMode(3);		// �}�X�^���M���[�h
		
		I2C_sendStartBit();			// I2C �o�X���J�n�����ɂ���
		
		if(I2C_sendByte(Addr) == 1){  	// �X���[�u�A�h���X�𑗐M
			if(errcnt>0){errcnt++;break;}
			I2C_sendStopBit();		// i2c �o�X���~�����ɂ���B
			if(errcnt>0){errcnt++;break;}
			errcnt ++;
		}
		
		if(!errcnt){
			I2C_sendByte(commandByte[i]);	// 8C CC 9C DC AC EC BC FC (ch�Z���N�g�j
			if(errcnt>0){errcnt++;break;}
			
		    I2C_sendStartBit();				// i2c �o�X���J�n�����ɂ���
			
			if(I2C_sendByte(Addr + 1) == 1)	{		// �X���[�u�A�h���X�𑗐M
				if(errcnt>0){errcnt++;break;}
				I2C_sendStopBit();			// i2c �o�X���~�����ɂ���B
				if(errcnt>0){errcnt++;break;}
				errcnt ++;
			}
		}		
		if(!errcnt){
		    I2C_setTransmitMode(2);			// �}�X�^��M���[�h
		    IIC2.ICSR.BIT.TDRE = 0;

		    I2C_receive008(data, 2);
			if(errcnt>0){errcnt++;break;}
				
			I2C_sendStopBit();				// i2c �o�X���~�����ɂ���B
			if(errcnt>0){errcnt++;break;}
				
		    IIC2.ICCR1.BIT.RCVD = 0;
		
			I2C_setTransmitMode(0);			// �X���[�u��M���[�h�ɂ���
			
			retdata[i] = ((unsigned int)data[0] << 8) + data[1];		// 12�r�b�g�f�[�^��
			
			i++;
		//	errcnt = 0;
		}
		else{
			break;
		}
	}
	if(errcnt){
		I2C_init();
		errcnt = 0;
		
		return 0;
	}
	return 1;
}