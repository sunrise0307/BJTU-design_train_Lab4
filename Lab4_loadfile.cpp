#define _CRT_SECURE_NO_WARNINGS
#include "Lab4_loadfile.h"
#include "Lab4_sort.h"
#include "Lab4_view.h"
#include "Lab4_data.h"
#include<time.h>
#include<fstream>
using namespace std;
//二维数组存储,开始时间
clock_t bgtime_arr=0;

//二维数组存储,结束时间
clock_t edtime_arr=0;

//结构体数组存储,开始时间
clock_t bgtime_struct=0;

//结构体数组存储结束时间
clock_t edtime_struct=0;

//结构体指针数组存储开始时间
clock_t bgtime_pstruct=0;

//结构体指针数组存储结束时间
clock_t edtime_pstruct=0;



//快排开始时间,随机数据
clock_t bgtime_q_randata=0;

//快排开始时间,正序数据
 clock_t bgtime_q_pdata=0;

//快排开始时间,逆序数据
clock_t bgtime_q_rdata=0;

//快排结束时间,随机数据
clock_t edtime_q_randata=0;

//快排结束时间,正序数据
clock_t edtime_q_pdata=0;

//快排结束时间,逆序数据
clock_t edtime_q_rdata=0;


//冒泡开始时间,随机数据
clock_t bgtime_p_randata=0;

//冒泡开始时间,正序数据
 clock_t bgtime_p_pdata=0;

//冒泡开始时间,逆序数据
clock_t bgtime_p_rdata=0;

//冒泡结束时间,随机数据
clock_t edtime_p_randata=0;

//冒泡结束时间,正序数据
 clock_t edtime_p_pdata=0;

//冒泡结束时间,逆序数据
clock_t edtime_p_rdata=0;

//读取实验四工作模式
void rmode() {
	ifstream file;
    file.open("..\\info.txt", ios::in);
    if (!file.is_open()) {
        cout << "info.txt文件打开失败" << endl;
    }
    file >> mode;
    file.close();
}

//将配置文件信息读入配置文件结构体
void readconf(CONF* conf) {
    FILE* fp = fopen("..\\conf.ini.txt", "r");
	if (fp == NULL) {
		cout << "failed" << endl;
	}
    fscanf(fp, "%s", conf->filesavepath);
    fscanf(fp, "%s", conf->filename);
	fscanf(fp, "%d", &conf->number);
    fscanf(fp, "%d", &conf->maxvalue1);
    fscanf(fp, "%d", &conf->minvalue1);
    fscanf(fp, "%d", &conf->maxvalue2);
    fscanf(fp, "%d", &conf->minvalue2);
    fscanf(fp, "%d", &conf->recordcount1);
    fscanf(fp, "%d", &conf->recordcount2);
    fclose(fp);
}

//读取实验三的记录文件
// is_sort=0表示原始顺序打印;=1表示排序后打印,逆序
void ReadFile(const char* filename, int num, int is_sort) {
	FILE* fp;

	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("文件打开失败！");
		return;
	}

	//储存到二维数组
	if (num == 1) {
		int n, i;//n是行数
		fscanf(fp, "%d", &n);
		int** arr = load_arr(fp,n);

		//排序
		if (is_sort == 1) {
			bgtime_arr = clock();
			qsort(arr, n, sizeof(int*), cmp_arr);
			edtime_arr = clock();
		}

		//打印数据
		printarry(arr, n);
	}

	//储存到结构体数组
	else if (num == 2) {
		int n, i;
		fscanf(fp, "%d", &n);
		DATAITEM* arr = load_struct(fp,n);
		//排序
		if (is_sort == 1) {
			bgtime_struct = clock();
			qsort(arr, n, sizeof(DATAITEM), cmp_struct);
			edtime_struct = clock();
		}

		//打印数据
		printstruct(arr,n);
	}

	//储存到指针数组
	else if (num == 3) {
		int n, i;
		fscanf(fp, "%d", &n);
		DATAITEM** arr = (DATAITEM**)malloc(n * sizeof(DATAITEM*));
		//为每一行动态分配空间
		for (i = 0; i < n; i++) {
			arr[i] = (DATAITEM*)malloc(sizeof(DATAITEM));
		}
		//读取每一行数据
		for (i = 0; i < n; i++) {
			fscanf(fp, "%d,%d,%d", &arr[i]->item1, &arr[i]->item2, &arr[i]->item3);
		}
		//排序
		if (is_sort == 1) {
			bgtime_pstruct = clock();

			qsort(arr, n, sizeof(DATAITEM*), cmp_pstruct);

			edtime_pstruct = clock();
		}
		//打印数据
		printpstruct(arr, n);
	}

	//储存到链表
	else if (num == 4) {
		LinkList* list = (LinkList*)malloc(sizeof(LinkList));
		list->head =(Node*)malloc(sizeof(Node));
		list->head->next = NULL;
		PNode tail = list->head;
		
		int i;
		fscanf(fp, "%d", &(list->head->data.item1));
		//读入数据
		for (i = 0; i < list->head->data.item1; i++) {

			Node* newNode = (Node*)malloc(sizeof(Node));
			fscanf(fp, "%d,%d,%d", &newNode->data.item1, &newNode->data.item2, &newNode->data.item3);
			newNode->next = NULL;
			tail->next = newNode;
			tail = newNode;
			
		}
		PNode p = list->head->next;
		//排序
		static int testtimes = 0;
		if (is_sort == 1) {
			if (list->head->next != NULL && list->head->next->next != NULL) {

				if (testtimes % 2 == 0) {
					//随机数据,结果为正序
					bgtime_q_randata = clock();
					p = quickSort_p(list->head->next);
					edtime_q_randata = clock();
					testtimes++;
				}
				else {
					//随机数据,结果为正序
					bgtime_p_randata = clock();
					p = bubbleSort_p(list->head->next);
					edtime_p_randata = clock();
					testtimes++;
				}

				//正序数据,结果是逆序
				bgtime_q_pdata = clock();
				p = quickSort_r(p);
				edtime_q_pdata = clock();

				//逆序数据,结果是正序
				bgtime_q_rdata = clock();
				p = quickSort_p(p);
				edtime_q_rdata = clock();

				
				//正序数据,结果为逆序
				bgtime_p_pdata = clock();
				p = bubbleSort_r(p);
				edtime_p_pdata = clock();

				//逆序数据,结果为正序
				bgtime_p_rdata = clock();
				p = bubbleSort_p(p);
				edtime_p_rdata = clock();


				
			}
		}

		//打印数据
		printlist(p);

	}
}

int** load_arr(FILE*fp,int n) {
	int i;
	int** arr = (int**)malloc(n * sizeof(int*));
	if (arr == NULL) {
		printf("内存分配失败！");
		return NULL;
	}

	//为每一行动态分配空间
	for (i = 0; i < n; i++) {
		arr[i] = (int*)malloc(3 * sizeof(int));
		if (arr[i] == NULL) {
			printf("内存分配失败！");
			return NULL;
		}
	}
	for (i = 0; i < n; i++) {
		fscanf(fp, "%d,%d,%d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}
	return arr;

}

//文件读入到结构体数组
DATAITEM* load_struct(FILE*fp,int n) {

	int i;
	DATAITEM* arr = (DATAITEM*)malloc(n * sizeof(DATAITEM));
	//读取每一行数据
	for (i = 0; i < n; i++) {
		fscanf(fp, "%d,%d,%d", &arr[i].item1, &arr[i].item2, &arr[i].item3);
	}
	return arr;
}