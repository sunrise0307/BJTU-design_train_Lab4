#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include "Lab4_data.h"
#include "Lab4_conf.h"
#include "Lab4_loadfile.h"
#include "Lab4_view.h"
using namespace std;

//修改实验三配置文件
void rs_lab3_arg(CONF* conf) {
    int opt = -1;

    //指示选择的项目
    while (opt != 0) {

        readconf(conf);
        printconf(conf);

        printf("\n请选择要修改的配置文件项：\n");
        printf("请输入对应的操作序号(输入0可以退出)：\n");
        printf("1. 更改1，2个元素的最大值\n");
        printf("2. 更改1，2个元素的最小值\n");
        printf("3. 更改第3个元素的最大值\n");
        printf("4. 更改第3个元素的最小值\n");
        printf("5. 更改数据记录条数的最大值\n");
        printf("6. 更改数据记录条数的最小值\n");
        cout << "7. 更改存放数据记录文件的存储目录" << endl;
        cout << "8. 更改存储数据记录文件的文件名" << endl;
        printf("9.更改记录条数\n");
       
        scanf("%d", &opt);
        getchar();

        if (opt == 1) {
            cout << "请输入新的第1个和第2个元素的最大值:" << endl;
            cin >> conf->maxvalue1;
            getchar();
        }
        else if (opt == 2) {
            cout << "请输入新的第1个和第2个元素的最小值:" << endl;
            cin >> conf->minvalue1;
            getchar();
        }
        else if (opt == 3) {
            cout << "请输入新的第3个元素的最大值:" << endl;
            cin >> conf->maxvalue2;
            getchar();
        }
        else if (opt == 4) {
            cout << "请输入新的第3个元素的最小值:" << endl;
            cin >> conf->minvalue2;
            getchar();
        }
        else if (opt == 5) {
            cout << "请输入新的数据记录文件需要随机生成记录条数时条数值的下限:" << endl;
            cin >> conf->recordcount2;
            getchar();
        }
        else if (opt == 6) {
            cout << "请输入新的数据记录文件需要随机生成记录条数时条数值的上限:" << endl;
            cin >> conf->recordcount1;
            getchar();
        }
        else if (opt == 7) {
            string str;
            cout << "请输入新的存放数据记录文件的存储目录:" << endl;
            getline(cin, str);
            
            strcpy(conf->filesavepath, str.c_str());
        }
        else if (opt == 8) {
            string str;
            cout << "请输入新的数据记录文件的名称:" << endl;
            cin >> str;
            getchar();
            strcpy(conf->filesavepath, str.c_str());
        }
        else if (opt == 9) {
            cout << "请输入新的数据记录数:" << endl;
            cin >> conf->number;
            getchar();
        }

        //写入实验三配置文件
        put_f(conf);
    }
}

//写入实验三配置文件
    ofstream fp;
	fp.open("..//conf.ini.txt", ios::out || ios::trunc);//trunc表示清空之前所有内容
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
    cout << "保存记录成功" << endl;
}

//修改实验四工作模式
void rs_lab4_mode() {
    string m;
    ifstream fp("..//info.txt", ios::in);
    fp >> m;
    fp.close();
    cout << "实验四当前工作模式是" << m<<endl;
    cout << "你可以输入auto或者interact" << endl;
    cin >> m;
    ofstream fp2("..//info.txt", ios::trunc);//存在则删,否则新建
    fp2 << m;
}
