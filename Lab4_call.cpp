#define _CRT_SECURE_NO_WARNINGS
#include "Lab4_data.h"
#include "Lab4_call.h"
#include "Lab4_loadfile.h"
using namespace std;

//调用实验三生成数据记录文件
void prod() {

    //自动模式
    if (mode == "auto") {
        cout << "aoto模式" << endl;
        int num;
        srand(time(NULL));
        CONF* conf;
        conf = (CONF*)malloc(sizeof(CONF));
        //新建一个conf结构体，申请空间
        readconf(conf);
        num = conf->recordcount2 + rand() % (conf->recordcount1 - conf->recordcount2 + 1);
        system("Lab3.exe num ..\\default.txt");
    }

    //交互模式
    else if (mode == "interact") {
        string cmd;

        //lab3可执行文件名
        string lab3 = "Lab3.exe";

        cout << "输入文件的存储位置和文件名和记录条数参数,以空格分隔" << endl;
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