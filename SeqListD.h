#pragma once

typedef int DataType;

#define INIT_CAPACITY (3)

typedef struct SeqListD
{
	DataType *parray;
	int capacity;//��ǰ��������ͬ�ھ�̬˳����MAXSIZE
	int size;//ͬ��̬˳���
} SeqListD;

//��ʼ��/����/����(β��)

void SeqListDInit(SeqListD *pSeq)
{
	assert(pSeq);

	//Ϊ�˻�������ռ�
	pSeq->capacity = INIT_CAPACITY;
	pSeq->parray = (DataType *)malloc(sizeof(DataType) * pSeq->capacity);
	assert(pSeq->parray);

	//����;�̬˳���һ��
	pSeq->size = 0;
}

void SeqListDDestroy(SeqListD *pSeq)
{
	free(pSeq->parray);

	pSeq->capacity = 0;
	pSeq->parray = NULL;//�ⲻ�Ǳ����
	pSeq->size  = 0;
}

static void ExpandIfRuquired(SeqListD *pSeq)
{
	int i = 0;

	//���������һ������Ľӿڣ����԰��������static������һ���������ڶ�̬˳����׳�ȥ��һ���ӿڣ�ֻ���ڲ�Ҫ���õ�һ���ط�
    //��������
	if(pSeq->size < pSeq->capacity)
	{
		//û��
		return;
	}

	//����
	pSeq->capacity *= 2;//��һ�� 

	//int i = 0;
    //1�������¿ռ�
	DataType *newArray = (DataType *)malloc(sizeof(DataType) * pSeq->capacity);
	//2�����ݰ���
	for(i=0; i<pSeq->size; i++)
	{
		newArray[i] = pSeq->parray[i];
	}
	//3���ͷ��Ͽռ䣬��������¿ռ�Ͷ�̬˳����������
	free(pSeq->parray);//ע��Ҫ���ͷ� 
	pSeq->parray = newArray;

}

void SeqListDPushBack(SeqListD *pSeq, DataType data)
{
	//��̬�����������ݻ���
	ExpandIfRequired(pSeq); 
	pSeq->parray[pSeq->size] = data;
	pSeq->size++;
}

//ͬ�����в��붼��Ҫ�������ݻ���
