//////////////////////////////////////////////////////////////////////////////////
// 本程序只供学习使用，未经作者许可，不得用于其它任何用途
// 测试硬件：单片机STM32F407ZGT6,正点原子Explorer STM32F4开发板,主频168MHZ，晶振12MHZ
// QDtech-TFT液晶驱动 for STM32 FSMC
// xiao冯@ShenZhen QDtech co.,LTD
// 公司网站:www.qdtft.com
// 淘宝网站：http://qdtech.taobao.com
// wiki技术网站：http://www.lcdwiki.com
// 我司提供技术支持，任何技术问题欢迎随时交流学习
// 固话(传真) :+86 0755-23594567
// 手机:15989313508（冯工）
// 邮箱:lcdwiki01@gmail.com    support@lcdwiki.com    goodtft@163.com
// 技术支持QQ:3002773612  3002778157
// 技术交流QQ群:324828016
// 创建日期:2018/08/09
// 版本：V1.0
// 版权所有，盗版必究。
// Copyright(C) 深圳市全动电子技术有限公司 2018-2028
// All rights reserved
/****************************************************************************************************
//此模块可以直接插入正点原子Explorer STM32F4开发板TFTLCD插槽，无需手动接线
//STM32连接引脚是指TFTLCD插槽引脚内部连接的STM32引脚
//=========================================电源接线================================================//
//     LCD模块             TFTLCD插槽引脚        STM32连接引脚
//      VDD       --->         5V/3.3              DC5V/3.3V          //电源
//      GND       --->          GND                  GND              //电源地
//=======================================液晶屏数据线接线==========================================//
//本模块默认数据总线类型为16位并口总线
//     LCD模块             TFTLCD插槽引脚        STM32连接引脚
//      DB0       --->          D0                   PD14        -|
//      DB1       --->          D1                   PD15         |
//      DB2       --->          D2                   PD0          |
//      DB3       --->          D3                   PD1          |
//      DB4       --->          D4                   PE7          |
//      DB5       --->          D5                   PE8          |
//      DB6       --->          D6                   PE9          |
//      DB7       --->          D7                   PE10         |
//如果使用8位模式，请使用下面高8位并口数据引脚                    |===>液晶屏16位并口数据信号
//      DB8       --->          D8                   PE11         |
//      DB9       --->          D9                   PE12         |
//      DB10      --->          D10                  PE13         |
//      DB11      --->          D11                  PE14         |
//      DB12      --->          D12                  PE15         |
//      DB13      --->          D13                  PD8          |
//      DB14      --->          D14                  PD9          |
//      DB15      --->          D15                  PD10        -|
//=======================================液晶屏控制线接线==========================================//
//     LCD模块 				     TFTLCD插槽引脚        STM32连接引脚
//       WR       --->          WR                   PD5             //液晶屏写数据控制信号
//       RD       --->          RD                   PD4             //液晶屏读数据控制信号
//       RS       --->          RS                   PF12            //液晶屏数据/命令控制信号
//       RST      --->          RST                复位引脚          //液晶屏复位控制信号
//       CS       --->          CS                   PG12            //液晶屏片选控制信号
//       BL       --->          BL                   PB15            //液晶屏背光控制信号
//=========================================触摸屏触接线=========================================//
//如果模块不带触摸功能或者带有触摸功能，但是不需要触摸功能，则不需要进行触摸屏接线
//	   LCD模块             TFTLCD插槽引脚        STM32连接引脚
//      HAL_GPIO_ReadPin(GPIOC,PEN_Pin)       --->          HAL_GPIO_ReadPin(GPIOC,PEN_Pin)                  PB1             //触摸屏触摸中断信号
//      MISO      --->          MISO                 PB2             //触摸屏SPI总线读信号
//      MOSI      --->          MOSI                 PF11            //触摸屏SPI总线写信号
//      T_CS      --->          TCS                  PC13            //触摸屏片选控制信号
//      CLK       --->          CLK                  PB0             //触摸屏SPI总线时钟信号
**************************************************************************************************/
/* @attention
 *
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
 * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 **************************************************************************************************/
#include "touch.h"
#include "lcd.h"
#include "stdlib.h"
#include "math.h"
#include "stdint.h"

