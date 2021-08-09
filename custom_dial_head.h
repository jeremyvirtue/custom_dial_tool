#ifndef __CUSTOM_DIAL_HEAD_H
#define __CUSTOM_DIAL_HEAD_H

#include "stdint.h"


struct _custom_dial_image//纯图片
{
	uint8_t type;
	uint16_t x;//左上角x坐标
	uint16_t y;//左上角y坐标
	uint32_t img_addr;//图片nandflash相对地址
};
typedef struct _custom_dial_image custom_dial_image;

struct _custom_dial_pointer//指针类型
{
	uint8_t  type;
	uint8_t  data_type;//指针数据类型
	uint16_t x;   //左上角x坐标
	uint16_t y;   //左上角y坐标
	uint32_t img_addr;    //图片nandflash相对地址
	uint16_t img_heigth;  //图片高度
	uint16_t img_width;   //图片宽度
	uint16_t start_arc;   //指针开始角度
	uint16_t end_arc;     //指针结束角度
	uint16_t rotation_center_x;//指针相对旋转坐标x
	uint16_t rotation_center_y;//指针相对旋转坐标y

};
typedef struct _custom_dial_pointer custom_dial_pointer;

struct _custom_dial_arc_bar { //圆形进度条
	uint8_t  type;
	uint8_t  data_type;//数据类型
	uint16_t x;//左上角x坐标
	uint16_t y;//左上角y坐标
	uint16_t width;     //圆弧宽度
	uint16_t heigth;    //圆弧高度
	uint8_t  bar_rgb[3];  //rgb
	uint8_t  radius;      //半径
	uint16_t start_arc;   //开始角度
	uint16_t end_arc;     //结束角度
};
typedef struct _custom_dial_arc_bar custom_dial_arc_bar;

//条形进度条
struct _custom_dial_chart_bar
{
	uint8_t type;
	uint8_t data_type;//数据类型
	uint16_t x;//左上角x坐标
	uint16_t y;//左上角y坐标
	uint16_t width;     //条形宽度
	uint16_t heigth;    //条形高度
	uint8_t  bar_rgb[3];  //rgb
};
typedef struct _custom_dial_chart_bar custom_dial_chart_bar;

//表盘文本
struct _custom_dial_text
{
	uint8_t  type;
	uint8_t  data_type;  //数据类型
	uint16_t x;          //左上角x坐标
	uint16_t y;          //左上角y坐标
	uint8_t  text_width; //文本宽度
	uint8_t  text_rgb[3];//字体RGB
	uint8_t  text_align; //对齐方式
	uint8_t  text_size;  //字体大小
	uint8_t  text_custom[20];//自定义文本
};
typedef struct _custom_dial_text custom_dial_text;

//多图
struct _custom_dial_more_img {
	uint8_t type;
	uint8_t data_type;  //数据类型
	uint16_t x;         //左上角x坐标
	uint16_t y;         //左上角y坐标 
	uint32_t img_addr[20];    //图片nandflash相对地址

};
typedef struct _custom_dial_more_img custom_dial_more_img;

//
enum _enum_custom_dial_type {
	dial_type_null = 0,
	dial_type_image,
	dial_type_pointer,
	dial_type_arc_bar,
	dial_type_chart_bar,
	dial_type_text,
	dial_type_more_img,
};
typedef enum _enum_custom_dial_type enum_custom_dial_type;

enum _enum_custom_dial_data_pointer {//指针数据类型
	dial_data_pointer_null,
	dial_data_hour_pointer,
	dial_data_min_pointer,
	dial_data_sec_pointer,

};
typedef enum _enum_custom_dial_data_pointer enum_custom_dial_data_pointer;

enum _enum_custom_dial_data_more_img {//多图数据类型
	dial_data_more_img_null,

	dial_data_hour_high,	//时钟高位
	dial_data_hour_low,   //时钟低位
	dial_data_min_high,		//分钟高位
	dial_data_min_low,		//分钟低位 
	dial_data_img_gif,		//gif

	dial_data_img_weather,

};
typedef enum _enum_custom_dial_data_more_img enum_custom_dial_data_more_img;



enum _enum_custom_text_data//文本数据类型
{
	dial_data_text_null = 0,
	dial_data_text_hour_high,	//时钟高位
	dial_data_text_hour_low,   //时钟低位
	dial_data_text_min_high,		//分钟高位
	dial_data_text_min_low,		//分钟低位 
	dial_data_text_heart,//心率
	dial_data_text_year,//年（数字）
	dial_data_text_month,//月 01 02 12（个位前面有个0）
	dial_data_text_day,//日 01 01 12（个位前面有个0）
	dial_data_text_week,//仅支持英文 MON FRI SUN...
	dial_data_text_week_lanuguage,//支持多语言 仅支持20 24 30文本大小 日 一 二 三 ...
	dial_data_text_high_tem,//最大温度 （个位前面有个0） oC/oF(单位根据当前状态)
	dial_data_text_low_tem,//最小温度 （个位前面有个0） oC/oF(单位根据当前状态)
	dial_data_text_now_tem,//当前温度 （个位前面有个0） oC/oF(单位根据当前状态)
	dial_data_text_step,	 //当前步数
	dial_data_text_sleep,  //睡眠时间
	dial_data_text_run_time, //运动时间
	dial_data_text_kal,			//卡路里
	dial_data_text_power,			//当前电量 数字 后面加个%
	dial_data_text_custom,//自定义文本 20个char大小

};
typedef enum _enum_custom_text_data enum_custom_text_data;

enum _enum_custom_text_size//文本类型大小
{
	dial_data_text_size_null = 0,

	dial_data_16x16_ext,//不支持多语言
	dial_data_20x20_ext,
	dial_data_24x24_ext,
	dial_data_30x30_ext,
	dial_data_40x40_ext,//不支持多语言
	dial_data_50x50_ext,//不支持多语言
	dial_data_60x60_ext,//不支持多语言
	dial_data_80x80_ext,//不支持多语言
};
typedef enum _enum_custom_text_size enum_custom_text_size;















#endif
