#define _CRT_SECURE_NO_WARNINGS
#include "Lab4_data.h"
#include "Lab4_view.h"
#include<iostream>

//��ӡ�ṹ����Ϣ
void printconf(CONF* conf) {
	cout << "���ݼ�¼�ļ��Ĵ洢Ŀ¼:" << endl;
	cout<< conf->filesavepath<<endl;
	cout << "�洢���ݼ�¼�ļ����ļ���:" << endl;
	cout<< conf->filename<<endl;
	cout << "���ɵļ�¼����:" << endl;
	cout<< conf->number<<endl;
	cout << "���ɵ����ݼ�¼��Ԫ���е�1��2��Ԫ��ȡֵ������:" << endl;
	cout<<conf->maxvalue1 <<endl;
	cout << "���ɵ����ݼ�¼��Ԫ���е�1��2��Ԫ��ȡֵ������:" << endl;
	cout<< conf->minvalue1<<endl;
	cout << "���ɵ����ݼ�¼��Ԫ���е�3��Ԫ��ȡֵ������:" << endl;
	cout<< conf->maxvalue2<<endl;
	cout << "���ɵ����ݼ�¼��Ԫ���е�3��Ԫ��ȡֵ������:" << endl;
	cout<<conf->minvalue2 <<endl;
	cout << "������ݼ�¼�ļ���Ҫ������ɼ�¼����ʱ����ֵ������:" << endl;
	cout<< conf->recordcount1<<endl;
	cout << "������ݼ�¼�ļ���Ҫ������ɼ�¼����ʱ����ֵ������:" << endl;
	cout<< conf->recordcount2<<endl;
}

//��ӡ����_��ά����
void printarry(int** arr, int len) {
	int i;
	for (i = 0; i < len; i++) {
		printf("%d %d %d\n", arr[i][0], arr[i][1], arr[i][2]);
	}
}

//��ӡ����_�ṹ��
void printstruct(DATAITEM* arr,int len) {
	int i;
	for (i = 0; i < len; i++) {
			printf("%d %d %d\n", arr[i].item1, arr[i].item2, arr[i].item3);
		}
}

//��ӡ�ṹ��ָ��
void printpstruct(DATAITEM** arr, int len) {
	int i;
	for (i = 0; i < len; i++) {
		printf("%d %d %d\n", arr[i]->item1, arr[i]->item2, arr[i]->item3);
	}
}

//��ӡ����_����
// ע:pΪ��һ�����ݽڵ�
void printlist(Node* p) {
	while (p != NULL) {
		printf("%d %d %d\n", p->data.item1, p->data.item2, p->data.item3);
		p = p->next;
	}
}