//_m_tp_dev tp_dev=
//{
//	TP_Init,
//	TP_Scan,
//	TP_Adjust,
//	0,
//	0,
// 	0,
//	0,
//	0,
//	0,
//	0,
//	0,
//	0,
//	0,
//};

// 已经过校准的屏幕参数
_m_tp_dev tp_dev =
	{
		TP_Scan,
		TP_Adjust,
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x00,
		0.087939702,
		-0.0645786226,
		0xFFF6,
		0x00FC,
		0x00,
};
// 默认为touchtype=0的数据.
// uint8_t CMD_RDX=0XD0;
// uint8_t CMD_RDY=0X90;

// 横屏
uint8_t CMD_RDX = 0X90;
uint8_t CMD_RDY = 0XD0;
/*****************************************************************************
 * @name       :void TP_Write_Byte(uint8_t num)
 * @date       :2018-08-09
 * @function   :Write a byte data to the touch screen IC with SPI bus
 * @parameters :num:Data to be written
 * @retvalue   :None
 ******************************************************************************/
void TP_Write_Byte(uint8_t num)
{
	uint8_t count = 0;
	for (count = 0; count < 8; count++)
	{
		if (num & 0x80)
			HAL_GPIO_WritePin(MOSI_GPIO_Port, MOSI_Pin, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(MOSI_GPIO_Port, MOSI_Pin, GPIO_PIN_RESET);
		num <<= 1;
		HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, GPIO_PIN_RESET);

		delay_us(1);
		HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, GPIO_PIN_SET); // 上升沿有效
	}
}

/*****************************************************************************
 * @name       :uint16_t TP_Read_AD(uint8_t CMD)
 * @date       :2018-08-09
 * @function   :Reading adc values from touch screen IC with SPI bus
 * @parameters :CMD:Read command,0xD0 for x,0x90 for y
 * @retvalue   :Read data
 ******************************************************************************/
uint16_t TP_Read_AD(uint8_t CMD)
{
	uint8_t count = 0;
	uint16_t Num = 0;
	HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, GPIO_PIN_RESET);	 // 先拉低时钟
	HAL_GPIO_WritePin(MOSI_GPIO_Port, MOSI_Pin, GPIO_PIN_RESET); // 拉低数据线
	HAL_GPIO_WritePin(T_CS_GPIO_Port, T_CS_Pin, GPIO_PIN_RESET); // 选中触摸屏IC
	TP_Write_Byte(CMD);											 // 发送命令字
	delay_us(6);												 // ADS7846的转换时间最长为6us
	HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, GPIO_PIN_RESET);
	delay_us(1);
	HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, GPIO_PIN_SET); // 给1个时钟，清除BUSY
	delay_us(1);
	HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, GPIO_PIN_RESET);
	for (count = 0; count < 16; count++) // 读出16位数据,只有高12位有效
	{
		Num <<= 1;
		HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, GPIO_PIN_RESET); // 下降沿有效
		delay_us(1);
		HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, GPIO_PIN_SET);
		if (HAL_GPIO_ReadPin(MISO_GPIO_Port, MISO_Pin))
			Num++;
	}
	Num >>= 4;												   // 只有高12位有效.
	HAL_GPIO_WritePin(T_CS_GPIO_Port, T_CS_Pin, GPIO_PIN_SET); // 释放片选
	return (Num);
	// #endif
}

#define READ_TIMES 5 // 读取次数
#define LOST_VAL 1	 // 丢弃值
/*****************************************************************************
 * @name       :uint16_t TP_Read_XOY(uint8_t xy)
 * @date       :2018-08-09
 * @function   :Read the touch screen coordinates (x or y),
								Read the READ_TIMES secondary data in succession
								and sort the data in ascending order,
								Then remove the lowest and highest number of LOST_VAL
								and take the average
 * @parameters :xy:Read command(CMD_RDX/CMD_RDY)
 * @retvalue   :Read data
******************************************************************************/
uint16_t TP_Read_XOY(uint8_t xy)
{
	uint16_t i, j;
	uint16_t buf[READ_TIMES];
	uint16_t sum = 0;
	uint16_t temp;
	for (i = 0; i < READ_TIMES; i++)
		buf[i] = TP_Read_AD(xy);
	for (i = 0; i < READ_TIMES - 1; i++) // 排序
	{
		for (j = i + 1; j < READ_TIMES; j++)
		{
			if (buf[i] > buf[j]) // 升序排列
			{
				temp = buf[i];
				buf[i] = buf[j];
				buf[j] = temp;
			}
		}
	}
	sum = 0;
	for (i = LOST_VAL; i < READ_TIMES - LOST_VAL; i++)
		sum += buf[i];
	temp = sum / (READ_TIMES - 2 * LOST_VAL);
	return temp;
}

