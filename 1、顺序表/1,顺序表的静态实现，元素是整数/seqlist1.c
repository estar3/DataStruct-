#include "seqlist1.h"

// 初始化顺序表
void InitList(PSeqList LL)
{
  ClearList(LL); // 清空顺序表。
}

// 清空顺序表。
void ClearList(PSeqList LL)
{
  if (LL == NULL) return;  // 检查空指针。

  LL->length=0;  // 表长置为0。
  memset(LL->data,0,sizeof(ElemType)*MAXSIZE);  // 数组元素清0。
}

// 求顺序表的长度，返回值：>=0-表LL元素的个数。
int LengthList(PSeqList LL)
{
  if (LL == NULL) return 0;  // 检查空指针。

  return LL->length;
}

// 获取顺序表中第ii个元素的值，存放在ee中，返回值：0-失败；1-成功。
int  GetElem(PSeqList LL, unsigned int ii, ElemType* ee)
{
  if ( (LL == NULL) || (ee == NULL) ) return 0;   // 检查空指针。
  
  // 判断位置ii是否合法
  if ( (ii < 1) || (ii > LL->length) ) return 0;

  //memcpy(ee,LL->data+ii-1,sizeof(ElemType));  // 采用memcpy是为了支持ee为结构体的情况。
  memcpy(ee,&LL->data[ii-1],sizeof(ElemType));   // 用数组的形式也可以。

  return 1;
}

// 在顺序表LL的第ii个位置插入元素ee，返回值：0-失败；1-成功。
int InsertList(PSeqList LL, unsigned int ii, ElemType *ee)
{
  if ( (LL == NULL) || (ee == NULL) ) return 0;   // 检查空指针。

  if (LL->length >= MAXSIZE)
  {
    printf("顺序表已满，不能插入。\n"); return 0;
  }

  // 判断插入位置是否合法
  if ( (ii < 1) || (ii > LL->length+1) )
  {
    printf("插入位置（%d）不合法，应该在（%d-%d）之间。\n",ii,1,LL->length+1); return 0;
  }

  // 注意，元素后移只能用循环，不能用以下注释掉的方法，当元素是结构体时，以下方法不稳定。
  // if ( ii < LL->length+1)
  //    memcpy(LL->data+ii,LL->data+ii-1,(LL->length-ii+1)*sizeof(ElemType));

  // 把ii和ii之后的元素后移。
  int kk;
  for (kk=LL->length;kk>=ii;kk--)
  {
    // memcpy(LL->data+kk,LL->data+kk-1,sizeof(ElemType));  // 采用memcpy是为了支持ee为结构体的情况。
    memcpy(&LL->data[kk],&LL->data[kk-1],sizeof(ElemType));  // 用数组的形式也可以。
  }

  //memcpy(LL->data+ii-1,ee,sizeof(ElemType));  // 采用memcpy是为了支持ee为结构体的情况。
  memcpy(&LL->data[ii-1],ee,sizeof(ElemType));  // 用数组的形式也可以。
  LL->length++;       // 表的长度加1。

  return 1;
}

// 在顺序表LL的头结点插入元素ee，返回值：0-失败；1-成功。
int  PushFront(PSeqList LL, ElemType *ee)
{
  return InsertList(LL,1,ee);
}

// 在顺序表LL的尾结点插入元素ee，返回值：0-失败；1-成功。
int PushBack(PSeqList LL, ElemType *ee)
{
  return InsertList(LL,LL->length+1,ee);
}

// 删除顺序表LL中的第ii个元素，返回值：0-位置ii不合法；1-成功。
int DeleteElem(PSeqList LL, unsigned int ii)
{
  if (LL == NULL) return 0;   // 检查空指针。

  // 判断删除位置ii是否合法
  if ( (ii < 1) || (ii > LL->length) )
  {
    printf("删除位置（%d）不合法，应该在（%d-%d）之间\n",ii,1,LL->length); return 0;
  }

  // 把ii之后的元素前移。
  int k;
  for (k=ii;k<=LL->length;k++)
  {
    // memcpy(LL->data+k-1,LL->data+k,sizeof(ElemType));  // 采用memcpy是为了支持ee为结构体的情况。
    memcpy(&LL->data[k-1],&LL->data[k],sizeof(ElemType));   // 用数组的形式也可以。
  }

  LL->length--;       // 表的长度减1。

  return 1;
}

// 查找ee在顺序表LL中的位置，返回值：0-元素ee在表LL中不存在，>0元素ee在表LL中的位置。
int LocateElem(PSeqList LL, ElemType *ee)
{
  if ( (LL == NULL) || (ee == NULL) ) return 0;   // 检查空指针。

  int kk;

  for (kk = 0; kk < LL->length; kk++)
  {
    // 如果元素ee为结构体，这行代码要修改。
    // if (*(LL->data+kk) == *ee) return kk+1; // 在表中对应序号应为kk+1。
    if (LL->data[kk] == *ee) return kk+1; // 用数组的形式也可以。
  }
    
  return 0;
}

// 删除顺序表LL中头元素，返回值：0-位置ii不合法；1-成功。
int PopFront(PSeqList LL)
{
  return DeleteElem(LL, 1);
}

// 删除顺序表LL中尾元素，返回值：0-位置ii不合法；1-成功。
int PopBack(PSeqList LL)
{
  return DeleteElem(LL, LL->length);
}

// 判断顺序表是否为空，返回值：1-空，0-非空或失败。
int IsEmpty(PSeqList LL)
{
  if (LL == NULL) return 0;   // 检查空指针。

  if (LL->length == 0) return 1;

  return 0;
}

// 打印顺序表中全部的元素。
void PrintList(PSeqList LL)
{
  if (LL == NULL) return;   // 检查空指针。

  if (LL->length == 0) { printf("表为空。\n"); return; }

  int kk;
  for (kk = 0; kk < LL->length; kk++)
  {
    // printf("%-3d", *(LL->data+kk));  // 如果元素ee为结构体，这行代码要修改。
    printf("%-3d", LL->data[kk]);  // 用数组的形式也可以。
  }

  printf("\n");
}

// 采用归并的方法，将两个升序的顺序表La和Lb，合并成一个升序的顺序表Lc。
int MergeList(PSeqList La,PSeqList Lb,PSeqList Lc)
{
  if ( (La == NULL) || (Lb == NULL) || (Lc == NULL) )   // 检查空指针。

  if ( MAXSIZE < La->length + Lb->length ) { printf("表Lc的长度不够。\n"); return 0; }

  int istartla=0;  // 表La第一个元素的位置。
  int istartlb=0;  // 表Lb第一个元素的位置。
  int istartlc=0;  // 表Lc第一个元素的位置。

  // 把La和Lb合并到Lc中。
  while (istartla < La->length && istartlb < Lb->length)
    Lc->data[istartlc++]=La->data[istartla]<Lb->data[istartlb] ? La->data[istartla++] : Lb->data[istartlb++];

  // 把La其它的元素追加到Lc中。
  while (istartla < La->length) Lc->data[istartlc++]=La->data[istartla++];

  // 把Lb其它的元素追加到Lc中。
  while (istartlb < Lb->length) Lc->data[istartlc++]=Lb->data[istartlb++];

  Lc->length=La->length + Lb->length;

  return 1;
}

// 销毁顺序表LL。
void DestroyList(PSeqList LL)
{
  // 静态顺序表无需释放内存，不需要销毁操作。
  return;
}