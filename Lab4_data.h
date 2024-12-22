#pragma once
#define  MAX_STR_LEN  255   
#include<string>
#include<string>
#include<time.h>
using namespace std;

//三元组结构体
typedef  struct  DataItem {
	int  item1;     //数据记录三元组第一个元素
	int  item2;     //数据记录三元组第二个元素
	int  item3;     //数据记录三元组第三个元素
} DATAITEM;

//链表节点
typedef struct Node {
	DATAITEM data;
	Node* next;
}Node, * PNode;

//链表结构,有头结点
typedef struct LinkList {
	Node* head;
}LinkList;

//配置文件结构体,9条参数
typedef struct configinfo {
	char  filesavepath[MAX_STR_LEN];     	//用于存放数据记录文件的存储目录
	char  filename[MAX_STR_LEN];              //用于存储数据记录文件的文件名信息
	int  number;		//用于存放生成的记录条数
	int  maxvalue1;   		//用于存放实验2中生成的数据记录三元组中第1、2个元素取值的上限
	int  minvalue1; 		//用于存放实验2中生成的数据记录三元组中第1、2个元素取值的下限
	int  maxvalue2;   		//用于存放实验2中生成的数据记录三元组中第3个元素取值的上限
	int  minvalue2; 		//用于存放实验2中生成的数据记录三元组中第3个元素取值的下限
	int  recordcount1;	//用于存放数据记录文件需要随机生成记录条数时条数值的上限
	int  recordcount2;	//用于存放数据记录文件需要随机生成记录条数时条数值的下限
} CONF;

extern string full_path_nm;

//实验四工作模式
extern string mode;

//Lab3数据记录文件的存储目录
extern string loc;

//存储数据记录文件的文件名信息
extern string fname;

//存放生成的记录条数
extern string num1;

//二维数组存储,开始时间
extern clock_t bgtime_arr;

//二维数组存储,结束时间
extern clock_t edtime_arr;

//结构体数组存储,开始时间
extern clock_t bgtime_struct;

//结构体数组存储结束时间
extern clock_t edtime_struct;

//结构体指针数组存储开始时间
extern clock_t bgtime_pstruct;

//结构体指针数组存储结束时间
extern clock_t edtime_pstruct;



//快排开始时间,随机数据
extern clock_t bgtime_q_randata;

//快排开始时间,正序数据
extern clock_t bgtime_q_pdata;

//快排开始时间,逆序数据
extern clock_t bgtime_q_rdata;

//快排结束时间,随机数据
extern clock_t edtime_q_randata;

//快排结束时间,正序数据
extern clock_t edtime_q_pdata;

//快排结束时间,逆序数据
extern clock_t edtime_q_rdata;


//冒泡开始时间,随机数据
extern clock_t bgtime_p_randata;

//冒泡开始时间,正序数据
extern clock_t bgtime_p_pdata;

//冒泡开始时间,逆序数据
extern clock_t bgtime_p_rdata;

//冒泡结束时间,随机数据
extern clock_t edtime_p_randata;

//冒泡结束时间,正序数据
extern clock_t edtime_p_pdata;

//冒泡结束时间,逆序数据
extern clock_t edtime_p_rdata;