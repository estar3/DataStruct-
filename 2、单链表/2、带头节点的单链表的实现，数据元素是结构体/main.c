#include "linklist2.h"

int main()
{
  LinkList LL=NULL; // 声明链表指针变量。

  LL=InitList1();     // 初始化链表。

  // 如果要在函数中对变量进行赋值，必须把变量的地址传入函数。
  // 指针变量简称指针，如果要在函数中对指针变量赋值，也必须把指针的地址传入函数。
  // LL是指针，在InitList2函数中，需要把头结点的地址赋值给LL，所以要传入LL的地址。
  // 指针是变量，用于存放变量的地址，指针不是地址，指针里存放的内容才是地址。
  // 所以，这里要把指针变量LL的地址传给InitList2()函数。
  // 各位菜鸡，明白鸟吗？
  // InitList2(&LL);     // 初始化链表，传入指针变量LL的地址。

  // InitList3(LL);      // 初始化链表，C++的引用。

  // 如果参数采用转指针LL的值，LL的值只能传进去，无法返回，这种方法是不行的。
  // InitList4(LL);

  printf("LL=%p\n",LL);

  ElemType ee;      // 创建一个数据元素。

  printf("在表中插入元素（1、2、3、4、5、6、7、8、9、10）。\n");
  ee.no=1;  strcpy(ee.name,"妲己");   InsertList(LL, 1, &ee);
  ee.no=2;  strcpy(ee.name,"褒姒");   InsertList(LL, 1, &ee);
  ee.no=3;  strcpy(ee.name,"西施");   InsertList(LL, 1, &ee);
  ee.no=4;  strcpy(ee.name,"王昭君"); InsertList(LL, 1, &ee);
  ee.no=5;  strcpy(ee.name,"貂蝉");   InsertList(LL, 1, &ee);
  ee.no=6;  strcpy(ee.name,"杨玉环"); InsertList(LL, 1, &ee);
  ee.no=7;  strcpy(ee.name,"赵飞燕"); InsertList(LL, 1, &ee);
  ee.no=8;  strcpy(ee.name,"萧美娘"); InsertList(LL, 1, &ee);
  ee.no=9;  strcpy(ee.name,"陈圆圆"); InsertList(LL, 1, &ee);
  ee.no=10; strcpy(ee.name,"李师师"); InsertList(LL, 1, &ee);

  printf("length=%d\n",LengthList(LL));

  PrintList(LL);

  printf("在第5个位置插入元素（13）。\n");
  memset(&ee,0,sizeof(ElemType)); ee.no=13; InsertList(LL, 5, &ee);  

  PrintList(LL);

  printf("在表头插入元素（11），表尾插入元素（12）。\n");
  memset(&ee,0,sizeof(ElemType)); ee.no=11; PushFront(LL, &ee);
  memset(&ee,0,sizeof(ElemType)); ee.no=12; PushBack(LL, &ee);

  PrintList(LL);

  printf("删除表中第7个结点。\n");
  DeleteNode(LL,7); PrintList(LL);

  printf("删除表中第一个结点。\n");
  PopFront(LL); PrintList(LL);

  printf("删除表中最后一个结点。\n");
  PopBack(LL); PrintList(LL);

  LNode *tmp;

  if ( (tmp=LocateNode(LL,3)) != NULL)
    printf("第3个结点的地址是=%p，ee.no=%d\n",tmp,tmp->data.no);

  memset(&ee,0,sizeof(ElemType)); ee.no=8;
  if ( (tmp=LocateElem(LL,&ee)) != NULL)
    printf("元素值为8的结点的地址是=%p\n",tmp);
  else
    printf("元素值为8的结点的地址是NULL，没找着。\n");

  printf("在结点%p之后插入66\n",tmp);
  memset(&ee,0,sizeof(ElemType)); ee.no=66;
  InsertNextNode(tmp,&ee);  PrintList(LL);

  printf("在结点%p之前插入55\n",tmp);
  memset(&ee,0,sizeof(ElemType)); ee.no=55;
  InsertPriorNode(tmp,&ee);  PrintList(LL);

  PrintList1(LL);

  DestroyList1(LL); LL=NULL;  // 销毁链表，LL置为空。
  // DestroyList2(&LL);       // 销毁链表，传入指针的地址，LL在函数中会置为空。
  // DestroyList3(LL);       // 销毁链表，C++的引用，LL在函数中会置为空。

  printf("LL=%p\n",LL);

  return 0;
}