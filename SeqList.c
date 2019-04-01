#include"SeqList.h"
#include<stdio.h> 
#include<assert.h>
//#include<stdlib.h>//NULL

//初始化成空表 
void SeqListInit(SeqList *pSeq)
{
	//初始化size
 
	//1、assert(pSeq != NULL);
	//2、if(pSeq == NULL)      if判定if(pSeq)？？？
	//   {
	//
    //   }

	assert(pSeq != NULL);

	pSeq->size = 0;

	//memset函数？？？
}

//销毁静态顺序表
void SeqListDestroy(SeqList *pSeq)
{
	assert(pSeq);

	pSeq->size = 0;
}

//尾插
void SeqListPushBack(SeqList *pSeq, DataType data)
{
	assert(pSeq != NULL);

	//特殊情况，表已经满了
	if(pSeq->size == MAXSIZE)
	{
		printf("表已满\n");
		assert(0);//极端一点，让程序彻底崩掉好了
	}

	//正常情况
	pSeq->array[pSeq->size] = data;
	pSeq->size += 1;
	printf("尾插%d\n", data);
}

//头插
void SeqListPushFront(SeqList *pSeq, DataType data)
{
	int i = 0;//VS08
	
	assert(pSeq);

	if(pSeq->size == MAXSIZE)
	{
		printf("表已满\n");
		assert(0);
	}

	//int i = 0；
	//1、从后往前搬，否则会覆盖
	//2、循环的区间：闭区间和开区间
#if 1
	//i的含义是数据下标，数据下标[size-1,0](未搬移前的状态，这么写的目的是因为从后往前搬的闭区间)，把[i]移动到[i+1]
	for(i=pSeq->size-1; i>=0; i--)//VS08是不允许for(int i=pSeq->size-1;i>=0;i--)这样使用的，即便是这样，i也是for循环内部的局部变量。
	{
		pSeq->array[i+1] = pSeq->array[i];
	}
#else
	i的含义是空间下标，空间下标[size,1](搬移后的状态)，把[i-1]移动到[i]
    for(i=pSeq->size; i>=1; i--)
    {
        pSeq->array[i] = pSeq->array[i-1];
    }
#endif
	pSeq->array[0] = data;
	pSeq->size++;
	printf("头插%d\n", data);
}

//依据下标插入
void SeqListInsert(SeqList *pSeq, int pos, DataType data)
{
	int i = 0;//VS08

	assert(pSeq != NULL);
	assert(pSeq->size < MAXSIZE);
    assert(pos>=0 && pos<=pSeq->size);//插入操作是可以pos == size的

	//int i = 0; 
	//i的含义是数据下标
	for(i=pSeq->size-1; i>=pos; i--)
	{
		pSeq->array[i+1] = pSeq->array[i];
	}
	pSeq->array[pos] = data;
	pSeq->size++;
	printf("在下标为%d的位置插入%d\n", pos, data);
}

//尾删
void SeqListPopBack(SeqList *pSeq)
{
	assert(pSeq != NULL);

	//特殊情况
	if(pSeq->size == 0)
	{
		printf("表已空\n");
		assert(0);
	}

	//正常情况
	pSeq->size--;
	printf("尾删");
}

//头删
void SeqListPopFront(SeqList *pSeq)
{
	int i = 0;//VS08

	assert(pSeq);

	if(pSeq->size == 0)
	{
		printf("表已空\n");
		assert(0);
	}

	//int i = 0；
#if 1
	//i的含义是数据下标，数据下标[1,size-1](未搬移前的状态)，把[i]移动到[i-1]
	for(i=1; i<=pSeq->size-1; i++)
	{
		pSeq->array[i-1] = pSeq->array[i];
	}
#else
	i的含义是空间下标，空间下标[0，size-2](搬移后的状态)，把[i+1]移动到[i]
    for(i=0; i<=pSeq->size-2; i++)
    {
    	pSeq->array[i] = pSeq->array[i+1];
    }
#endif
	pSeq->size--;
	printf("头删");
}


//依据下标删除
void SeqListErase(SeqList *pSeq, int pos)
{
	int i = 0;//VS08

	assert(pSeq != NULL);
	assert(pSeq->size > 0);
	assert(pos>=0 && pos<pSeq->size);//这里和insert不一样，没有等于的情况
    
	//int i = 0；
	//i的含义是空间下标
	for(i=pos; i<=pSeq->size-2; i++)
	{
		pSeq->array[i] = pSeq->array[i+1];
	}
	pSeq->size--;
	printf("把下标在%d位置的数据进行删除\n", pos);
}

//依据数据删除
//第一种，删除第一个遇到的data
void SeqListRemove(SeqList *pSeq, DataType data)
{
	int pos = 0;//VS08

	assert(pSeq != NULL);

	pos = SeqListFind(pSeq, data);
	if(-1 == pos)
	{
		printf("%d在表中不存在，不能对此数据进行删除\n", data);
		return ;
	}
	SeqListErase(pSeq, pos);
    printf("对第一次出现的数据%d进行删除\n", data);
}

