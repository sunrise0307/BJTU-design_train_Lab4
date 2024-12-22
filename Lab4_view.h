#define _CRT_SECURE_NO_WARNINGS
#include "Lab4_data.h"

//打印配置文件结构体信息
void printconf(CONF* conf);

//打印数据_二维数组
void printarry(int** arr, int len);

//打印数据_结构体
void printstruct(DATAITEM* arr,int len);

//打印数据_结构体指针数组
void printpstruct(DATAITEM** arr, int len);

//打印数据_链表
// 注:p为第一个数据节点
void printlist(Node* p);