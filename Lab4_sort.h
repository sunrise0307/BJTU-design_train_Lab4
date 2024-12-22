#pragma once
#include "Lab4_data.h"

//冒泡排序,正序
struct Node* bubbleSort_p(struct Node* head);

//冒泡排序,逆序
struct Node* bubbleSort_r(struct Node* head);

//快速排序,正序
struct Node* quickSort_p(struct Node* head);

//快速排序,逆序
struct Node* quickSort_r(struct Node* head);

//二维数组比较函数
int cmp_arr(const void* a, const void* b);

//结构体比较函数
int cmp_struct(const void* a, const void* b);

//结构体指针数组比较函数
int cmp_pstruct(const void* a, const void* b);