/*****************************************************************************
 * @name       :uint8_t TP_Read_XY(uint16_t *x,uint16_t *y)
 * @date       :2018-08-09
 * @function   :Read touch screen x and y coordinates,
								The minimum value can not be less than 100
 * @parameters :x:Read x coordinate of the touch screen
								y:Read y coordinate of the touch screen
 * @retvalue   :0-fail,1-success
******************************************************************************/
uint8_t TP_Read_XY(uint16_t *x, uint16_t *y)
{
	uint16_t xtemp, ytemp;
	xtemp = TP_Read_XOY(CMD_RDX);
	ytemp = TP_Read_XOY(CMD_RDY);
	// if(xtemp<100||ytemp<100)return 0;//读数失败
	*x = xtemp;
	*y = ytemp;
	return 1; // 读数成功
}

#define ERR_RANGE 50 // 误差范围
/*****************************************************************************
 * @name       :uint8_t TP_Read_XY2(uint16_t *x,uint16_t *y)
 * @date       :2018-08-09
 * @function   :Read the touch screen coordinates twice in a row,
								and the deviation of these two times can not exceed ERR_RANGE,
								satisfy the condition, then think the reading is correct,
								otherwise the reading is wrong.
								This function can greatly improve the accuracy.
 * @parameters :x:Read x coordinate of the touch screen
								y:Read y coordinate of the touch screen
 * @retvalue   :0-fail,1-success
******************************************************************************/
uint8_t TP_Read_XY2(uint16_t *x, uint16_t *y)
{
	uint16_t x1, y1;
	uint16_t x2, y2;
	uint8_t flag;
	flag = TP_Read_XY(&x1, &y1);
	if (flag == 0)
		return (0);
	flag = TP_Read_XY(&x2, &y2);
	if (flag == 0)
		return (0);
	if (((x2 <= x1 && x1 < x2 + ERR_RANGE) || (x1 <= x2 && x2 < x1 + ERR_RANGE)) // 前后两次采样在+-50内
		&& ((y2 <= y1 && y1 < y2 + ERR_RANGE) || (y1 <= y2 && y2 < y1 + ERR_RANGE)))
	{
		*x = (x1 + x2) / 2;
		*y = (y1 + y2) / 2;
		return 1;
	}
	else
		return 0;
}

/*****************************************************************************
 * @name       :void TP_Drow_Touch_Point(uint16_t x,uint16_t y,uint16_t color)
 * @date       :2018-08-09
 * @function   :Draw a touch point,Used to calibrate
 * @parameters :x:Read x coordinate of the touch screen
								y:Read y coordinate of the touch screen
								color:the color value of the touch point
 * @retvalue   :None
******************************************************************************/
void TP_Drow_Touch_Point(uint16_t x, uint16_t y, uint16_t color)
{
	POINT_COLOR = color;
	LCD_DrawLine(x - 12, y, x + 13, y); // 横线
	LCD_DrawLine(x, y - 12, x, y + 13); // 竖线
	LCD_DrawPoint(x + 1, y + 1);
	LCD_DrawPoint(x - 1, y + 1);
	LCD_DrawPoint(x + 1, y - 1);
	LCD_DrawPoint(x - 1, y - 1);
	gui_circle(x, y, POINT_COLOR, 6, 0); // 画中心圈
}

/*****************************************************************************
 * @name       :void TP_Draw_Big_Point(uint16_t x,uint16_t y,uint16_t color)
 * @date       :2018-08-09
 * @function   :Draw a big point(2*2)
 * @parameters :x:Read x coordinate of the point
								y:Read y coordinate of the point
								color:the color value of the point
 * @retvalue   :None
******************************************************************************/
void TP_Draw_Big_Point(uint16_t x, uint16_t y, uint16_t color)
{
	POINT_COLOR = color;
	LCD_DrawPoint(x, y); // 中心点
	LCD_DrawPoint(x + 1, y);
	LCD_DrawPoint(x, y + 1);
	LCD_DrawPoint(x + 1, y + 1);
}

