#pragma once

typedef int DataType;

#define INIT_CAPACITY (3)

typedef struct SeqListD
{
	DataType *parray;
	int capacity;//当前容量，等同于静态顺序表的MAXSIZE
	int size;//同静态顺序表
} SeqListD;

//初始化/销毁/插入(尾插)

void SeqListDInit(SeqListD *pSeq)
{
	assert(pSeq);

	//为了获得容器空间
	pSeq->capacity = INIT_CAPACITY;
	pSeq->parray = (DataType *)malloc(sizeof(DataType) * pSeq->capacity);
	assert(pSeq->parray);

	//这个和静态顺序表一样
	pSeq->size = 0;
}

void SeqListDDestroy(SeqListD *pSeq)
{
	free(pSeq->parray);

	pSeq->capacity = 0;
	pSeq->parray = NULL;//这不是必须的
	pSeq->size  = 0;
}

static void ExpandIfRuquired(SeqListD *pSeq)
{
	int i = 0;

	//这个不属于一个对外的接口，所以把它定义成static，标明一下它不属于动态顺序表抛出去的一个接口，只是内部要调用的一个地方
    //扩容条件
	if(pSeq->size < pSeq->capacity)
	{
		//没满
		return;
	}

	//扩容
	pSeq->capacity *= 2;//翻一倍 

	//int i = 0;
    //1、申请新空间
	DataType *newArray = (DataType *)malloc(sizeof(DataType) * pSeq->capacity);
	//2、数据搬移
	for(i=0; i<pSeq->size; i++)
	{
		newArray[i] = pSeq->parray[i];
	}
	//3、释放老空间，把申请的新空间和动态顺序表关联起来
	free(pSeq->parray);//注意要先释放 
	pSeq->parray = newArray;

}

void SeqListDPushBack(SeqListD *pSeq, DataType data)
{
	//动态，加入了扩容机制
	ExpandIfRequired(pSeq); 
	pSeq->parray[pSeq->size] = data;
	pSeq->size++;
}

//同理，所有插入都需要加入扩容机制
