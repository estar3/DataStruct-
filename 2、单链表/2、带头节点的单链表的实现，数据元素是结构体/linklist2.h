/*
 * 程序名：linklist2.c，此程序演示带头结点的单链表的实现，数据元素是结构体。
 * 作者：C语言技术网(www.freecplus.net) 日期：20201230
*/
#ifndef _LINKLIST2_H
#define _LINKLIST2_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
  int  no;        // 超女编号。
  char name[31];  // 超女姓名。
}ElemType;        // 自定义顺序表的数据元素为结构体。

typedef struct LNode
{
  ElemType data;       // 存放结点的数据元素。
  struct LNode *next;  // 指向下一个结点的指针。
}LNode,*LinkList;

// 初始化链表LL，返回值：失败返回NULL，成功返回头结点的地址。
LNode *InitList1();

// 传入指针变量的地址的方法。
// 初始化链表，返回值：0-失败；1-成功。
int InitList2(LinkList *LL);

// C++引用的方法，在Linux下，需要用g++编译。
// 初始化链表，返回值：0-失败；1-成功。
// int InitList3(LinkList &LL);

// 如果参数采用转指针LL的值，LL的值只能传进去，无法返回，这种方法是不行的。
int InitList4(LinkList LL);

// 销毁链表LL。
void DestroyList1(LinkList LL);

// 销毁链表LL。
// 传入指针的地址的方法。
void DestroyList2(LinkList *LL);

// C++引用的方法，在Linux下，需要用g++编译。
// 传入指针的地址的方法。
// void DestroyList3(LinkList &LL);

// 清空链表。
void ClearList(LinkList LL);                    

// 在链表LL的第ii个位置插入元素ee，返回值：0-失败；1-成功。
int  InsertList(LinkList LL, unsigned int ii, ElemType *ee);   

// 打印链表中全部的元素。
void PrintList(LinkList LL);                    

// 打印链表中全部的元素，包括超女编号和姓名。
void PrintList1(LinkList LL);

// 在链表LL的头部插入元素ee，返回值：0-失败；1-成功。
int  PushFront(LinkList LL, ElemType *ee);

// 在链表LL的尾部插入元素ee，返回值：0-失败；1-成功。
int  PushBack(LinkList LL, ElemType *ee);

// 删除链表LL中的第ii个结点，返回值：0-位置ii不合法；1-成功。
int  DeleteNode(LinkList LL, unsigned int ii);  

// 删除链表LL中第一个结点，返回值：0-位置不合法；1-成功。
int PopFront(LinkList LL);

// 删除链表LL中最后一个结点，返回值：0-位置不合法；1-成功。
int PopBack(LinkList LL);

// 求链表的长度，返回值：>=0-表LL结点的个数。
int  LengthList(LinkList LL);                   

// 判断链表是否为空，返回值：0-非空或失败，1-空。
int IsEmpty(LinkList LL);

// 获取链表中第ii个结点，成功返回结点的地址，失败返回空。
// 注意，ii可以取值为0，表示头结点。
LNode *LocateNode(LinkList LL, unsigned int ii);

// 查找元素ee在链表LL中的结点地址，如果没找到返回NULL，否则返回结点的地址。
LNode *LocateElem(LinkList LL, ElemType *ee);

// 在指定结点pp之后插入元素ee，返回值：0-失败；1-成功。
int InsertNextNode(LNode *pp, ElemType *ee);

// 在指定结点pp之前插入元素ee，返回值：0-失败；1-成功。
int InsertPriorNode(LNode *pp, ElemType *ee);

// 删除指定结点。
int DeleteNode1(LNode *pp);

#endif