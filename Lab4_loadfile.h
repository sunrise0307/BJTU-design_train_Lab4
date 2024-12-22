#pragma once
#include <iostream>
#include "Lab4_data.h"

//读取实验四工作模式
void rmode();

//文件读入二维数组
int** load_arr(FILE*fp,int n);

//文件读入结构体数组
DATAITEM* load_struct(FILE* fp, int n);
//将配置文件信息读入配置文件结构体
void readconf(CONF* conf);

//读取实验三的记录文件
// is_sort=0表示原始顺序打印,=1表示排序后打印,逆序
void ReadFile(const char* filename, int num, int is_sort=0);
