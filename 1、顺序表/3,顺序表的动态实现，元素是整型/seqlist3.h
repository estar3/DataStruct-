/*
 * 程序名：seqlist3.c，此程序演示顺序表的动态实现，数据元素是整数。
*/

#ifndef _SEQLIST3_H
#define _SEQLIST3_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INITSIZE 10        // 顺序表的初始长度。
#define EXTSIZE   5        // 每次扩展元素的个数。

typedef int ElemType;      // 自定义顺序表的数据元素为整数。

typedef struct
{
  ElemType *data;           // 存储顺序表中元素的首地址。
  unsigned int maxsize;     // 顺序表元素的最大长度。
  unsigned int length;      // 顺序表中元素的个数。
}SeqList,*PSeqList;

// 顺序表LL的初始化操作。
void InitList(PSeqList LL);                     

// 销毁顺序表LL。
void DestroyList(PSeqList LL);

// 扩展顺序表的内存空间，返回值：0-失败；1-成功。
int ExtList(PSeqList LL);

// 在顺序表LL的第ii个位置插入元素ee，返回值：0-失败；1-成功。
int  InsertList(PSeqList LL, unsigned int ii, ElemType *ee);   

// 在顺序表LL的头结点插入元素ee，返回值：0-失败；1-成功。
int  PushFront(PSeqList LL, ElemType *ee);

// 在顺序表LL的尾结点插入元素ee，返回值：0-失败；1-成功。
int  PushBack(PSeqList LL, ElemType *ee);

// 求顺序表的长度，返回值：>=0-表LL元素的个数。
int  LengthList(PSeqList LL);                   

// 获取顺序表中第ii个元素的值，存放在ee中，返回值：0-失败；1-成功。
int  GetElem(PSeqList LL, unsigned int ii, ElemType* ee);  

// 清空顺序表。
void ClearList(PSeqList LL);                    

// 判断顺序表是否为空，返回值：1-空，0-非空或失败。
int  IsEmpty(PSeqList LL);                    

// 打印顺序表中全部的元素。
void PrintList(PSeqList LL);                    

// 查找ee在顺序表LL中的位置，返回值：0-元素ee在表LL中不存在，>0元素ee在表LL中的位置。
int  LocateElem(PSeqList LL, ElemType *ee);

// 删除顺序表LL中的第ii个元素，返回值：0-位置ii不合法；1-成功。
int  DeleteElem(PSeqList LL, unsigned int ii);  

// 删除顺序表LL中头元素，返回值：0-位置ii不合法；1-成功。
int PopFront(PSeqList LL);

// 删除顺序表LL中尾元素，返回值：0-位置ii不合法；1-成功。
int PopBack(PSeqList LL);

#endif