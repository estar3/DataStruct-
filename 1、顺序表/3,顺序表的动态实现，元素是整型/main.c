#include "seqlist3.h"

int main()
{
  SeqList LL;     // 创建顺序表。

  ElemType ee;    // 创建一个数据元素。

  InitList(&LL);  // 初始化顺序表。

  printf("在表中插入元素（1、2、3、4、5、6、7、8、9、10）。\n");
  ee=1;  InsertList(&LL, 1, &ee);
  ee=2;  InsertList(&LL, 1, &ee);
  ee=3;  InsertList(&LL, 1, &ee);
  ee=4;  InsertList(&LL, 1, &ee);
  ee=5;  InsertList(&LL, 1, &ee);
  ee=6;  InsertList(&LL, 1, &ee);
  ee=7;  InsertList(&LL, 1, &ee);
  ee=8;  InsertList(&LL, 1, &ee);
  ee=9;  InsertList(&LL, 1, &ee);
  ee=10; InsertList(&LL, 1, &ee);

  PrintList(&LL);

  printf("在表头插入元素（11），表尾插入元素（12）。\n");
  ee=11; PushFront(&LL, &ee);
  ee=12; PushBack(&LL, &ee);

  PrintList(&LL);

  printf("在第5个位置插入元素（13）。\n");
  ee=13; InsertList(&LL, 5, &ee);  

  PrintList(&LL);

  printf("删除表中第7个元素。\n");
  DeleteElem(&LL,7); PrintList(&LL);

  printf("删除表头元素。\n");
  PopFront(&LL); PrintList(&LL);

  printf("删除表尾元素。\n");
  PopBack(&LL); PrintList(&LL);

  GetElem(&LL,3,&ee);
  printf("第3个元素的值是%d。\n",ee);

  ee=8;
  printf("元素值为8的位置是=%d\n",LocateElem(&LL,&ee));

  DestroyList(&LL);  // 销毁顺序表LL。

  return 0;
}