/*****************************************************************************
 * @name       :uint8_t TP_Scan(uint8_t tp)
 * @date       :2018-08-09
 * @function   :Scanning touch event
 * @parameters :tp:0-screen coordinate
									 1-Physical coordinates(For special occasions such as calibration)
 * @retvalue   :Current touch screen status,
								0-no touch
								1-touch
******************************************************************************/
uint8_t TP_Scan(uint8_t tp)
{
	if (HAL_GPIO_ReadPin(PEN_GPIO_Port, PEN_Pin) == 0) // 有按键按下
	{
		if (tp)
			TP_Read_XY2(&tp_dev.x, &tp_dev.y);		// 读取物理坐标
		else if (TP_Read_XY2(&tp_dev.x, &tp_dev.y)) // 读取屏幕坐标
		{
			tp_dev.x = tp_dev.xfac * tp_dev.x + tp_dev.xoff; // 将结果转换为屏幕坐标
			tp_dev.y = tp_dev.yfac * tp_dev.y + tp_dev.yoff;
		}
		if ((tp_dev.sta & TP_PRES_DOWN) == 0) // 之前没有被按下
		{
			tp_dev.sta = TP_PRES_DOWN | TP_CATH_PRES; // 按键按下
			tp_dev.x0 = tp_dev.x;					  // 记录第一次按下时的坐标
			tp_dev.y0 = tp_dev.y;
		}
	}
	else
	{
		if (tp_dev.sta & TP_PRES_DOWN) // 之前是被按下的
		{
			tp_dev.sta &= ~(1 << 7); // 标记按键松开
		}
		else // 之前就没有被按下
		{
			tp_dev.x0 = 0;
			tp_dev.y0 = 0;
			tp_dev.x = 0xffff;
			tp_dev.y = 0xffff;
		}
	}
	return tp_dev.sta & TP_PRES_DOWN; // 返回当前的触屏状态
}

// 提示字符串
const uint8_t *TP_REMIND_MSG_TBL = "Please use the stylus click the cross on the screen.The cross will always move until the screen adjustment is completed.";

/*****************************************************************************
 * @name       :void TP_Adj_Info_Show(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t x3,uint16_t y3,uint16_t fac)
 * @date       :2018-08-09
 * @function   :Display calibration results
 * @parameters :x0:the x coordinates of first calibration point
								y0:the y coordinates of first calibration point
								x1:the x coordinates of second calibration point
								y1:the y coordinates of second calibration point
								x2:the x coordinates of third calibration point
								y2:the y coordinates of third calibration point
								x3:the x coordinates of fourth calibration point
								y3:the y coordinates of fourth calibration point
								fac:calibration factor
 * @retvalue   :None
******************************************************************************/
void TP_Adj_Info_Show(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t fac)
{
	POINT_COLOR = RED;
	LCD_ShowString(40, 140, 16, "x1:", 1);
	LCD_ShowString(40 + 80, 140, 16, "y1:", 1);
	LCD_ShowString(40, 160, 16, "x2:", 1);
	LCD_ShowString(40 + 80, 160, 16, "y2:", 1);
	LCD_ShowString(40, 180, 16, "x3:", 1);
	LCD_ShowString(40 + 80, 180, 16, "y3:", 1);
	LCD_ShowString(40, 200, 16, "x4:", 1);
	LCD_ShowString(40 + 80, 200, 16, "y4:", 1);
	LCD_ShowString(40, 220, 16, "fac is:", 1);
	LCD_ShowNum(40 + 24, 140, x0, 4, 16);	   // 显示数值
	LCD_ShowNum(40 + 24 + 80, 140, y0, 4, 16); // 显示数值
	LCD_ShowNum(40 + 24, 160, x1, 4, 16);	   // 显示数值
	LCD_ShowNum(40 + 24 + 80, 160, y1, 4, 16); // 显示数值
	LCD_ShowNum(40 + 24, 180, x2, 4, 16);	   // 显示数值
	LCD_ShowNum(40 + 24 + 80, 180, y2, 4, 16); // 显示数值
	LCD_ShowNum(40 + 24, 200, x3, 4, 16);	   // 显示数值
	LCD_ShowNum(40 + 24 + 80, 200, y3, 4, 16); // 显示数值
	LCD_ShowNum(40 + 56, 220, fac, 3, 16);	   // 显示数值,该数值必须在95~105范围之内.
}