//第二种，删除遇到的所有data
void SeqListRemoveAll(SeqList *pSeq, DataType data)
{
	/*while((pos = SeqListFind(pSeq, data)) != -1)
	{
		SeqListErase(pSeq, pos);
	}*/
	//这种方式不好，慢
	//举个极端情况，有一个数列1 1 1 ……
	//让你删掉1，你想你在这个循环里面执行了多少次这个遍历啊，一直在执行遍历，
	//循环套循环

    
    /*
    //一次遍历
	//这个代码也不是很好，好处是一次遍历就结束了，时间比较快；坏处是开了新空间，空间大小和size有关系
	DataType *newArray = (DataType *)malloc(sizeof(DataType) * pSeq->size);
	int i = 0, j = 0;
	for(i=0,j=0; i<pSeq->size; i++)                                       //逗号表达式？？？
	{
		if(data != array[i])
		{
			newArray[j++] = pSeq->array[i];
		}
	}
	//把数据搬回来
	for(i=0; i<j; i++)
	{
		pSeq->array[i] = newArray[i];
	}
	pSeq->size = j;
	//释放
	free(newArray);
	*/

	int i = 0, j = 0;//VS08

	assert(pSeq != NULL);

	for(i=0; i<pSeq->size; i++)
	{
		if(pSeq->array[i] != data)
		{
			pSeq->array[j++] = pSeq->array[i];
		} 
	}
	pSeq->size = j;
	printf("对表中所有出现的数据%d进行删除\n", data);
}

//查找（无序的）找到了就返回下标，没找到就返回-1。若是找到的话就返回第一个遇见的下标
int SeqListFind(SeqList *pSeq, DataType data)
{
	//二分查找，前提是有序的
	//顺序遍历查找
	int i = 0;

	assert(pSeq);

	for(i=0; i<pSeq->size; i++)
	{
		if(data == pSeq->array[i])
		{
			printf("找到了,下标为%d\n", i);
			return i;
		}
	}
	printf("没找到要查找的数据\n");
	return -1;
}

int SeqListSize(SeqList *pSeq)
{
	assert(pSeq != NULL);

	printf("此时表中数据个数为%d\n", pSeq->size);
	return pSeq->size;
}

//1表示true，0表示false
int SeqListIsFull(SeqList *pSeq)
{
	assert(pSeq != NULL);

	if(pSeq->size == MAXSIZE)
	{
		printf("表已满\n");
        return 1;
	}
	printf("表未满\n");
	return 0;

	//return pSeq->size == MAXSIZE;
}

int SeqListEmpty(SeqList *pSeq)
{
	assert(pSeq != NULL);

	if(pSeq->size == 0)
	{
		printf("表已空\n");
        return 1;
	}
	printf("表未空\n");
	return 0;

	//return pSeq->size == 0;
}

//打印静态顺序表
void SeqListPrint(const SeqList *pSeq)
{
    int i = 0;//VS08

	assert(pSeq != NULL);

	//写这个就是为了打印经初始化过的空表
	if(0 == pSeq->size)
	{
		printf("此时表是空表\n");
        return;
	}
	//int i = 0;
	printf("此时表中数据是:");
	for(i=0; i<pSeq->size; i++)
	{
		printf("%d ", pSeq->array[i]);
	}
	printf("\n");
}

//不属于顺序表的接口 
static void Swap(DataType *a, DataType *b)
{
	DataType t = *a;
	*a = *b;
	*b = t;
}
//1、冒泡
void SeqListBubbleSort(SeqList *pSeq)
{
	int i = 0, j = 0;
	int isSorted = 0;
	for(i=0; i<pSeq->size-1; i++)
	{   
		isSorted = 1;
		for(j=0; j<pSeq->size-1-i; j++)
		{
			if(pSeq->array[j] > pSeq->array[j+1])
			{
				Swap(pSeq->array+j, pSeq->array+j+1);
			}
			isSorted = 0;
		}
		if(isSorted)
		{
			break;
		}
	}
}
//2、选择排序
void SeqListSelectSort(SeqList *pSeq)
{
	int min, max;
	int minPos, maxPos;
	min = 0;
	max = pSeq->size-1;
	while(min < max)
	{
		int i = 0;
		minPos = maxPos = min;
        //int i = 0;
		for(i=min; i<=max; i++)
		{
			if(pSeq->array[i] > pSeq->array[maxPos])
			{
				maxPos = i;
			}
			if(pSeq->array[i] < pSeq->array[minPos])
			{
				minPos = i;
			}
		}
		//将最大值插到最后
		if(maxPos != max)
		{
			Swap(pSeq->array+maxPos, pSeq->array+max);
		}
		//防止minPos在最大值要插入的位置
		if(minPos == max)
		{
			minPos = maxPos;
		}
		//将最小值插到最前面
		if(minPos != min)
		{
			Swap(pSeq->array+minPos, pSeq->array+min);
		}
		min++;
	    max--;
	}
}
