#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include "Lab4_data.h"
#include "Lab4_conf.h"
#include "Lab4_loadfile.h"
#include "Lab4_view.h"
using namespace std;

//�޸�ʵ���������ļ�
void rs_lab3_arg(CONF* conf) {
    int opt = -1;

    //ָʾѡ�����Ŀ
    while (opt != 0) {

        readconf(conf);
        printconf(conf);

        printf("\n��ѡ��Ҫ�޸ĵ������ļ��\n");
        printf("�������Ӧ�Ĳ������(����0�����˳�)��\n");
        printf("1. ����1��2��Ԫ�ص����ֵ\n");
        printf("2. ����1��2��Ԫ�ص���Сֵ\n");
        printf("3. ���ĵ�3��Ԫ�ص����ֵ\n");
        printf("4. ���ĵ�3��Ԫ�ص���Сֵ\n");
        printf("5. �������ݼ�¼���������ֵ\n");
        printf("6. �������ݼ�¼��������Сֵ\n");
        cout << "7. ���Ĵ�����ݼ�¼�ļ��Ĵ洢Ŀ¼" << endl;
        cout << "8. ���Ĵ洢���ݼ�¼�ļ����ļ���" << endl;
        printf("9.���ļ�¼����\n");
       
        scanf("%d", &opt);
        getchar();

        if (opt == 1) {
            cout << "�������µĵ�1���͵�2��Ԫ�ص����ֵ:" << endl;
            cin >> conf->maxvalue1;
            getchar();
        }
        else if (opt == 2) {
            cout << "�������µĵ�1���͵�2��Ԫ�ص���Сֵ:" << endl;
            cin >> conf->minvalue1;
            getchar();
        }
        else if (opt == 3) {
            cout << "�������µĵ�3��Ԫ�ص����ֵ:" << endl;
            cin >> conf->maxvalue2;
            getchar();
        }
        else if (opt == 4) {
            cout << "�������µĵ�3��Ԫ�ص���Сֵ:" << endl;
            cin >> conf->minvalue2;
            getchar();
        }
        else if (opt == 5) {
            cout << "�������µ����ݼ�¼�ļ���Ҫ������ɼ�¼����ʱ����ֵ������:" << endl;
            cin >> conf->recordcount2;
            getchar();
        }
        else if (opt == 6) {
            cout << "�������µ����ݼ�¼�ļ���Ҫ������ɼ�¼����ʱ����ֵ������:" << endl;
            cin >> conf->recordcount1;
            getchar();
        }
        else if (opt == 7) {
            string str;
            cout << "�������µĴ�����ݼ�¼�ļ��Ĵ洢Ŀ¼:" << endl;
            getline(cin, str);
            
            strcpy(conf->filesavepath, str.c_str());
        }
        else if (opt == 8) {
            string str;
            cout << "�������µ����ݼ�¼�ļ�������:" << endl;
            cin >> str;
            getchar();
            strcpy(conf->filesavepath, str.c_str());
        }
        else if (opt == 9) {
            cout << "�������µ����ݼ�¼��:" << endl;
            cin >> conf->number;
            getchar();
        }

        //д��ʵ���������ļ�
        put_f(conf);
    }
}

//д��ʵ���������ļ�
    ofstream fp;
	fp.open("..//conf.ini.txt", ios::out || ios::trunc);//trunc��ʾ���֮ǰ��������
    fp << conf->filesavepath<<endl;
    fp << conf->filename<<endl;
    fp << conf->number << endl;
    fp << conf->maxvalue1 << endl;
    fp << conf->minvalue1 << endl;
    fp << conf->maxvalue2 << endl;
    fp << conf->minvalue2 << endl;
    
    fp << conf->recordcount1 << endl;
    fp << conf->recordcount2 << endl;
    fp.close();
    cout << "�����¼�ɹ�" << endl;
}

//�޸�ʵ���Ĺ���ģʽ
void rs_lab4_mode() {
    string m;
    ifstream fp("..//info.txt", ios::in);
    fp >> m;
    fp.close();
    cout << "ʵ���ĵ�ǰ����ģʽ��" << m<<endl;
    cout << "���������auto����interact" << endl;
    cin >> m;
    ofstream fp2("..//info.txt", ios::trunc);//������ɾ,�����½�
    fp2 << m;
}
