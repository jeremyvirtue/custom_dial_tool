/*
 * @Descripttion: 
 * @version: 
 * @Author: Jeremy
 * @Date: 2021-08-09 14:23:55
 * @LastEditors: Jeremy
 * @LastEditTime: 2021-08-13 17:46:45
 */
/*
 * @LastEditTime: 2021-08-09 13:40:08
 */
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "custom_dial_head.h"
#include "cJSON/cJSON.h"

uint8_t dial_data[4096];
uint8_t obj_type[40]; 
#define LV_HOR_RES_MAX 320
#define LV_VER_RES_MAX 320

uint8_t get_dial_type_size(uint8_t type)
{
	if(type == dial_type_image)						return sizeof(custom_dial_image);
	else if(type == dial_type_pointer) 		return sizeof(custom_dial_pointer);
	else if(type == dial_type_arc_bar) 		return sizeof(custom_dial_arc_bar);
	else if(type == dial_type_chart_bar)  return sizeof(custom_dial_chart_bar);
	else if(type == dial_type_text)			  return sizeof(custom_dial_text);
	else if(type == dial_type_more_img) 	return sizeof(custom_dial_more_img);
	else return 0;
}


const custom_dial_more_img main9_watch_bg = {
  .type= dial_type_image,
  .x= 0,//左上角x坐标
  .y= 0,//左上角y坐标
  .img_addr[0] = main_30_001_320x320_png ,//图片nandflash相对地址
  .img_addr[1] = main_30_002_320x320_png ,//图片nandflash相对地址
  .img_addr[2] = main_30_003_320x320_png ,//图片nandflash相对地址
  .img_addr[3] = main_30_004_320x320_png ,//图片nandflash相对地址
  .img_addr[4] = main_30_005_320x320_png ,//图片nandflash相对地址
  .img_addr[5] = main_30_006_320x320_png ,//图片nandflash相对地址
  .img_addr[6] = main_30_007_320x320_png ,//图片nandflash相对地址
  .img_addr[7] = main_30_008_320x320_png ,//图片nandflash相对地址
  .img_addr[8] = main_30_009_320x320_png ,//图片nandflash相对地址
  .img_addr[9] = main_30_010_320x320_png ,//图片nandflash相对地址
  .img_addr[10]= main_30_011_320x320_png ,//图片nandflash相对地址
  .img_addr[11]= main_30_012_320x320_png ,//图片nandflash相对地址
  .img_addr[12]= main_30_013_320x320_png ,//图片nandflash相对地址
  .img_addr[13]= main_30_014_320x320_png ,//图片nandflash相对地址
  .img_addr[14]= main_30_015_320x320_png ,//图片nandflash相对地址
  .img_addr[15]= main_30_016_320x320_png ,//图片nandflash相对地址  
  .data_type = dial_data_img_gif,
};
const custom_dial_text 		 main9_watch_hour_high = {
  .type = dial_type_text,
  .data_type = dial_data_text_hour_high  ,
  .x =  82 ,
  .y =  22,        
  .text_width = 35,
  .text_rgb[0] = 0xff,
  .text_rgb[1] = 0xff,
  .text_rgb[2] = 0xff,
  .text_align = LV_LABEL_ALIGN_LEFT,
  .text_size = dial_data_60x60_ext,
};
const custom_dial_text 		 main9_watch_hour_low = {
  .type = dial_type_text,
  .data_type = dial_data_text_hour_low  ,
  .x =  117 ,
  .y =  22,        
  .text_width = 35,
  .text_rgb[0] = 0xff,
  .text_rgb[1] = 0xff,
  .text_rgb[2] = 0xff,
  .text_align = LV_LABEL_ALIGN_LEFT,
  .text_size = dial_data_60x60_ext,
};
const custom_dial_text 		 main9_watch_min_high = {
  .type = dial_type_text,
  .data_type = dial_data_text_min_high  ,
  .x =  169 ,
  .y =  22,        
  .text_width = 35,
  .text_rgb[0] = 0xff,
  .text_rgb[1] = 0xff,
  .text_rgb[2] = 0xff,
  .text_align = LV_LABEL_ALIGN_LEFT,
  .text_size = dial_data_60x60_ext,
};
const custom_dial_text 		 main9_watch_min_low = {
  .type = dial_type_text,
  .data_type = dial_data_text_min_low  ,
  .x =  204 ,
  .y =  22,        
  .text_width = 35,
  .text_rgb[0] = 0xff,
  .text_rgb[1] = 0xff,
  .text_rgb[2] = 0xff,
  .text_align = LV_LABEL_ALIGN_LEFT,
  .text_size = dial_data_60x60_ext,
};
const custom_dial_text 		 main9_watch_separator = {
  .type = dial_type_text,
  .data_type = dial_data_text_custom  ,
  .x =  152 ,
  .y =  22,        
  .text_width = 35,
  .text_rgb[0] = 0xff,
  .text_rgb[1] = 0xff,
  .text_rgb[2] = 0xff,
  .text_align = LV_LABEL_ALIGN_LEFT,
  .text_size = dial_data_60x60_ext,
  .text_custom[0] = ':',
  .text_custom[1] = '\n',
};
const custom_dial_text 		 main9_watch_month = {
  .type = dial_type_text,
  .data_type = dial_data_text_month  ,
  .x =  119 ,
  .y =  268,        
  .text_width = 35,
  .text_rgb[0] = 0xff,
  .text_rgb[1] = 0xff,
  .text_rgb[2] = 0xff,
  .text_align = LV_LABEL_ALIGN_LEFT,
  .text_size = dial_data_30x30_ext, 
};
const custom_dial_text 		 main9_watch_date = {
  .type = dial_type_text,
  .data_type = dial_data_text_day  ,
  .x =  164 ,
  .y =  268,        
  .text_width = 35,
  .text_rgb[0] = 0xff,
  .text_rgb[1] = 0xff,
  .text_rgb[2] = 0xff,
  .text_align = LV_LABEL_ALIGN_LEFT,
  .text_size = dial_data_30x30_ext, 
};
const custom_dial_text 		 main9_watch_separator2 = {
  .type = dial_type_text,
  .data_type = dial_data_text_custom  ,
  .x =  154  ,
  .y =  268,        
  .text_width = 35,
  .text_rgb[0] = 0xff,
  .text_rgb[1] = 0xff,
  .text_rgb[2] = 0xff,
  .text_align = LV_LABEL_ALIGN_LEFT,
  .text_size = dial_data_30x30_ext,
  .text_custom[0] = '/',
  .text_custom[1] = '\n',
};

