#include "configuration.h"
#include "stdarg.h"
#include "stdio.h"
#include "stdlib.h"


#define CMD_BUFFER_LEN 100
#define OV7670_IMAGE_SIZE 20000
#define OV2650_FLASH_SETOR ((uint16_t)0x0028)   //ÉÈÇø5
#define OV2640_FLASH_ADDR_START 0x08020000
#define OV2640_FLASH_ADDR_END 0x080201FC
#define PARAM_FLASH_SETOR ((uint16_t)0x0020) //  ÉÈÇø4
#define PARAM_FLASH_ADDR_START 0x08010000
#define PARAM_FLASH_ADDR_END 0x080104FC


extern int g_tim1_irq_flg;
extern int g_rotary;
extern float g_round;
extern u32 g_ov7670_irq_flag;
extern char g_ov7670_image[40000];
extern u8 g_ov2640_custom_config[][2]; 
extern u32 g_ov7670_line_cnt;
extern u16 g_ov7670_cols_cnt;
extern int g_light_sensor_left,g_light_sensor_right;
extern int g_color_right_flag;
extern float g_gyro[3];

void myprintf (USART_TypeDef* USARTx, char *fmt, ...);
void delay_us(uint32_t us);
void delay_ms(uint16_t ms);
void tim3_pwm_set(u16 freq,u16 duty);
void exti_color_disable();
void exti_color_enable();
void acar_init();