/*****************************************************************************
 * @name       :uint8_t TP_Get_Adjdata(void)
 * @date       :2018-08-09
 * @function   :Calibration touch screen and Get 4 calibration parameters
 * @parameters :None
 * @retvalue   :None
 ******************************************************************************/
void TP_Adjust(void)
{
	uint16_t pos_temp[4][2]; // 坐标缓存值
	uint8_t cnt = 0;
	uint16_t d1, d2;
	uint32_t tem1, tem2;
	double fac;
	cnt = 0;
	POINT_COLOR = BLUE;
	BACK_COLOR = WHITE;
	LCD_Clear(WHITE);  // 清屏
	POINT_COLOR = RED; // 红色
	LCD_Clear(WHITE);  // 清屏
	POINT_COLOR = BLACK;
	LCD_ShowString(10, 40, 16, "Please touch cross marks on the screen,", 1); // 显示提示信息
	LCD_ShowString(10, 56, 16, "which will display 4 times.", 1);			  // 显示提示信息

	TP_Drow_Touch_Point(20, 20, RED); // 画点1
	tp_dev.sta = 0;					  // 消除触发信号
	tp_dev.xfac = 0;				  // xfac用来标记是否校准过,所以校准之前必须清掉!以免错误
	uint16_t Timer = HAL_GetTick();
	while (1) // 如果连续5秒钟没有按下,则自动退出
	{
		tp_dev.scan(1);							 // 扫描物理坐标
		if ((tp_dev.sta & 0xc0) == TP_CATH_PRES) // 按键按下了一次(此时按键松开了.)
		{
			Timer = HAL_GetTick();	 // 重置计时器
			tp_dev.sta &= ~(1 << 6); // 标记按键已经被处理过了.

			pos_temp[cnt][0] = tp_dev.x;
			pos_temp[cnt][1] = tp_dev.y;
			cnt++;
			switch (cnt)
			{
			case 1:
				TP_Drow_Touch_Point(20, 20, WHITE);				 // 清除点1
				TP_Drow_Touch_Point(lcddev.width - 20, 20, RED); // 画点2
				break;
			case 2:
				TP_Drow_Touch_Point(lcddev.width - 20, 20, WHITE); // 清除点2
				TP_Drow_Touch_Point(20, lcddev.height - 20, RED);  // 画点3
				break;
			case 3:
				TP_Drow_Touch_Point(20, lcddev.height - 20, WHITE);				 // 清除点3
				TP_Drow_Touch_Point(lcddev.width - 20, lcddev.height - 20, RED); // 画点4
				break;
			case 4: // 全部四个点已经得到
				// 对边相等
				tem1 = abs(pos_temp[0][0] - pos_temp[1][0]); // x1-x2
				tem2 = abs(pos_temp[0][1] - pos_temp[1][1]); // y1-y2
				tem1 *= tem1;
				tem2 *= tem2;
				d1 = sqrt(tem1 + tem2); // 得到1,2的距离

				tem1 = abs(pos_temp[2][0] - pos_temp[3][0]); // x3-x4
				tem2 = abs(pos_temp[2][1] - pos_temp[3][1]); // y3-y4
				tem1 *= tem1;
				tem2 *= tem2;
				d2 = sqrt(tem1 + tem2); // 得到3,4的距离
				fac = (float)d1 / d2;
				if (fac < 0.95 || fac > 1.05 || d1 == 0 || d2 == 0) // 不合格
				{
					cnt = 0;
					TP_Drow_Touch_Point(lcddev.width - 20, lcddev.height - 20, WHITE);																							 // 清除点4
					TP_Drow_Touch_Point(20, 20, RED);																															 // 画点1
					TP_Adj_Info_Show(pos_temp[0][0], pos_temp[0][1], pos_temp[1][0], pos_temp[1][1], pos_temp[2][0], pos_temp[2][1], pos_temp[3][0], pos_temp[3][1], fac * 100); // 显示数据
					continue;
				}
				tem1 = abs(pos_temp[0][0] - pos_temp[2][0]); // x1-x3
				tem2 = abs(pos_temp[0][1] - pos_temp[2][1]); // y1-y3
				tem1 *= tem1;
				tem2 *= tem2;
				d1 = sqrt(tem1 + tem2); // 得到1,3的距离

				tem1 = abs(pos_temp[1][0] - pos_temp[3][0]); // x2-x4
				tem2 = abs(pos_temp[1][1] - pos_temp[3][1]); // y2-y4
				tem1 *= tem1;
				tem2 *= tem2;
				d2 = sqrt(tem1 + tem2); // 得到2,4的距离
				fac = (float)d1 / d2;
				if (fac < 0.95 || fac > 1.05) // 不合格
				{
					cnt = 0;
					TP_Drow_Touch_Point(lcddev.width - 20, lcddev.height - 20, WHITE);																							 // 清除点4
					TP_Drow_Touch_Point(20, 20, RED);																															 // 画点1
					TP_Adj_Info_Show(pos_temp[0][0], pos_temp[0][1], pos_temp[1][0], pos_temp[1][1], pos_temp[2][0], pos_temp[2][1], pos_temp[3][0], pos_temp[3][1], fac * 100); // 显示数据
					continue;
				} // 正确了

				// 对角线相等
				tem1 = abs(pos_temp[1][0] - pos_temp[2][0]); // x1-x3
				tem2 = abs(pos_temp[1][1] - pos_temp[2][1]); // y1-y3
				tem1 *= tem1;
				tem2 *= tem2;
				d1 = sqrt(tem1 + tem2); // 得到1,4的距离

				tem1 = abs(pos_temp[0][0] - pos_temp[3][0]); // x2-x4
				tem2 = abs(pos_temp[0][1] - pos_temp[3][1]); // y2-y4
				tem1 *= tem1;
				tem2 *= tem2;
				d2 = sqrt(tem1 + tem2); // 得到2,3的距离
				fac = (float)d1 / d2;
				if (fac < 0.95 || fac > 1.05) // 不合格
				{
					cnt = 0;
					TP_Drow_Touch_Point(lcddev.width - 20, lcddev.height - 20, WHITE);																							 // 清除点4
					TP_Drow_Touch_Point(20, 20, RED);																															 // 画点1
					TP_Adj_Info_Show(pos_temp[0][0], pos_temp[0][1], pos_temp[1][0], pos_temp[1][1], pos_temp[2][0], pos_temp[2][1], pos_temp[3][0], pos_temp[3][1], fac * 100); // 显示数据
					continue;
				} // 正确了
				// 计算结果
				tp_dev.xfac = (float)(lcddev.width - 40) / (pos_temp[1][0] - pos_temp[0][0]);		// 得到xfac
				tp_dev.xoff = (lcddev.width - tp_dev.xfac * (pos_temp[1][0] + pos_temp[0][0])) / 2; // 得到xoff

				tp_dev.yfac = (float)(lcddev.height - 40) / (pos_temp[2][1] - pos_temp[0][1]);		 // 得到yfac
				tp_dev.yoff = (lcddev.height - tp_dev.yfac * (pos_temp[2][1] + pos_temp[0][1])) / 2; // 得到yoff
				if (abs(tp_dev.xfac) > 2 || abs(tp_dev.yfac) > 2)									 // 触屏和预设的相反了.
				{
					cnt = 0;
					TP_Drow_Touch_Point(lcddev.width - 20, lcddev.height - 20, WHITE); // 清除点4
					TP_Drow_Touch_Point(20, 20, RED);								   // 画点1
					LCD_ShowString(40, 26, 16, "TP Need readjust!", 1);
					tp_dev.touchtype = !tp_dev.touchtype; // 修改触屏类型.
					if (tp_dev.touchtype)				  // X,Y方向与屏幕相反
					{
						CMD_RDX = 0X90;
						CMD_RDY = 0XD0;
					}
					else // X,Y方向与屏幕相同
					{
						CMD_RDX = 0XD0;
						CMD_RDY = 0X90;
					}
					continue;
				}
				POINT_COLOR = BLUE;
				LCD_Clear(WHITE);										   // 清屏
				LCD_ShowString(35, 110, 16, "Touch Screen Adjust OK!", 1); // 校正完成
				HAL_Delay(300);
				TP_Save_Adjdata();
				// LCD_Clear(WHITE);//清屏
				ui_load_scr_animation(&guider_ui, &guider_ui.main_page, guider_ui.main_page_del,
									  &guider_ui.setting_screen_del, setup_scr_main_page, LV_SCR_LOAD_ANIM_OVER_RIGHT, 300, 50, false, true);
				return; // 校正完成
			}
		}
		HAL_Delay(10);
		if (HAL_GetTick() - Timer >= 5000)
			break;
	}
	ui_load_scr_animation(&guider_ui, &guider_ui.main_page, guider_ui.main_page_del,
						  &guider_ui.setting_screen_del, setup_scr_main_page, LV_SCR_LOAD_ANIM_OVER_RIGHT, 300, 50, false, true);
}

