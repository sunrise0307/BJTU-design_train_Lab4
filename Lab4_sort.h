#pragma once
#include "Lab4_data.h"

//ð������,����
struct Node* bubbleSort_p(struct Node* head);

//ð������,����
struct Node* bubbleSort_r(struct Node* head);

//��������,����
struct Node* quickSort_p(struct Node* head);

//��������,����
struct Node* quickSort_r(struct Node* head);

//��ά����ȽϺ���
int cmp_arr(const void* a, const void* b);

//�ṹ��ȽϺ���
int cmp_struct(const void* a, const void* b);

//�ṹ��ָ������ȽϺ���
int cmp_pstruct(const void* a, const void* b);