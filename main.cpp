/*
 * @Descripttion: 
 * @version: 
 * @Author: Jeremy
 * @Date: 2021-08-09 14:23:55
 * @LastEditors: Jeremy
 * @LastEditTime: 2021-08-09 14:45:33
 */
/*
 * @LastEditTime: 2021-08-09 13:40:08
 */
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include "custom_dial_head.h" 


using namespace std;

#define EXT_FLASH_PNG_BASE						(0x020ce530UL)
#define LV_HOR_RES_MAX 320
#define LV_VER_RES_MAX 320
#define      main_7_bg_320x320_png                                                                            (EXT_FLASH_PNG_BASE+0x1FE7F4)
#define      main_7_hour_10x79_c79_png                                                                        (EXT_FLASH_PNG_BASE+0x2497F8)
#define      main_7_min_18x142_c133_png                                                                       (EXT_FLASH_PNG_BASE+0x24A13E)
#define      main_7_sec_4x106_c106_png                                                                        (EXT_FLASH_PNG_BASE+0x24BF36)

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

custom_dial_image     main7_watch_bg = {
  .type = dial_type_image,
  .x = 0,//左上角x坐标
  .y = 0,//左上角y坐标
  .img_addr = main_7_bg_320x320_png,//图片nandflash相对地址
};
custom_dial_pointer   main7_hour_pointer = {
	.type = dial_type_pointer,
	.data_type = dial_data_hour_pointer,//指针数据类型
	.x = (LV_HOR_RES_MAX - 10) / 2,   //左上角x坐标
	.y = (LV_VER_RES_MAX / 2) - 79,   //左上角y坐标
	.img_addr = main_7_hour_10x79_c79_png,    //图片nandflash相对地址
	.img_heigth = 10,  //图片高度
	.img_width = 79,   //图片宽度
	.start_arc = 0,   //指针开始角度
	.end_arc = 360,     //指针结束角度
	.rotation_center_x = 10 / 2,//指针相对旋转坐标x
	.rotation_center_y = 79,//指针相对旋转坐标y
};
custom_dial_pointer   main7_min_pointer = {
	.type = dial_type_pointer,
	.data_type = dial_data_min_pointer,//指针数据类型
	.x = (LV_HOR_RES_MAX - 18) / 2,   //左上角x坐标
	.y = (LV_VER_RES_MAX / 2) - 133,   //左上角y坐标
	.img_addr = main_7_min_18x142_c133_png,    //图片nandflash相对地址
	.img_heigth = 18,  //图片高度
	.img_width = 142,   //图片宽度
	.start_arc = 0,   //指针开始角度
	.end_arc = 360,     //指针结束角度
	.rotation_center_x = 18 / 2,//指针相对旋转坐标x
	.rotation_center_y = 133,//指针相对旋转坐标y
};
custom_dial_pointer   main7_sec_pointer = {
	.type = dial_type_pointer,
	.data_type = dial_data_sec_pointer,//指针数据类型
	.x = (LV_HOR_RES_MAX - 4) / 2,   //左上角x坐标
	.y = (LV_VER_RES_MAX / 2) - 106,   //左上角y坐标
	.img_addr = main_7_sec_4x106_c106_png,    //图片nandflash相对地址
	.img_heigth = 4,  //图片高度
	.img_width = 106,   //图片宽度
	.start_arc = 0,   //指针开始角度
	.end_arc = 360,     //指针结束角度
	.rotation_center_x = 4 / 2,//指针相对旋转坐标x
	.rotation_center_y = 106,//指针相对旋转坐标y
};

uint8_t dial_data[4096];
uint8_t obj[40];


