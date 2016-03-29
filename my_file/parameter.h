#include "stm32f4xx.h"
#include "link_list.h"
#include "global.h"
//���ƻ����˵Ĵ����У�����Ҫ���Ĳ��������з�������ṹ��(param_struct�ṹ��)��
//�Ժ���Ҫ��Ӳ��������Ⱦ�Ҫ������(param_struct�ṹ��)��ӣ�Ȼ����parameter.c�ļ������param_update()����������Ӷ�Ӧ�ĺ�PARAM_UPDATE()
//ÿ����������Ľڵ����ݱ��ı��ʱ�򣬿���ִ�к���param_update_all()������patam_struct�ṹ�������г�Ա������
//����һ�θı�Ĳ������࣬����Ե������ú�PARAM_UPDATE()�����³�Ա������



typedef struct{
		float servo_p;
		float servo_i;
		float servo_d;
		float threshold;
		float servo_centroid;
		float servo_p_gain;
		float servo_d_gain;
		float servo_p_base;
		float servo_d_base;
		float return_right;
		float return_left;
		float fturn_right;
		float fturn_left;
	
		/*�����Ǵ󳵵Ĳ���*/
		float acar_a;  //�󳵼��ٶȵ�λ
		float acar_v;   //���ٶȵ�λ
		float acar_wa;   //����ת���ٶȵ�λ
		float acar_w;		//����ת�ٶȵ�λ
		float acar_xita1;  //���ִ󳵵����Ӽн�
		float acar_xita2;
		float acar_xita3;
		float acar_l1;     //���ִ����ӵ��е�ľ���
		float acar_l2;
		float acar_l3;
		float gyro_x_adj;
}param_struct;

extern param_struct *g_control_param;   //����ṹ������ɱ��ⲿ���� 
extern link_list g_param_list;    //��������

//�������������еĲ������������²���   USARTx Ϊ���������Ϣ�Ĵ���
#define PARAM_UPDATE(param_list,control_param_array,param_name,USARTx) \
					if(list_search(&param_list,#param_name) != NULL){    \
							int i;                  \
							for(i = 0;i < PARAM_GROUP_LENGTH;i++){     \
									control_param_array[i].param_name = list_search(&param_list,#param_name)->data->param_value[i];  	\
							}      \
					}else{   \
							myprintf(USARTx,"param_name:%s not found\n",#param_name);              \
					}                                                     \
					
					
void param_update_all();
int param_save_to_flash();
int	param_ld_from_flash();
int param_list_reset();
int param_switch(param_struct **control_param,int group_num);  //�л�������
int param_group_now();  //��ò�������