/*
 * @Descripttion: 
 * @version: 
 * @Author: Jeremy
 * @Date: 2021-08-09 14:23:55
 * @LastEditors: Jeremy
 * @LastEditTime: 2021-08-10 00:00:33
 */
/*
 * @LastEditTime: 2021-08-09 13:40:08
 */
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "custom_dial_head.h"
#include "cJSON/cJSON.h"

uint8_t dial_data[4096];
uint8_t obj[40]; 
#define LV_HOR_RES_MAX 320
#define LV_VER_RES_MAX 320


custom_dial_image     main10_watch_bg =  {//背景
  .type= dial_type_image,
  .x= 0,//左上角x坐标
  .y= 0,//左上角y坐标
  .img_addr= main_61_bg_320x320_png,//图片nandflash相对地址
};
custom_dial_text      main10_watch_month = {//文本 月
  .type = dial_type_text,
  .data_type = dial_data_text_month  ,
  .x =  125 ,
  .y =  16,        
  .text_width = 35,
  .text_rgb[0] = 0xff,
  .text_rgb[1] = 0xff,
  .text_rgb[2] = 0xff,
  .text_align = LV_LABEL_ALIGN_LEFT,
  .text_size = dial_data_16x16_ext, 
};
custom_dial_text      main10_watch_date = {//文本 日
  .type = dial_type_text,
  .data_type = dial_data_text_day  ,
  .x =  151 ,
  .y =  16,        
  .text_width = 35,
  .text_rgb[0] = 0xff,
  .text_rgb[1] = 0xff,
  .text_rgb[2] = 0xff,
  .text_align = LV_LABEL_ALIGN_LEFT,
  .text_size = dial_data_16x16_ext, 
};
custom_dial_text      main10_watch_separator = {//文本 日月的斜杠
  .type = dial_type_text,
  .data_type = dial_data_text_custom  ,
  .x =  143  ,
  .y =  16,        
  .text_width = 35,
  .text_rgb[0] = 0xff,
  .text_rgb[1] = 0xff,
  .text_rgb[2] = 0xff,
  .text_align = LV_LABEL_ALIGN_LEFT,
  .text_size = dial_data_16x16_ext,
  .text_custom[0] = '/',
  .text_custom[1] = '\n',
};
custom_dial_text      main10_watch_week = {//文本 星期
  .type = dial_type_text,
  .data_type = dial_data_text_week  ,
  .x =  174  ,
  .y =  16,        
  .text_width = 50,
  .text_rgb[0] = 0xff,
  .text_rgb[1] = 0xff,
  .text_rgb[2] = 0xff,
  .text_align = LV_LABEL_ALIGN_LEFT,
  .text_size = dial_data_16x16_ext,
};
custom_dial_text      main10_watch_power = {//文本 电池电量
  .type = dial_type_text,
  .data_type = dial_data_text_power  ,
  .x =  34,
  .y =  16,        
  .text_width = 35,
  .text_rgb[0] = 0xff,
  .text_rgb[1] = 0xff,
  .text_rgb[2] = 0xff,
  .text_align = LV_LABEL_ALIGN_CENTER,
  .text_size = dial_data_16x16_ext,
};
custom_dial_more_img  main10_watch_hour_high = {//多图 时
  .type= dial_type_more_img,
  .x= 28,//左上角x坐标
  .y= 48,//左上角y坐标
  .img_addr[0]= main_61_num_0_58x88_png,//图片nandflash相对地址
  .img_addr[1]= main_61_num_1_58x88_png,//图片nandflash相对地址
  .img_addr[2]= main_61_num_2_58x88_png,//图片nandflash相对地址
  .img_addr[3]= main_61_num_3_58x88_png,//图片nandflash相对地址
  .img_addr[4]= main_61_num_4_58x88_png,//图片nandflash相对地址
  .img_addr[5]= main_61_num_5_58x88_png,//图片nandflash相对地址
  .img_addr[6]= main_61_num_6_58x88_png,//图片nandflash相对地址
  .img_addr[7]= main_61_num_7_58x88_png,//图片nandflash相对地址
  .img_addr[8]= main_61_num_8_58x88_png,//图片nandflash相对地址
  .img_addr[9]= main_61_num_9_58x88_png,//图片nandflash相对地址
  .data_type = dial_data_hour_high,
};
custom_dial_more_img  main10_watch_hour_low = {//多图 时
  .type= dial_type_more_img,
  .x= 90,//左上角x坐标
  .y= 48,//左上角y坐标
  .img_addr[0]= main_61_num_0_58x88_png,//图片nandflash相对地址
  .img_addr[1]= main_61_num_1_58x88_png,//图片nandflash相对地址
  .img_addr[2]= main_61_num_2_58x88_png,//图片nandflash相对地址
  .img_addr[3]= main_61_num_3_58x88_png,//图片nandflash相对地址
  .img_addr[4]= main_61_num_4_58x88_png,//图片nandflash相对地址
  .img_addr[5]= main_61_num_5_58x88_png,//图片nandflash相对地址
  .img_addr[6]= main_61_num_6_58x88_png,//图片nandflash相对地址
  .img_addr[7]= main_61_num_7_58x88_png,//图片nandflash相对地址
  .img_addr[8]= main_61_num_8_58x88_png,//图片nandflash相对地址
  .img_addr[9]= main_61_num_9_58x88_png,//图片nandflash相对地址
  .data_type = dial_data_hour_low,
};
custom_dial_more_img  main10_watch_min_high = {//多图 分
  .type= dial_type_more_img,
  .x= 172,//左上角x坐标
  .y= 48,//左上角y坐标
  .img_addr[0]= main_61_num_0_58x88_png,//图片nandflash相对地址
  .img_addr[1]= main_61_num_1_58x88_png,//图片nandflash相对地址
  .img_addr[2]= main_61_num_2_58x88_png,//图片nandflash相对地址
  .img_addr[3]= main_61_num_3_58x88_png,//图片nandflash相对地址
  .img_addr[4]= main_61_num_4_58x88_png,//图片nandflash相对地址
  .img_addr[5]= main_61_num_5_58x88_png,//图片nandflash相对地址
  .img_addr[6]= main_61_num_6_58x88_png,//图片nandflash相对地址
  .img_addr[7]= main_61_num_7_58x88_png,//图片nandflash相对地址
  .img_addr[8]= main_61_num_8_58x88_png,//图片nandflash相对地址
  .img_addr[9]= main_61_num_9_58x88_png,//图片nandflash相对地址
  .data_type = dial_data_min_high,
};
custom_dial_more_img  main10_watch_min_low = {//多图 分
  .type= dial_type_more_img,
  .x= 234,//左上角x坐标
  .y= 48,//左上角y坐标
  .img_addr[0]= main_61_num_0_58x88_png,//图片nandflash相对地址
  .img_addr[1]= main_61_num_1_58x88_png,//图片nandflash相对地址
  .img_addr[2]= main_61_num_2_58x88_png,//图片nandflash相对地址
  .img_addr[3]= main_61_num_3_58x88_png,//图片nandflash相对地址
  .img_addr[4]= main_61_num_4_58x88_png,//图片nandflash相对地址
  .img_addr[5]= main_61_num_5_58x88_png,//图片nandflash相对地址
  .img_addr[6]= main_61_num_6_58x88_png,//图片nandflash相对地址
  .img_addr[7]= main_61_num_7_58x88_png,//图片nandflash相对地址
  .img_addr[8]= main_61_num_8_58x88_png,//图片nandflash相对地址
  .img_addr[9]= main_61_num_9_58x88_png,//图片nandflash相对地址
  .data_type = dial_data_min_low,
};
custom_dial_image     main10_watch_maohao =  {//单图 冒号
  .type= dial_type_image,
  .x= 152,//左上角x坐标
  .y= 67,//左上角y坐标
  .img_addr= main_61_volon_png,//图片nandflash相对地址
};
custom_dial_more_img  main10_watch_weather_icon = {//多图 天气
  .type= dial_type_image,
  .x= 247,//左上角x坐标
  .y= 16,//左上角y坐标
  .img_addr[0] = main_61_weather_Clear_16x16_png         ,//图片nandflash相对地址
  .img_addr[1] = main_61_weather_cloudy_16x16_png        ,//图片nandflash相对地址
  .img_addr[2] = main_61_weather_gloomy_16x16_png      ,//图片nandflash相对地址
  .img_addr[3] = main_61_weather_Drizzle_16x16_png       ,//图片nandflash相对地址
  .img_addr[4] = main_61_weather_moderate_rain_16x16_png  ,//图片nandflash相对地址
  .img_addr[5] = main_61_weather_thunderstorm_16x16_png  ,//图片nandflash相对地址
  .img_addr[6] = main_61_weather_heavy_rain_16x16_png  ,//图片nandflash相对地址
  .img_addr[7] = main_61_weather_sleet_16x16_png ,//图片nandflash相对地址
  .img_addr[8] = main_61_weather_light_snow_16x16_png  ,//图片nandflash相对地址
  .img_addr[9] = main_61_weather_moderate_snow_16x16_png        ,//图片nandflash相对地址
  .img_addr[10]= main_61_weather_heavy_snow_16x16_png ,//图片nandflash相对地址 
  .data_type = dial_data_img_weather,
};
custom_dial_text      main10_watch_text_icon = {//文本 天气
  .type = dial_type_text,
  .data_type = dial_data_text_now_tem  ,
  .x =  269  ,
  .y =  16,        
  .text_width = 35,
  .text_rgb[0] = 0xff,
  .text_rgb[1] = 0xff,
  .text_rgb[2] = 0xff,
  .text_align = LV_LABEL_ALIGN_CENTER,
  .text_size = dial_data_16x16_ext,
};
custom_dial_text      main10_watch_text_heart = {//文本 心率
  .type = dial_type_text,
  .data_type = dial_data_text_heart  ,
  .x =  103  ,
  .y =  270,        
  .text_width = 42,
  .text_rgb[0] = 0xff,
  .text_rgb[1] = 0xff,
  .text_rgb[2] = 0xff,
  .text_align = LV_LABEL_ALIGN_CENTER,
  .text_size = dial_data_24x24_ext,
};
custom_dial_text      main10_watch_text_step = {//文本 步数
  .type = dial_type_text,
  .data_type = dial_data_text_step  ,
  .x =  249  ,
  .y =  207,        
  .text_width = 55,
  .text_rgb[0] = 0xff,
  .text_rgb[1] = 0xff,
  .text_rgb[2] = 0xff,
  .text_align = LV_LABEL_ALIGN_CENTER,
  .text_size = dial_data_16x16_ext,
};
custom_dial_text      main10_watch_text_kal = {//文本 卡路里
  .type = dial_type_text,
  .data_type = dial_data_text_kal  ,
  .x =  249  ,
  .y =  288,        
  .text_width = 55,
  .text_rgb[0] = 0xff,
  .text_rgb[1] = 0xff,
  .text_rgb[2] = 0xff,
  .text_align = LV_LABEL_ALIGN_CENTER,
  .text_size = dial_data_16x16_ext,
};


