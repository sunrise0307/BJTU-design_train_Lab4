#pragma once
#include <iostream>
#include "Lab4_data.h"

//��ȡʵ���Ĺ���ģʽ
void rmode();

//�ļ������ά����
int** load_arr(FILE*fp,int n);

//�ļ�����ṹ������
DATAITEM* load_struct(FILE* fp, int n);
//�������ļ���Ϣ���������ļ��ṹ��
void readconf(CONF* conf);

//��ȡʵ�����ļ�¼�ļ�
// is_sort=0��ʾԭʼ˳���ӡ,=1��ʾ������ӡ,����
void ReadFile(const char* filename, int num, int is_sort=0);
