#ifndef _I2C_H
#define _I2C_H

/* �֐� */
//IXBUS***************************************************/
//I2C������
void I2C_init(void);

//VS-IX008�܂���VS-IX001����f�[�^���擾
//Addr : �g���{�[�h�̃A�h���X�@,�@retdata:�@��M�f�[�^(����8�ȏ�A16byte)
char Get_IX008(BYTE Addr,unsigned int *retdata);

#endif