uint8_t get_dial_type_size(uint8_t type)
{
    if (type == dial_type_image)	      	 return sizeof(custom_dial_image);
    else if (type == dial_type_pointer) 	 return sizeof(custom_dial_pointer);
    else if (type == dial_type_arc_bar) 	 return sizeof(custom_dial_arc_bar);
    else if (type == dial_type_chart_bar)    return sizeof(custom_dial_chart_bar);
    else if (type == dial_type_text)	     return sizeof(custom_dial_text);
    else if (type == dial_type_more_img) 	 return sizeof(custom_dial_more_img);
    else return 0;
}


 void main10_data_init(void)
{ 
	uint8_t* memory = dial_data; 
	obj[0] = dial_type_image;
	obj[1] = dial_type_more_img;
	obj[2] = dial_type_more_img;
	obj[3] = dial_type_more_img;
	obj[4] = dial_type_more_img; 
	obj[5] = dial_type_image; 
	obj[6] = dial_type_text; 
	obj[7] = dial_type_text; 
	obj[8] = dial_type_text; 
	obj[9] = dial_type_text; 
	obj[10] = dial_type_text; 
	obj[11] = dial_type_text; 
	obj[12] = dial_type_text; 
	obj[13] = dial_type_text; 
	obj[14] = dial_type_text; 
	obj[15] = dial_type_more_img; 

	
	memcpy(memory,&main10_watch_bg,get_dial_type_size(dial_type_image)); 
	memory += get_dial_type_size(dial_type_image);

	memcpy(memory,&main10_watch_hour_high,get_dial_type_size(dial_type_more_img)); 
	memory += get_dial_type_size(dial_type_more_img);

	memcpy(memory,&main10_watch_hour_low,get_dial_type_size(dial_type_more_img)); 
	memory += get_dial_type_size(dial_type_more_img);

	memcpy(memory,&main10_watch_min_high,get_dial_type_size(dial_type_more_img)); 
	memory += get_dial_type_size(dial_type_more_img); 

	memcpy(memory,&main10_watch_min_low,get_dial_type_size(dial_type_more_img)); 
	memory += get_dial_type_size(dial_type_more_img); 

  memcpy(memory,&main10_watch_maohao,get_dial_type_size(dial_type_image)); 
	memory += get_dial_type_size(dial_type_image); 

  memcpy(memory,&main10_watch_month,get_dial_type_size(dial_type_text)); 
	memory += get_dial_type_size(dial_type_text); 
  memcpy(memory,&main10_watch_date,get_dial_type_size(dial_type_text)); 
	memory += get_dial_type_size(dial_type_text); 
  memcpy(memory,&main10_watch_separator,get_dial_type_size(dial_type_text)); 
	memory += get_dial_type_size(dial_type_text); 

  memcpy(memory,&main10_watch_text_icon,get_dial_type_size(dial_type_text)); 
	memory += get_dial_type_size(dial_type_text); 
  memcpy(memory,&main10_watch_text_heart,get_dial_type_size(dial_type_text)); 
	memory += get_dial_type_size(dial_type_text); 
  memcpy(memory,&main10_watch_text_step,get_dial_type_size(dial_type_text)); 
	memory += get_dial_type_size(dial_type_text); 
  memcpy(memory,&main10_watch_text_kal,get_dial_type_size(dial_type_text)); 
	memory += get_dial_type_size(dial_type_text); 

  memcpy(memory,&main10_watch_week,get_dial_type_size(dial_type_text)); 
	memory += get_dial_type_size(dial_type_text); 
  memcpy(memory,&main10_watch_power,get_dial_type_size(dial_type_text)); 
	memory += get_dial_type_size(dial_type_text); 
  
  memcpy(memory,&main10_watch_weather_icon,get_dial_type_size(dial_type_more_img)); 
	memory += get_dial_type_size(dial_type_more_img); 
}


 char *message = 
