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

//全局变量定义
//注意:外部变量必须定义为全局的,声明和定义的作用域一致
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

//程序主控函数
int run() {

    int n;

    //菜单显示
    printf("\n");
    printf("sunrise的实验4程序：\n");
    printf("1. 调用实验3程序生成记录文件\n");
    printf("2.读取指定数据记录文件（二维数组存储方式）\n");
    printf("3.读取指定数据记录文件（结构体数组存储方式）\n");
    printf("4.读取指定数据记录文件（指针数组存储方式）\n");
    printf("5.读取指定数据记录文件（链表存储方式）\n");
    printf("6. 调用实验3生成数据记录文件，同时读取数据记录文件（二维数组方式存储）\n");
    printf("7. 调用实验3生成数据记录文件，同时读取数据记录文件（结构体数组方式存储）\n");
    printf("8. 调用实验3生成数据记录文件，同时读取数据记录文件（指针数组方式存储）\n");
    printf("9. 调用实验3生成数据记录文件，同时读取数据记录文件（链表方式存储）\n");
    printf("10. 调用实验3生成数据记录文件，同时读取数据记录文件并排序（二维数组方式存储）\n");
    printf("11. 调用实验3生成数据记录文件，同时读取数据记录文件并排序（结构体数组方式存储）\n");
    printf("12. 调用实验3生成数据记录文件，同时读取数据记录文件并排序（指针数组方式存储）\n");
    printf("13. 调用实验3生成数据记录文件，同时读取数据记录文件并排序（链表方式存储）\n");
    printf("14. 重新设置配置参数值\n");
    printf("15, 重新设置实验4工作模式\n");
    printf("0. 退出\n");
    printf("请输入您要执行的程序序号：\n");
    
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
        printf("sunrise的实验4程序：\n");
        printf("1. 调用实验3程序生成记录文件\n");
        printf("2.读取指定数据记录文件（二维数组存储方式）\n");
        printf("3.读取指定数据记录文件（结构体数组存储方式）\n");
        printf("4.读取指定数据记录文件（指针数组存储方式）\n");
        printf("5.读取指定数据记录文件（链表存储方式）\n");
        printf("6. 调用实验3生成数据记录文件，同时读取数据记录文件（二维数组方式存储）\n");
        printf("7. 调用实验3生成数据记录文件，同时读取数据记录文件（结构体数组方式存储）\n");
        printf("8. 调用实验3生成数据记录文件，同时读取数据记录文件（指针数组方式存储）\n");
        printf("9. 调用实验3生成数据记录文件，同时读取数据记录文件（链表方式存储）\n");
        printf("10. 调用实验3生成数据记录文件，同时读取数据记录文件并排序（二维数组方式存储）\n");
        printf("11. 调用实验3生成数据记录文件，同时读取数据记录文件并排序（结构体数组方式存储）\n");
        printf("12. 调用实验3生成数据记录文件，同时读取数据记录文件并排序（指针数组方式存储）\n");
        printf("13. 调用实验3生成数据记录文件，同时读取数据记录文件并排序（链表方式存储）\n");
        printf("14. 重新设置配置参数值\n");
        printf("0. 退出\n");
        printf("请输入您要执行的程序序号：\n");
        cin >> n;
        getchar();

    }
	return 0;

}