// 保存校准数据
#define SAVE_ADDR_BASE 30
void TP_Save_Adjdata()
{
	int temp;
	// 保存校正结果
	// x校准参数的符号位
	if (tp_dev.xfac > 0)
		eeprom_write_data(0x2B, SAVE_ADDR_BASE, 1);
	else
		eeprom_write_data(0x2D, SAVE_ADDR_BASE, 1);
	temp = fabs(tp_dev.xfac * 100000000); // 保存x校正因素
	eeprom_write_data(temp, SAVE_ADDR_BASE + 1, 4);
	// y校准参数的符号位
	if (tp_dev.yfac > 0)
		eeprom_write_data(0x2B, SAVE_ADDR_BASE + 5, 1);
	else
		eeprom_write_data(0x2D, SAVE_ADDR_BASE + 5, 1);
	temp = fabs(tp_dev.yfac * 100000000); // 保存y校正因素
	eeprom_write_data(temp, SAVE_ADDR_BASE + 6, 4);
	// 保存x偏移量
	eeprom_write_data(tp_dev.xoff, SAVE_ADDR_BASE + 10, 2);
	// 保存y偏移量
	eeprom_write_data(tp_dev.yoff, SAVE_ADDR_BASE + 12, 2);
	// 保存触屏类型
	eeprom_write_data(tp_dev.touchtype, SAVE_ADDR_BASE + 14, 1);
	temp = 0X0A; // 标记校准过了
	eeprom_write_data(temp, SAVE_ADDR_BASE + 15, 1);
}