"{                              \
    \"name\":\"mculover666\",   \
    \"age\": 22,                \
    \"weight\": 55.5,           \
    \"address\":                \
        {                       \
            \"country\": \"China\",\
            \"zip-code\": 111111\
        },                      \
    \"skill\": [\"c\", \"Java\", \"Python\"],\
    \"student\": false          \
}";



int main()
{
  printf("Version: %s\n", cJSON_Version());
  cJSON* cjson_test = NULL;
  cJSON* cjson_name = NULL;
  cJSON* cjson_age = NULL;
  cJSON* cjson_weight = NULL;
  cJSON* cjson_address = NULL;
  cJSON* cjson_address_country = NULL;
  cJSON* cjson_address_zipcode = NULL;
  cJSON* cjson_skill = NULL;
  cJSON* cjson_student = NULL;
  int    skill_array_size = 0, i = 0;
  cJSON* cjson_skill_item = NULL;

  /* 解析整段JSO数据 */
  cjson_test = cJSON_Parse(message);
  if(cjson_test == NULL)
  {
      printf("parse fail.\n");
      return -1;
  }

  /* 依次根据名称提取JSON数据（键值对） */
  cjson_name = cJSON_GetObjectItem(cjson_test, "name");
  cjson_age = cJSON_GetObjectItem(cjson_test, "age");
  cjson_weight = cJSON_GetObjectItem(cjson_test, "weight");

  printf("name: %s\n", cjson_name->valuestring);
  printf("age:%d\n", cjson_age->valueint);
  printf("weight:%.1f\n", cjson_weight->valuedouble);

  /* 解析嵌套json数据 */
  cjson_address = cJSON_GetObjectItem(cjson_test, "address");
  cjson_address_country = cJSON_GetObjectItem(cjson_address, "country");
  cjson_address_zipcode = cJSON_GetObjectItem(cjson_address, "zip-code");
  printf("address-country:%s\naddress-zipcode:%d\n", cjson_address_country->valuestring, cjson_address_zipcode->valueint);

  /* 解析数组 */
  cjson_skill = cJSON_GetObjectItem(cjson_test, "skill");
  skill_array_size = cJSON_GetArraySize(cjson_skill);
  printf("skill:[");
  for(i = 0; i < skill_array_size; i++)
  {
      cjson_skill_item = cJSON_GetArrayItem(cjson_skill, i);
      printf("%s,", cjson_skill_item->valuestring);
  }
  printf("\b]\n");

  /* 解析布尔型数据 */
  cjson_student = cJSON_GetObjectItem(cjson_test, "student");
  if(cjson_student->valueint == 0)
  {
      printf("student: false\n");
  }
  else
  {
      printf("student:error\n");
  }

  char read_json[65535] = {0};
  char *ch;
  ch = read_json;
  FILE *re = NULL; 
  re = fopen("dial_image_example.txt","r");
  *ch=fgetc(re);
  int num = 0;
  while( *ch != '}'){
      ch++;
      *ch=fgetc(re); 
      num++;
  }
  printf("\nnum = %d\n",num);
  printf("%s\n\n",read_json);
  fclose(re);


  cJSON* cjson_mytest = NULL;
  cJSON* cjson_names = NULL;
  cJSON* cjson_num = NULL; 
  cJSON* cjson_sites = NULL; 
  cJSON* cjson_sites_item = NULL; 


  cjson_mytest = cJSON_Parse(read_json);
  if(cjson_mytest == NULL)
  {
      printf("parse fail.\n"); 
  }
  cjson_names = cJSON_GetObjectItem(cjson_mytest, "name");
  cjson_num = cJSON_GetObjectItem(cjson_mytest, "num");
  cjson_sites = cJSON_GetObjectItem(cjson_mytest, "sites");
  skill_array_size = cJSON_GetArraySize(cjson_sites);
  for(i = 0; i < skill_array_size; i++)
  {
      cjson_sites_item = cJSON_GetArrayItem(cjson_sites, i);
      printf("%s ,", cjson_sites_item->valuestring);
  }


  printf("\nname = %s\n",cjson_names->valuestring);
  printf("num  = %d\n",cjson_num->valueint); 
    



  uint8_t crc8[8] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
  uint8_t head_bin4[4] = { 0x00,0x00,0xa0,0x06};


  main10_data_init();
  printf("\nhello world\n");

  FILE *fp = NULL; 
  // fp = fopen("head_bin4.bin", "w+");
  // fwrite(&head_bin4,sizeof(head_bin4),1,fp);  
  // fclose(fp);

  // fp = fopen("password.bin", "w+");
  // fwrite(&crc8,sizeof(crc8),1,fp);  
  // fclose(fp);
 
  // fp = fopen("obj.bin", "w+");
  // fwrite(&obj,sizeof(obj),1,fp);  
  // fclose(fp);

  // fp = fopen("obj_data.bin", "w+");
  // fwrite(&dial_data,sizeof(dial_data),1,fp);  
  // fclose(fp);
  
  fp = fopen("all.bin", "w+");
  fwrite(&head_bin4,sizeof(head_bin4),1,fp);  
  fwrite(&crc8,sizeof(crc8),1,fp);  
  fwrite(&obj,sizeof(obj),1,fp);  
  fwrite(&dial_data,sizeof(dial_data),1,fp);  
  fclose(fp);

  



  
}

