void main9_data_init(void)
{
	uint8_t* memory = dial_data; 
	obj_type[0] = dial_type_more_img;
	obj_type[1] = dial_type_text;
	obj_type[2] = dial_type_text;
	obj_type[3] = dial_type_text;
	obj_type[4] = dial_type_text;
	obj_type[5] = dial_type_text;
  obj_type[6] = dial_type_text;
	obj_type[7] = dial_type_text;
	obj_type[8] = dial_type_text;

	memcpy(memory,&main9_watch_bg,get_dial_type_size(dial_type_more_img)); 
	memory += get_dial_type_size(dial_type_more_img);

	memcpy(memory,&main9_watch_hour_high,get_dial_type_size(dial_type_text)); 
	memory += get_dial_type_size(dial_type_text);

  memcpy(memory,&main9_watch_hour_low,get_dial_type_size(dial_type_text)); 
	memory += get_dial_type_size(dial_type_text);

  memcpy(memory,&main9_watch_min_high,get_dial_type_size(dial_type_text)); 
	memory += get_dial_type_size(dial_type_text);

  memcpy(memory,&main9_watch_min_low,get_dial_type_size(dial_type_text)); 
	memory += get_dial_type_size(dial_type_text);

  memcpy(memory,&main9_watch_separator,get_dial_type_size(dial_type_text)); 
	memory += get_dial_type_size(dial_type_text);

  memcpy(memory,&main9_watch_month,get_dial_type_size(dial_type_text)); 
	memory += get_dial_type_size(dial_type_text);

  memcpy(memory,&main9_watch_date,get_dial_type_size(dial_type_text)); 
	memory += get_dial_type_size(dial_type_text);

  memcpy(memory,&main9_watch_separator2,get_dial_type_size(dial_type_text)); 
	memory += get_dial_type_size(dial_type_text);
}


 
/* 返回ch字符在sign数组中的序号 */
int getIndexOfSigns(char ch)
{
    if(ch >= '0' && ch <= '9')
    {
        return ch - '0';
    }
    if(ch >= 'A' && ch <='F') 
    {
        return ch - 'A' + 10;
    }
    if(ch >= 'a' && ch <= 'f')
    {
        return ch - 'a' + 10;
    }
    return -1;
}

