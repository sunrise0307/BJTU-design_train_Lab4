#define _CRT_SECURE_NO_WARNINGS
#include "Lab4_loadfile.h"
#include "Lab4_sort.h"
#include "Lab4_view.h"
#include "Lab4_data.h"
#include<time.h>
#include<fstream>
using namespace std;
//��ά����洢,��ʼʱ��
clock_t bgtime_arr=0;

//��ά����洢,����ʱ��
clock_t edtime_arr=0;

//�ṹ������洢,��ʼʱ��
clock_t bgtime_struct=0;

//�ṹ������洢����ʱ��
clock_t edtime_struct=0;

//�ṹ��ָ������洢��ʼʱ��
clock_t bgtime_pstruct=0;

//�ṹ��ָ������洢����ʱ��
clock_t edtime_pstruct=0;



//���ſ�ʼʱ��,�������
clock_t bgtime_q_randata=0;

//���ſ�ʼʱ��,��������
 clock_t bgtime_q_pdata=0;

//���ſ�ʼʱ��,��������
clock_t bgtime_q_rdata=0;

//���Ž���ʱ��,�������
clock_t edtime_q_randata=0;

//���Ž���ʱ��,��������
clock_t edtime_q_pdata=0;

//���Ž���ʱ��,��������
clock_t edtime_q_rdata=0;


//ð�ݿ�ʼʱ��,�������
clock_t bgtime_p_randata=0;

//ð�ݿ�ʼʱ��,��������
 clock_t bgtime_p_pdata=0;

//ð�ݿ�ʼʱ��,��������
clock_t bgtime_p_rdata=0;

//ð�ݽ���ʱ��,�������
clock_t edtime_p_randata=0;

//ð�ݽ���ʱ��,��������
 clock_t edtime_p_pdata=0;

//ð�ݽ���ʱ��,��������
clock_t edtime_p_rdata=0;

//��ȡʵ���Ĺ���ģʽ
void rmode() {
	ifstream file;
    file.open("..\\info.txt", ios::in);
    if (!file.is_open()) {
        cout << "info.txt�ļ���ʧ��" << endl;
    }
    file >> mode;
    file.close();
}

//�������ļ���Ϣ���������ļ��ṹ��
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

//��ȡʵ�����ļ�¼�ļ�
// is_sort=0��ʾԭʼ˳���ӡ;=1��ʾ������ӡ,����
void ReadFile(const char* filename, int num, int is_sort) {
	FILE* fp;

	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("�ļ���ʧ�ܣ�");
		return;
	}

	//���浽��ά����
	if (num == 1) {
		int n, i;//n������
		fscanf(fp, "%d", &n);
		int** arr = load_arr(fp,n);

		//����
		if (is_sort == 1) {
			bgtime_arr = clock();
			qsort(arr, n, sizeof(int*), cmp_arr);
			edtime_arr = clock();
		}

		//��ӡ����
		printarry(arr, n);
	}

	//���浽�ṹ������
	else if (num == 2) {
		int n, i;
		fscanf(fp, "%d", &n);
		DATAITEM* arr = load_struct(fp,n);
		//����
		if (is_sort == 1) {
			bgtime_struct = clock();
			qsort(arr, n, sizeof(DATAITEM), cmp_struct);
			edtime_struct = clock();
		}

		//��ӡ����
		printstruct(arr,n);
	}

	//���浽ָ������
	else if (num == 3) {
		int n, i;
		fscanf(fp, "%d", &n);
		DATAITEM** arr = (DATAITEM**)malloc(n * sizeof(DATAITEM*));
		//Ϊÿһ�ж�̬����ռ�
		for (i = 0; i < n; i++) {
			arr[i] = (DATAITEM*)malloc(sizeof(DATAITEM));
		}
		//��ȡÿһ������
		for (i = 0; i < n; i++) {
			fscanf(fp, "%d,%d,%d", &arr[i]->item1, &arr[i]->item2, &arr[i]->item3);
		}
		//����
		if (is_sort == 1) {
			bgtime_pstruct = clock();

			qsort(arr, n, sizeof(DATAITEM*), cmp_pstruct);

			edtime_pstruct = clock();
		}
		//��ӡ����
		printpstruct(arr, n);
	}

	//���浽����
	else if (num == 4) {
		LinkList* list = (LinkList*)malloc(sizeof(LinkList));
		list->head =(Node*)malloc(sizeof(Node));
		list->head->next = NULL;
		PNode tail = list->head;
		
		int i;
		fscanf(fp, "%d", &(list->head->data.item1));
		//��������
		for (i = 0; i < list->head->data.item1; i++) {

			Node* newNode = (Node*)malloc(sizeof(Node));
			fscanf(fp, "%d,%d,%d", &newNode->data.item1, &newNode->data.item2, &newNode->data.item3);
			newNode->next = NULL;
			tail->next = newNode;
			tail = newNode;
			
		}
		PNode p = list->head->next;
		//����
		static int testtimes = 0;
		if (is_sort == 1) {
			if (list->head->next != NULL && list->head->next->next != NULL) {

				if (testtimes % 2 == 0) {
					//�������,���Ϊ����
					bgtime_q_randata = clock();
					p = quickSort_p(list->head->next);
					edtime_q_randata = clock();
					testtimes++;
				}
				else {
					//�������,���Ϊ����
					bgtime_p_randata = clock();
					p = bubbleSort_p(list->head->next);
					edtime_p_randata = clock();
					testtimes++;
				}

				//��������,���������
				bgtime_q_pdata = clock();
				p = quickSort_r(p);
				edtime_q_pdata = clock();

				//��������,���������
				bgtime_q_rdata = clock();
				p = quickSort_p(p);
				edtime_q_rdata = clock();

				
				//��������,���Ϊ����
				bgtime_p_pdata = clock();
				p = bubbleSort_r(p);
				edtime_p_pdata = clock();

				//��������,���Ϊ����
				bgtime_p_rdata = clock();
				p = bubbleSort_p(p);
				edtime_p_rdata = clock();


				
			}
		}

		//��ӡ����
		printlist(p);

	}
}

int** load_arr(FILE*fp,int n) {
	int i;
	int** arr = (int**)malloc(n * sizeof(int*));
	if (arr == NULL) {
		printf("�ڴ����ʧ�ܣ�");
		return NULL;
	}

	//Ϊÿһ�ж�̬����ռ�
	for (i = 0; i < n; i++) {
		arr[i] = (int*)malloc(3 * sizeof(int));
		if (arr[i] == NULL) {
			printf("�ڴ����ʧ�ܣ�");
			return NULL;
		}
	}
	for (i = 0; i < n; i++) {
		fscanf(fp, "%d,%d,%d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}
	return arr;

}

//�ļ����뵽�ṹ������
DATAITEM* load_struct(FILE*fp,int n) {

	int i;
	DATAITEM* arr = (DATAITEM*)malloc(n * sizeof(DATAITEM));
	//��ȡÿһ������
	for (i = 0; i < n; i++) {
		fscanf(fp, "%d,%d,%d", &arr[i].item1, &arr[i].item2, &arr[i].item3);
	}
	return arr;
}