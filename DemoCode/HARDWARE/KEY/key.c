#include "key.h"
#include "delay.h" 

//������ʼ������
void KEY_Init(void)
{
	
    GPIO_InitTypeDef  GPIO_InitStructure;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOB, ENABLE);  //ʹ��GPIOA,GPIOBʱ��
 
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;                                   //KEY1Ӧ����PB2
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;                                //��ͨ����ģʽ
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;                          //100M
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;                              //����
    GPIO_Init(GPIOB, &GPIO_InitStructure);                                      //��ʼ��GPIOE2
	
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;                                   //WK_UP��Ӧ����PA0
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN ;                             //����
    GPIO_Init(GPIOA, &GPIO_InitStructure);                                      //��ʼ��GPIOA0
 
} 
//������������
//���ذ���ֵ
//mode:0,��֧��������;1,֧��������;
//0��û���κΰ�������
//2��KEY1����
//4��WKUP���� 
//ע��˺�������Ӧ���ȼ�,KEY1>WK_UP!!
u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;                                                          //�������ɿ���־
	if(mode)key_up=1;                                                            //֧������		  
	if(key_up&&(KEY1==1||WK_UP==1))
	{
		delay_ms(10);                                                            //ȥ���� 
		key_up=0;
		if(WK_UP==1)return 4;
		else if(KEY1==1)return 2;
	}else if(KEY1==0&&WK_UP==0)key_up=1; 	    
 	return 0;                                                                    // �ް�������
}