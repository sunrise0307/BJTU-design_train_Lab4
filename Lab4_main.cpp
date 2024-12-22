#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<malloc.h>
#include "Lab4_data.h"
#include "Lab4_loadfile.h"
#include "Lab4_call.h"
#include "Lab4_conf.h"

using namespace std;

//ȫ�ֱ�������
//ע��:�ⲿ�������붨��Ϊȫ�ֵ�,�����Ͷ����������һ��
string mode = "";
string loc = "..", fname = "default.txt", num1="";
string full_path_nm="";

string sumstr() {
    string str="";
    str.append(loc);
    str.append("\\");
    str.append(fname);
    return str;
}

//�������غ���
int run() {

    int n;

    //�˵���ʾ
    printf("\n");
    printf("sunrise��ʵ��4����\n");
    printf("1. ����ʵ��3�������ɼ�¼�ļ�\n");
    printf("2.��ȡָ�����ݼ�¼�ļ�����ά����洢��ʽ��\n");
    printf("3.��ȡָ�����ݼ�¼�ļ����ṹ������洢��ʽ��\n");
    printf("4.��ȡָ�����ݼ�¼�ļ���ָ������洢��ʽ��\n");
    printf("5.��ȡָ�����ݼ�¼�ļ�������洢��ʽ��\n");
    printf("6. ����ʵ��3�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ�����ά���鷽ʽ�洢��\n");
    printf("7. ����ʵ��3�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ����ṹ�����鷽ʽ�洢��\n");
    printf("8. ����ʵ��3�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ���ָ�����鷽ʽ�洢��\n");
    printf("9. ����ʵ��3�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ�������ʽ�洢��\n");
    printf("10. ����ʵ��3�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ������򣨶�ά���鷽ʽ�洢��\n");
    printf("11. ����ʵ��3�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ������򣨽ṹ�����鷽ʽ�洢��\n");
    printf("12. ����ʵ��3�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ�������ָ�����鷽ʽ�洢��\n");
    printf("13. ����ʵ��3�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ�����������ʽ�洢��\n");
    printf("14. �����������ò���ֵ\n");
    printf("15, ��������ʵ��4����ģʽ\n");
    printf("0. �˳�\n");
    printf("��������Ҫִ�еĳ�����ţ�\n");
    
    cin >> n;
    getchar();

    CONF conf;
    
    while (n != 0) {
        
        switch (n) {
        case 1:
            rmode();
            prod(); 
            break;
        case 2:
            full_path_nm = sumstr();
            ReadFile(full_path_nm.c_str(), 1, 0); break;

        case 3:
            full_path_nm = sumstr();
            ReadFile(full_path_nm.c_str(), 2, 0); break;

        case 4:
            full_path_nm = sumstr();
            ReadFile(full_path_nm.c_str(), 3, 0); break;

        case 5:
            full_path_nm = sumstr();
            ReadFile(full_path_nm.c_str(), 4, 0); break;

        case 6:
            prod();
            full_path_nm = sumstr();
            ReadFile(full_path_nm.c_str(), 1, 0); break;

        case 7:
            prod();
            full_path_nm = sumstr();
            ReadFile(full_path_nm.c_str(), 2,0); break;

        case 8:
            prod();
            full_path_nm = sumstr();
            ReadFile(full_path_nm.c_str(), 3, 0); break;

        case 9:
            prod();
            full_path_nm=sumstr();
            ReadFile(full_path_nm.c_str(), 4, 0); break;

        case 10:
            prod();
            full_path_nm = sumstr();
            ReadFile(full_path_nm.c_str(), 1, 1); break;

        case 11:
            prod();
            full_path_nm = sumstr();
            ReadFile(full_path_nm.c_str(), 2, 1); break;

        case 12:
            prod();
            full_path_nm = sumstr();
            ReadFile(full_path_nm.c_str(), 3, 1); break;

        case 13:
            prod();
            full_path_nm = sumstr();
            ReadFile(full_path_nm.c_str(), 4, 1); break;

        case 14:
            
            rs_lab3_arg(&conf); break;

        case 15:
            rs_lab4_mode(); break;

        default:
            break;
        }

        printf("\n");
        printf("sunrise��ʵ��4����\n");
        printf("1. ����ʵ��3�������ɼ�¼�ļ�\n");
        printf("2.��ȡָ�����ݼ�¼�ļ�����ά����洢��ʽ��\n");
        printf("3.��ȡָ�����ݼ�¼�ļ����ṹ������洢��ʽ��\n");
        printf("4.��ȡָ�����ݼ�¼�ļ���ָ������洢��ʽ��\n");
        printf("5.��ȡָ�����ݼ�¼�ļ�������洢��ʽ��\n");
        printf("6. ����ʵ��3�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ�����ά���鷽ʽ�洢��\n");
        printf("7. ����ʵ��3�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ����ṹ�����鷽ʽ�洢��\n");
        printf("8. ����ʵ��3�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ���ָ�����鷽ʽ�洢��\n");
        printf("9. ����ʵ��3�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ�������ʽ�洢��\n");
        printf("10. ����ʵ��3�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ������򣨶�ά���鷽ʽ�洢��\n");
        printf("11. ����ʵ��3�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ������򣨽ṹ�����鷽ʽ�洢��\n");
        printf("12. ����ʵ��3�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ�������ָ�����鷽ʽ�洢��\n");
        printf("13. ����ʵ��3�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ�����������ʽ�洢��\n");
        printf("14. �����������ò���ֵ\n");
        printf("0. �˳�\n");
        printf("��������Ҫִ�еĳ�����ţ�\n");
        cin >> n;
        getchar();

    }
	return 0;

}