void main7_data_init(void)
{
	uint8_t* memory = dial_data;
	obj[0] = 1;
	obj[1] = 2;
	obj[2] = 2;
	obj[3] = 2;



	memcpy(memory, &main7_watch_bg, get_dial_type_size(dial_type_image));
	memory += get_dial_type_size(dial_type_image);

	memcpy(memory, &main7_hour_pointer, get_dial_type_size(dial_type_pointer));
	memory += get_dial_type_size(dial_type_pointer);

	memcpy(memory, &main7_min_pointer, get_dial_type_size(dial_type_pointer));
	memory += get_dial_type_size(dial_type_pointer);

	memcpy(memory, &main7_sec_pointer, get_dial_type_size(dial_type_pointer));
	memory += get_dial_type_size(dial_type_pointer);

	// for (int i = 0; i < 100; i++)
	// {
	// 	printf("main7[%d] = 0x%x\n", i, dial_data[i]);
	// }
}


int main()
{
  uint8_t* buffer;
  long size;

   main7_data_init();

    uint8_t dial_obj_type_seek = 0; 
    uint8_t password[8] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
    ofstream fs1;
    fs1.open("password.bin");
    fs1.write((const char*)&password, sizeof(password));  // 使用 write函数写二进制文件
    fs1.close();
 
 
    ofstream fs2;

    fs2.open("dial_obj_type.bin");
    fs2.write((const char*)&obj, sizeof(obj));  // 使用 write函数写二进制文件


 

    ofstream fs3;
    fs3.open("dial_data.bin");
    fs3.write((const char*)&dial_data, sizeof(dial_data));  // 使用 write函数写二进制文件

  
    fs2.close(); 
    fs3.close(); 

    ifstream in_test("dial_data.bin", ios::in | ios::binary | ios::ate);
    size = (long)in_test.tellg();
    in_test.seekg(0, ios::beg);
    buffer = new uint8_t[size];
    in_test.read((char*)buffer, size);
    in_test.close(); 
    for (int i = 0; i < 100; i++)
    {
      if(buffer[i] != dial_data[i])
      {
        printf("i= %d\r\n",i);
      }
		  // printf("main7[%d] = 0x%x  buffer[%d] = 0x%x \n", i, dial_data[i],i,buffer[i]);

    }
    printf("is ok!\r\n");

 
    // add head 4 addr
    uint8_t ota_head[4] = { 0x00,0x00,0xa0,0x06};
    ofstream ota_h;
    ota_h.open("ota_h.bin");
    ota_h.write((const char*)&ota_head, sizeof(ota_head));  // 使用 write函数写二进制文件
    ota_h.close();


    //合并文件
    ofstream fs4;
    fs4.open("all.bin"); 
    ifstream in5("ota_h.bin", ios::in | ios::binary | ios::ate);
    size = (long)in5.tellg();
    in5.seekg(0, ios::beg);
    buffer = new uint8_t[size];
    in5.read((char*)buffer, size);
    in5.close(); 
    fs4.write((const char*)&buffer[0], sizeof(uint8_t) * size);
    delete[] buffer; 

    ifstream in("password.bin", ios::in | ios::binary | ios::ate);
    size = (long)in.tellg();
    in.seekg(0, ios::beg);
    buffer = new uint8_t[size];
    in.read((char*)buffer, size);
    in.close(); 
    fs4.write((const char*)&buffer[0], sizeof(uint8_t) * size);
    delete[] buffer; 
    ifstream in1("dial_obj_type.bin", ios::in | ios::binary | ios::ate);
    size = (long)in1.tellg();
    in1.seekg(0, ios::beg);
    buffer = new uint8_t[size];
    in1.read((char*)buffer, size);
    in1.close(); 
    fs4.write((const char*)&buffer[0], sizeof(uint8_t) * size); 
    delete[] buffer; 
    ifstream in2("dial_data.bin", ios::in | ios::binary | ios::ate);
    size = (long)in2.tellg();
    in2.seekg(0, ios::beg);
    buffer = new uint8_t[size];
    in2.read((char*)buffer, size);
    in2.close();
    fs4.write((const char*)&buffer[0], sizeof(uint8_t) * size);
    delete[] buffer; 
    fs4.close();




  
}

























