#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include<stdlib.h>
#include<iostream>
#include "Lab4_sort.h"
#include "Lab4_timelong.h"
#include "Lab4_data.h"
#include "Lab4_main.h"
#include "Lab4_loadfile.h"
#include "Lab4_call.h"
#include "Lab4_conf.h"
#include "Lab4_view.h"
void cmp_timelong() {
	int n,i=0;
	cout << "��������׼��������ʵ��,���Ƚϸ��������ʱ��" << endl;
	cin >> n;
	while (i<n) {
		i++;
		/*
		CONF conf;
		readconf(&conf);
		rs_lab3_arg(&conf);
		rmode();
		prod();
		ReadFile(full_path_nm.c_str(), 1, 1);
		ReadFile(full_path_nm.c_str(), 2, 1);
		ReadFile(full_path_nm.c_str(), 3, 1);
		ReadFile(full_path_nm.c_str(), 4, 1);
		ReadFile(full_path_nm.c_str(), 4, 1);*/
		//1,����14���ܸı����ݲ���
		//2,����10.11.12.13���ܻ�ȡ������ʼ�ͽ���ʱ��
		run();
		printf("\n\n----------------------------------------------------------------------------------------------------\n");
		cout << "��" << i << "��ʵ����" << endl;
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("qsort����ʱ��:\n");
		printf("��ά����\t");
		printf("�ṹ������\t");
		printf("�ṹ��ָ������\t");
		printf("\n");
		printf("%lf\t", timelong(bgtime_arr, edtime_arr));
		printf("%lf\t", timelong(bgtime_struct, edtime_struct));
		printf("%lf\t", timelong(bgtime_pstruct, edtime_pstruct));


		printf("\n");
		printf("---------------------------------------------------------------------------------------------------------\n");
		cout << "������ݼ�����ʱ��" << endl;
		printf("---------------------------------------------------------------------------------------------------------\n");
		printf("ð������\t");
		printf("��������\t");
		printf("\n");
		printf("%lf\t", timelong(bgtime_p_randata, edtime_p_randata));
		printf("%lf\t", timelong(bgtime_q_randata, edtime_q_randata));

		printf("\n");
		printf("----------------------------------------------------------------------------------------------------------\n");
		cout << "�������ݼ�����ʱ��" << endl;
		printf("----------------------------------------------------------------------------------------------------------\n");
		printf("ð������\t");
		printf("��������\t");
		printf("\n");
		printf("%lf\t", timelong(bgtime_p_pdata, edtime_p_pdata));
		printf("%lf\t", timelong(bgtime_q_pdata, edtime_q_pdata));

		printf("\n");
		printf("----------------------------------------------------------------------------------------------------------\n");
		cout << "�������ݼ�����ʱ��" << endl;
		printf("----------------------------------------------------------------------------------------------------------\n");
		printf("ð������\t");
		printf("��������\t");
		printf("\n");
		printf("%lf\t", timelong(bgtime_p_rdata, edtime_p_rdata));
		printf("%lf\t", timelong(bgtime_q_rdata, edtime_q_rdata));

	}



}

double timelong(clock_t bg,clock_t ed) {
	return (double)(ed - bg) / CLOCKS_PER_SEC;
}