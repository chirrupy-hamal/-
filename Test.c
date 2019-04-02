#include"SeqList.h"

void Test()
{
	SeqList seqlist;
    //初始化成空表
	SeqListInit(&seqlist);
    SeqListPrint(&seqlist);
    SeqListSize(&seqlist);
	SeqListEmpty(&seqlist);
    //尾插
	SeqListPushBack(&seqlist, 1);
	SeqListPushBack(&seqlist, 2);
    SeqListPushBack(&seqlist, 3);
	SeqListPushBack(&seqlist, 4);
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
	//头插
	SeqListPushFront(&seqlist, 0);
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
    //依据下标插入
    SeqListInsert(&seqlist, 1, 5);
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
	SeqListInsert(&seqlist, seqlist.size, -1); 
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
    //尾删
	SeqListPopBack(&seqlist);
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
    //头删
	SeqListPopFront(&seqlist);
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
	//依据下标删除
    SeqListErase(&seqlist, 1);
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
	//SeqListErase(&seqlist, seqlist.size);错误 
	SeqListErase(&seqlist, seqlist.size-1); 
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
	//依据数据删除
	//第一种，删除第一个遇到的data
	SeqListRemove(&seqlist, 1);
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
	SeqListPushBack(&seqlist, 3);
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
	SeqListRemove(&seqlist, 3);
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
	//第二种，删除遇到的所有data
	SeqListPushBack(&seqlist, 3);
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
	SeqListRemoveAll(&seqlist, 3);
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
	//查找
	SeqListPushBack(&seqlist, 1);
	SeqListPushBack(&seqlist, 3);
    SeqListPushBack(&seqlist, 1);
	SeqListPushBack(&seqlist, 4);
	SeqListPushBack(&seqlist, -1);//加入-1是为了检测选择排序的特殊情况
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);

	//Swap(seqlist.array, seqlist.array+1);
	SeqListSelectSort(&seqlist);
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
    SeqListBubbleSort(&seqlist);
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
}

int main()
 {
	 Test();
	 return 0;
 }
