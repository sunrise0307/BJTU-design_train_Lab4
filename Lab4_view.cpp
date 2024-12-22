#define _CRT_SECURE_NO_WARNINGS
#include "Lab4_data.h"
#include "Lab4_view.h"
#include<iostream>

//打印结构体信息
void printconf(CONF* conf) {
	cout << "数据记录文件的存储目录:" << endl;
	cout<< conf->filesavepath<<endl;
	cout << "存储数据记录文件的文件名:" << endl;
	cout<< conf->filename<<endl;
	cout << "生成的记录条数:" << endl;
	cout<< conf->number<<endl;
	cout << "生成的数据记录三元组中第1、2个元素取值的上限:" << endl;
	cout<<conf->maxvalue1 <<endl;
	cout << "生成的数据记录三元组中第1、2个元素取值的下限:" << endl;
	cout<< conf->minvalue1<<endl;
	cout << "生成的数据记录三元组中第3个元素取值的上限:" << endl;
	cout<< conf->maxvalue2<<endl;
	cout << "生成的数据记录三元组中第3个元素取值的下限:" << endl;
	cout<<conf->minvalue2 <<endl;
	cout << "存放数据记录文件需要随机生成记录条数时条数值的上限:" << endl;
	cout<< conf->recordcount1<<endl;
	cout << "存放数据记录文件需要随机生成记录条数时条数值的下限:" << endl;
	cout<< conf->recordcount2<<endl;
}

//打印数据_二维数组
void printarry(int** arr, int len) {
	int i;
	for (i = 0; i < len; i++) {
		printf("%d %d %d\n", arr[i][0], arr[i][1], arr[i][2]);
	}
}

//打印数据_结构体
void printstruct(DATAITEM* arr,int len) {
	int i;
	for (i = 0; i < len; i++) {
			printf("%d %d %d\n", arr[i].item1, arr[i].item2, arr[i].item3);
		}
}

//打印结构体指针
void printpstruct(DATAITEM** arr, int len) {
	int i;
	for (i = 0; i < len; i++) {
		printf("%d %d %d\n", arr[i]->item1, arr[i]->item2, arr[i]->item3);
	}
}

//打印数据_链表
// 注:p为第一个数据节点
void printlist(Node* p) {
	while (p != NULL) {
		printf("%d %d %d\n", p->data.item1, p->data.item2, p->data.item3);
		p = p->next;
	}
}