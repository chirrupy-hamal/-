#pragma once
//#ifndef
//#define
//
//#endif

//这两个，达到的目的都是一样的，防止头文件被重复引用

//#pragma once，它是从物理文件的角度去防止它被重复引用的，
//就是编译器发现SeqList.h被包含过了，它就不会再包含这个文件本身了，就只限于这一个文件，
//如果你把这个内容整体拷贝一份，起一个新名字，它还是可以包含进来的。

//而宏定义的话从内容上就保证了它不会被包含两次。

typedef int DataType;

#define MAXSIZE (10)                           //回去看一下？？？

//静态顺序表
typedef struct SeqList
{
	DataType array[MAXSIZE];
	int size;//1、保存了静态顺序表里面已存的数据个数
	         //2、当前可用下标
} SeqList;//顺序表的定义不是唯一的

                                  //大小？？？

//数据结构是一种抽象类型
//数据本身不仅仅是数字，甚至是所有的东西我们都可以将其抽象成数据，
//包括图片、声音等都是数据。

//接口（函数）
 
//1、初始化/销毁

//初始化成空表
void SeqListInit/*初始化，VS是支持汉字的*/(SeqList *pSeq);
                                        //1、传址，空间更小。
                                       //2、我们要改变它的内部值，所以只能通过传址，而不能用传值的方式。
//销毁静态顺序表
void SeqListDestroy(SeqList *pSeq);

//2、增/删/查/改

//尾插
void SeqListPushBack(SeqList *pSeq, DataType data);
//头插
void SeqListPushFront(SeqList *pSeq, DataType data);
//依据下标插入
void SeqListInsert(SeqList *pSeq, int pos, DataType data);

//尾删
void SeqListPopBack(SeqList *pSeq);
//头删
void SeqListPopFront(SeqList *pSeq);
//依据下标删除
void SeqListErase(SeqList *pSeq, int pos);
//依据数据删除
//第一种，删除第一个遇到的data
void SeqListRemove(SeqList *pSeq, DataType data);
//第二种，删除遇到的所有data
void SeqListRemoveAll(SeqList *pSeq, DataType data);

//查找（无序的）找到了就返回下标，没找到就返回-1。若是找到的话就返回第一个遇见的下标
int SeqListFind(SeqList *pSeq, DataType data);

//size_t无符号类型？？？
//ssize_t有符号类型，用它的话得引用一些头变量，它是更理想的返回类型

int SeqListSize(SeqList *pSeq);
int SeqListIsFull(SeqList *pSeq);
int SeqListEmpty(SeqList *pSeq);

//打印
void SeqListPrint(const SeqList *pSeq);

//不属于静态顺序表的接口
static void Swap(DataType *a, DataType *b);

//1、冒泡排序
//for(i=1; i<size; i++)//i的含义，冒泡的次数
//for(i=0; i<size-1; i++)
void SeqListBubbleSort(SeqList *pSeq);
//已经放好最大数的个数，一开始一个都没放好是0，最多要放size-1，剩下1个就不需要放了
//for(i=size-1; i>0; i--)//放最大数的下标

//2、选择排序
void SeqListSelectSort(SeqList *pSeq);