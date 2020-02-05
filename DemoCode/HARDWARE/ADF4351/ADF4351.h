#ifndef __ADF4351_H
#define __ADF4351_H
#include "sys.h"
#include "delay.h"

/*
*
*   CE      ��оƬʹ�ܣ��ߵ�ƽ��Ч
*   LE      ������ʹ�ܣ��ߵ�ƽ��Ч
*   CLK     ������ʱ�����룬��������Ч
*   DATA    �������������룬����������MSB���ȷ�ʽ���أ�����LSB��������λ
*
**/

// ����ADF_DATA���������ߵĲ�������
#define ADF_DATA_READ()  {GPIOG->MODER &= ~(3 << 13*2); GPIOG->MODER |= (0 << 13*2);}
#define ADF_DATA_WRITE() {GPIOG->MODER &= ~(3 << 13*2); GPIOG->MODER |= (1 << 13*2);}

// λ������
#define ADF_CE          PGout(14)
#define ADF_LE          PGout(15)
#define ADF_CLK         PGout(12)
// ע�������߲�������

#define ADF_DATA_OUT    PGout(13)
#define ADF_DATA_IN     PGin(13)

// GPIO��ʼ��
void ADF_GPIO_Init(void);
void ADF_Init(void);
void WriteOneRegToADF4351(u32 Regster);
void ADF4351_Init_some(void);
void ADF4351WriteFreq(float Fre);		//	(xx.x) M Hz
#endif

