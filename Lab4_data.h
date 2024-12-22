#pragma once
#define  MAX_STR_LEN  255   
#include<string>
#include<string>
#include<time.h>
using namespace std;

//��Ԫ��ṹ��
typedef  struct  DataItem {
	int  item1;     //���ݼ�¼��Ԫ���һ��Ԫ��
	int  item2;     //���ݼ�¼��Ԫ��ڶ���Ԫ��
	int  item3;     //���ݼ�¼��Ԫ�������Ԫ��
} DATAITEM;

//����ڵ�
typedef struct Node {
	DATAITEM data;
	Node* next;
}Node, * PNode;

//����ṹ,��ͷ���
typedef struct LinkList {
	Node* head;
}LinkList;

//�����ļ��ṹ��,9������
typedef struct configinfo {
	char  filesavepath[MAX_STR_LEN];     	//���ڴ�����ݼ�¼�ļ��Ĵ洢Ŀ¼
	char  filename[MAX_STR_LEN];              //���ڴ洢���ݼ�¼�ļ����ļ�����Ϣ
	int  number;		//���ڴ�����ɵļ�¼����
	int  maxvalue1;   		//���ڴ��ʵ��2�����ɵ����ݼ�¼��Ԫ���е�1��2��Ԫ��ȡֵ������
	int  minvalue1; 		//���ڴ��ʵ��2�����ɵ����ݼ�¼��Ԫ���е�1��2��Ԫ��ȡֵ������
	int  maxvalue2;   		//���ڴ��ʵ��2�����ɵ����ݼ�¼��Ԫ���е�3��Ԫ��ȡֵ������
	int  minvalue2; 		//���ڴ��ʵ��2�����ɵ����ݼ�¼��Ԫ���е�3��Ԫ��ȡֵ������
	int  recordcount1;	//���ڴ�����ݼ�¼�ļ���Ҫ������ɼ�¼����ʱ����ֵ������
	int  recordcount2;	//���ڴ�����ݼ�¼�ļ���Ҫ������ɼ�¼����ʱ����ֵ������
} CONF;

extern string full_path_nm;

//ʵ���Ĺ���ģʽ
extern string mode;

//Lab3���ݼ�¼�ļ��Ĵ洢Ŀ¼
extern string loc;

//�洢���ݼ�¼�ļ����ļ�����Ϣ
extern string fname;

//������ɵļ�¼����
extern string num1;

//��ά����洢,��ʼʱ��
extern clock_t bgtime_arr;

//��ά����洢,����ʱ��
extern clock_t edtime_arr;

//�ṹ������洢,��ʼʱ��
extern clock_t bgtime_struct;

//�ṹ������洢����ʱ��
extern clock_t edtime_struct;

//�ṹ��ָ������洢��ʼʱ��
extern clock_t bgtime_pstruct;

//�ṹ��ָ������洢����ʱ��
extern clock_t edtime_pstruct;



//���ſ�ʼʱ��,�������
extern clock_t bgtime_q_randata;

//���ſ�ʼʱ��,��������
extern clock_t bgtime_q_pdata;

//���ſ�ʼʱ��,��������
extern clock_t bgtime_q_rdata;

//���Ž���ʱ��,�������
extern clock_t edtime_q_randata;

//���Ž���ʱ��,��������
extern clock_t edtime_q_pdata;

//���Ž���ʱ��,��������
extern clock_t edtime_q_rdata;


//ð�ݿ�ʼʱ��,�������
extern clock_t bgtime_p_randata;

//ð�ݿ�ʼʱ��,��������
extern clock_t bgtime_p_pdata;

//ð�ݿ�ʼʱ��,��������
extern clock_t bgtime_p_rdata;

//ð�ݽ���ʱ��,�������
extern clock_t edtime_p_randata;

//ð�ݽ���ʱ��,��������
extern clock_t edtime_p_pdata;

//ð�ݽ���ʱ��,��������
extern clock_t edtime_p_rdata;