long hexToDec(char *source)
{
    long sum = 0;
    long t = 1;
    int i, len;
 
    len = strlen(source);
    for(i=len-1; i>=0; i--)
    {
        sum += t * getIndexOfSigns(*(source + i));
        t *= 16;
    }  
    printf("sum = %ld\n",sum);
    return sum;
}
 
  /*
  */
uint32_t get16CharToInt(char* s)
{
  uint32_t num;
  s+=2;
  num = hexToDec(s);
  // printf("%s\n",s);
  // num = aoti(s);

  return num;
}
  

int main()
{
  printf("Version: %s\n", cJSON_Version()); 
  uint8_t obj_num = 0;
	uint8_t* memory = dial_data;  

  
  int    skill_array_size = 0, i = 0,j; 
  char read_json[65535] = {0};
  char *ch;
  ch = read_json;
  FILE *re = NULL; 
  re = fopen("dial_task.json","r");
  *ch=fgetc(re);
  int num = 0;
  while( *ch != EOF){
      ch++;
      *ch=fgetc(re); 
      num++;
  }
  // printf("\nnum = %d\n",num);
  // printf("%s\n\n",read_json);
  fclose(re);


  cJSON* cjson_mytest = NULL;


  cjson_mytest = cJSON_Parse(read_json);
  if(cjson_mytest == NULL)
  {
      printf("parse fail.\n"); 
      return 0;
  }
  cJSON* cjson_dial_id = cJSON_GetObjectItem(cjson_mytest, "dial_id");
  if(cjson_dial_id == NULL)
  {
    printf("get id fail\n");
    return 0;
  }



  printf("cJSON_GetArraySize = %d\n",cJSON_GetArraySize(cjson_mytest));
  for(j = 1;j<cJSON_GetArraySize(cjson_mytest);j++)
  { 
    cJSON* obj = cJSON_GetArrayItem(cjson_mytest,j); 
    printf("obj[%d] = %s\n",j,obj->string); 
    cJSON* read_type = cJSON_GetObjectItem(obj,"type");
    if (read_type->valueint == dial_type_image)
    {
      cJSON* json_type     = cJSON_GetObjectItem(obj,"type");     if(json_type == NULL) {printf("format err\n");return 0;}
      cJSON* json_x        = cJSON_GetObjectItem(obj,"x");        if(json_x == NULL) {printf("format err\n");return 0;}
      cJSON* json_y        = cJSON_GetObjectItem(obj,"y");        if(json_y == NULL) {printf("format err\n");return 0;}
      cJSON* json_img_addr = cJSON_GetObjectItem(obj,"img_addr"); if(json_img_addr == NULL) {printf("format err\n");return 0;}
      custom_dial_image dat;
      dat.type     = json_type->valueint;
      dat.x        = json_x->valueint;
      dat.y        = json_y->valueint;
      dat.img_addr = get16CharToInt(json_img_addr->valuestring);
      printf("%d %d %d %d \n",dat.type,dat.x,dat.y,dat.img_addr);
      obj_type[obj_num++] = dat.type;
      memcpy(memory,&dat,get_dial_type_size(dial_type_image)); 
      memory += get_dial_type_size(dial_type_image); 
    }
    else if(read_type->valueint == dial_type_pointer)
    {
      cJSON* json_type               = cJSON_GetObjectItem(obj,"type");               if(json_type == NULL) {printf("format err\n");return 0;}
      cJSON* json_data_type          = cJSON_GetObjectItem(obj,"data_type");          if(json_data_type == NULL) {printf("format err\n");return 0;}
      cJSON* json_x                  = cJSON_GetObjectItem(obj,"x");                  if(json_x == NULL) {printf("format err\n");return 0;}
      cJSON* json_y                  = cJSON_GetObjectItem(obj,"y");                  if(json_y == NULL) {printf("format err\n");return 0;}
      cJSON* json_img_addr           = cJSON_GetObjectItem(obj,"img_addr");           if(json_img_addr == NULL) {printf("format err\n");return 0;}
      cJSON* json_img_heigth         = cJSON_GetObjectItem(obj,"img_heigth");         if(json_img_heigth == NULL) {printf("format err\n");return 0;}
      cJSON* json_img_width          = cJSON_GetObjectItem(obj,"img_width");          if(json_img_width == NULL) {printf("format err\n");return 0;}
      cJSON* json_start_arc          = cJSON_GetObjectItem(obj,"start_arc");          if(json_start_arc == NULL) {printf("format err\n");return 0;}
      cJSON* json_end_arc            = cJSON_GetObjectItem(obj,"end_arc");            if(json_end_arc == NULL) {printf("format err\n");return 0;}
      cJSON* json_rotation_center_x  = cJSON_GetObjectItem(obj,"rotation_center_x");  if(json_rotation_center_x == NULL) {printf("format err\n");return 0;}
      cJSON* json_rotation_center_y  = cJSON_GetObjectItem(obj,"rotation_center_y");  if(json_rotation_center_y == NULL) {printf("format err\n");return 0;}
      custom_dial_pointer dat;
      dat.type              =  json_type->valueint;
      dat.data_type         =  json_data_type->valueint;
      dat.x                 =  json_x->valueint;
      dat.y                 =  json_y->valueint;
      dat.img_addr          =  get16CharToInt(json_img_addr->valuestring);
      dat.img_heigth        =  json_img_heigth->valueint;
      dat.img_width         =  json_img_width->valueint;
      dat.start_arc         =  json_start_arc->valueint;
      dat.end_arc           =  json_end_arc->valueint;
      dat.rotation_center_x =  json_rotation_center_x->valueint;
      dat.rotation_center_y =  json_rotation_center_y->valueint;
      printf("%d %d %d %d %d %d %d %d %d %d %d \n",dat.type,dat.data_type,dat.x,dat.y,dat.img_addr,dat.img_heigth,dat.img_width,dat.start_arc,dat.end_arc,dat.rotation_center_x,dat.rotation_center_y);

      obj_type[obj_num++] = dat.type;
      memcpy(memory,&dat,get_dial_type_size(dial_type_pointer)); 
      memory += get_dial_type_size(dial_type_pointer); 
    }
    else if(read_type->valueint == dial_type_text)
    {
      cJSON* cjson_type           =  cJSON_GetObjectItem(obj,"type");        if(cjson_type == NULL) {printf("format err\n");return 0;}                      
      cJSON* cjson_data_type      =  cJSON_GetObjectItem(obj,"data_type");   if(cjson_data_type == NULL) {printf("format err\n");return 0;}                  
      cJSON* cjson_x              =  cJSON_GetObjectItem(obj,"x");           if(cjson_x == NULL) {printf("format err\n");return 0;}          
      cJSON* cjson_y              =  cJSON_GetObjectItem(obj,"y");           if(cjson_y == NULL) {printf("format err\n");return 0;}          
      cJSON* cjson_text_width     =  cJSON_GetObjectItem(obj,"text_width");  if(cjson_text_width == NULL) {printf("format err\n");return 0;}                  
      cJSON* cjson_text_rgb       =  cJSON_GetObjectItem(obj,"text_rgb");    if(cjson_text_rgb == NULL) {printf("format err\n");return 0;}                
      cJSON* cjson_text_align     =  cJSON_GetObjectItem(obj,"text_align");  if(cjson_text_align == NULL) {printf("format err\n");return 0;}                  
      cJSON* cjson_text_size      =  cJSON_GetObjectItem(obj,"text_size");   if(cjson_text_size == NULL) {printf("format err\n");return 0;}                  
      cJSON* cjson_text_custom    =  cJSON_GetObjectItem(obj,"text_custom"); if(cjson_text_custom == NULL) {printf("format err\n");return 0;}                    

      custom_dial_text dat;
      dat.type            = cjson_type->valueint;                   
      dat.data_type       = cjson_data_type->valueint;                          
      dat.x               = cjson_x->valueint;                                  
      dat.y               = cjson_y->valueint;                                
      dat.text_width      = cjson_text_width->valueint;                       
      if(cJSON_GetArraySize(cjson_text_rgb) == 3){
        cJSON* r =cJSON_GetArrayItem(cjson_text_rgb,0);
        cJSON* g =cJSON_GetArrayItem(cjson_text_rgb,1);
        cJSON* b =cJSON_GetArrayItem(cjson_text_rgb,2);
        dat.text_rgb[0] = r->valueint;
        dat.text_rgb[1] = g->valueint;
        dat.text_rgb[2] = b->valueint;
      }
      dat.text_align     =    cjson_text_align->valueint;                       
      dat.text_size      =    cjson_text_size->valueint;
      if(strlen(cjson_text_custom->valuestring) >=20){
        for(i = 0;i<19;i++)
          dat.text_custom[i] = cjson_text_custom->valuestring[i];
        dat.text_custom[19] = '\0';
      }
      else
      {
        for(i = 0;i<strlen(cjson_text_custom->valuestring);i++)
          dat.text_custom[i] = cjson_text_custom->valuestring[i];
      }
       
      printf("%d %d %d %d %d %d %d %d %d %d %s\r\n",dat.type,dat.data_type,dat.x,dat.y,dat.text_width,dat.text_rgb[0],dat.text_rgb[1],dat.text_rgb[2],dat.text_align,dat.text_size,dat.text_custom );
      obj_type[obj_num++] = dat.type;
      memcpy(memory,&dat,get_dial_type_size(dial_type_text)); 
      memory += get_dial_type_size(dial_type_text);
    }
    else if(read_type->valueint == dial_type_more_img)
    {
      cJSON* cjson_type           =  cJSON_GetObjectItem(obj,"type");
      cJSON* cjson_data_type      =  cJSON_GetObjectItem(obj,"data_type");
      cJSON* cjson_x              =  cJSON_GetObjectItem(obj,"x");
      cJSON* cjson_y              =  cJSON_GetObjectItem(obj,"y");
      cJSON* cjson_img_addr       =  cJSON_GetObjectItem(obj,"img_addr");
      custom_dial_more_img dat;
      dat.type      = cjson_type->valueint;
      dat.data_type = cjson_data_type->valueint;
      dat.x         = cjson_x->valueint;
      dat.y         = cjson_y->valueint;
      for(i = 0;i<cJSON_GetArraySize(cjson_img_addr);i++)
      {
        cJSON* r =cJSON_GetArrayItem(cjson_img_addr,i);
        dat.img_addr[i] = get16CharToInt(r->valuestring);
      }
      printf("%d %d %d %d ",dat.type,dat.data_type ,dat.x,dat.y);
      for(i = 0;i<cJSON_GetArraySize(cjson_img_addr);i++)
        printf("%d ",dat.img_addr[i]);
      printf("\n");

      obj_type[obj_num++] = dat.type;
      memcpy(memory,&dat,get_dial_type_size(dial_type_more_img)); 
      memory += get_dial_type_size(dial_type_more_img);
    }
  }






  uint8_t crc8[8] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
  uint8_t head_bin4[4] = { 0x00,0x00,0xa0,0x06};


  // main9_data_init();
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
  
	// FILE *f_rb;
  // int c;
  // f_rb = fopen("AllBinData.bin","rb");

  char file_name[] = "001001_U0.";
  strcat(file_name,cjson_dial_id->valuestring);
  strcat(file_name,".bin");

  fp = fopen(file_name, "w+");
  fwrite(&head_bin4,sizeof(head_bin4),1,fp);  
  fwrite(&crc8,sizeof(crc8),1,fp);  
  fwrite(&obj_type,sizeof(obj_type),1,fp);  
  fwrite(&dial_data,sizeof(dial_data),1,fp);  

  // // while((	c=fgetc(f_rb))!=EOF) { putc(c, fp);}	
  fwrite(&crc8,sizeof(crc8),1,fp);   
  // fclose(f_rb); 
  fclose(fp);
  printf("ok\n");
  

  
	// FILE *f_rb,*f_wb;
	// long n,offset;
	// int c;
	// f_rb = fopen("AllBinData.bin","rb");
	
	// f_wb = fopen("001001_R0.5.bin","w+");
	
	// // fseek(f_wb,0,SEEK_END);
	// fputc('\x00',f_wb);//0X00
	// fputc('\x00',f_wb);//0X00
	// fputc('\x02',f_wb);//0X00
	// fputc('\x04',f_wb);//0X00
	// while((	c=fgetc(f_rb))!=EOF) fputc(c, f_wb);	
	// fclose(f_rb);


	// fclose(f_wb);


  
}

