uint8_t TP_Get_Adjdata(void)
{
	uint32_t tempfac, sign;
	eeprom_read_data(&tempfac, SAVE_ADDR_BASE + 15, 1); // 读取标记字,看是否校准过！
	if (tempfac == 0X0A)								// 触摸屏已经校准过了
	{
		// x校准参数的符号位
		eeprom_read_data(&sign, SAVE_ADDR_BASE, 1);

		eeprom_read_data(&tempfac, SAVE_ADDR_BASE + 1, 4);
		tp_dev.xfac = ((float)tempfac / 100000000) * (sign == 0x2B ? 1 : -1); // 得到x校准参数

		// y校准参数的符号位
		eeprom_read_data(&sign, SAVE_ADDR_BASE + 5, 1);

		eeprom_read_data(&tempfac, SAVE_ADDR_BASE + 6, 4);
		tp_dev.yfac = ((float)tempfac / 100000000) * (sign == 0x2B ? 1 : -1); // 得到y校准参数
		// 得到x偏移量
		eeprom_read_data(&tempfac, SAVE_ADDR_BASE + 10, 2);
		tp_dev.xoff = tempfac;
		// 得到y偏移量
		eeprom_read_data(&tempfac, SAVE_ADDR_BASE + 12, 2);
		tp_dev.yoff = tempfac;
		eeprom_read_data(&tempfac, SAVE_ADDR_BASE + 14, 1); // 读取触屏类型标记
		tp_dev.touchtype = tempfac;
		if (tp_dev.touchtype) // X,Y方向与屏幕相反
		{
			CMD_RDX = 0X90;
			CMD_RDY = 0XD0;
		}
		else // X,Y方向与屏幕相同
		{
			CMD_RDX = 0XD0;
			CMD_RDY = 0X90;
		}
		return 1;
	}
	return 0;
}
