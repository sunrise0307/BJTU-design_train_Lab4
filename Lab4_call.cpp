#define _CRT_SECURE_NO_WARNINGS
#include "Lab4_data.h"
#include "Lab4_call.h"
#include "Lab4_loadfile.h"
using namespace std;

//����ʵ�����������ݼ�¼�ļ�
void prod() {

    //�Զ�ģʽ
    if (mode == "auto") {
        cout << "aotoģʽ" << endl;
        int num;
        srand(time(NULL));
        CONF* conf;
        conf = (CONF*)malloc(sizeof(CONF));
        //�½�һ��conf�ṹ�壬����ռ�
        readconf(conf);
        num = conf->recordcount2 + rand() % (conf->recordcount1 - conf->recordcount2 + 1);
        system("Lab3.exe num ..\\default.txt");
    }

    //����ģʽ
    else if (mode == "interact") {
        string cmd;

        //lab3��ִ���ļ���
        string lab3 = "Lab3.exe";

        cout << "�����ļ��Ĵ洢λ�ú��ļ����ͼ�¼��������,�Կո�ָ�" << endl;
        cin >> loc >> fname >> num1;

        lab3 += " ";
        lab3 += loc;
        lab3 += "\\";
        lab3 += fname;
        lab3 += " ";
        lab3 += num1;
        cmd = lab3;
        system(cmd.c_str());
    }
}