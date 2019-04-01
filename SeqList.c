#include"SeqList.h"
#include<stdio.h> 
#include<assert.h>
//#include<stdlib.h>//NULL

//��ʼ���ɿձ� 
void SeqListInit(SeqList *pSeq)
{
	//��ʼ��size
 
	//1��assert(pSeq != NULL);
	//2��if(pSeq == NULL)      if�ж�if(pSeq)������
	//   {
	//
    //   }

	assert(pSeq != NULL);

	pSeq->size = 0;

	//memset����������
}

//���پ�̬˳���
void SeqListDestroy(SeqList *pSeq)
{
	assert(pSeq);

	pSeq->size = 0;
}

//β��
void SeqListPushBack(SeqList *pSeq, DataType data)
{
	assert(pSeq != NULL);

	//������������Ѿ�����
	if(pSeq->size == MAXSIZE)
	{
		printf("������\n");
		assert(0);//����һ�㣬�ó��򳹵ױ�������
	}

	//�������
	pSeq->array[pSeq->size] = data;
	pSeq->size += 1;
	printf("β��%d\n", data);
}

//ͷ��
void SeqListPushFront(SeqList *pSeq, DataType data)
{
	int i = 0;//VS08
	
	assert(pSeq);

	if(pSeq->size == MAXSIZE)
	{
		printf("������\n");
		assert(0);
	}

	//int i = 0��
	//1���Ӻ���ǰ�ᣬ����Ḳ��
	//2��ѭ�������䣺������Ϳ�����
#if 1
	//i�ĺ����������±꣬�����±�[size-1,0](δ����ǰ��״̬����ôд��Ŀ������Ϊ�Ӻ���ǰ��ı�����)����[i]�ƶ���[i+1]
	for(i=pSeq->size-1; i>=0; i--)//VS08�ǲ�����for(int i=pSeq->size-1;i>=0;i--)����ʹ�õģ�������������iҲ��forѭ���ڲ��ľֲ�������
	{
		pSeq->array[i+1] = pSeq->array[i];
	}
#else
	i�ĺ����ǿռ��±꣬�ռ��±�[size,1](���ƺ��״̬)����[i-1]�ƶ���[i]
    for(i=pSeq->size; i>=1; i--)
    {
        pSeq->array[i] = pSeq->array[i-1];
    }
#endif
	pSeq->array[0] = data;
	pSeq->size++;
	printf("ͷ��%d\n", data);
}

//�����±����
void SeqListInsert(SeqList *pSeq, int pos, DataType data)
{
	int i = 0;//VS08

	assert(pSeq != NULL);
	assert(pSeq->size < MAXSIZE);
    assert(pos>=0 && pos<=pSeq->size);//��������ǿ���pos == size��

	//int i = 0; 
	//i�ĺ����������±�
	for(i=pSeq->size-1; i>=pos; i--)
	{
		pSeq->array[i+1] = pSeq->array[i];
	}
	pSeq->array[pos] = data;
	pSeq->size++;
	printf("���±�Ϊ%d��λ�ò���%d\n", pos, data);
}

//βɾ
void SeqListPopBack(SeqList *pSeq)
{
	assert(pSeq != NULL);

	//�������
	if(pSeq->size == 0)
	{
		printf("���ѿ�\n");
		assert(0);
	}

	//�������
	pSeq->size--;
	printf("βɾ");
}

//ͷɾ
void SeqListPopFront(SeqList *pSeq)
{
	int i = 0;//VS08

	assert(pSeq);

	if(pSeq->size == 0)
	{
		printf("���ѿ�\n");
		assert(0);
	}

	//int i = 0��
#if 1
	//i�ĺ����������±꣬�����±�[1,size-1](δ����ǰ��״̬)����[i]�ƶ���[i-1]
	for(i=1; i<=pSeq->size-1; i++)
	{
		pSeq->array[i-1] = pSeq->array[i];
	}
#else
	i�ĺ����ǿռ��±꣬�ռ��±�[0��size-2](���ƺ��״̬)����[i+1]�ƶ���[i]
    for(i=0; i<=pSeq->size-2; i++)
    {
    	pSeq->array[i] = pSeq->array[i+1];
    }
#endif
	pSeq->size--;
	printf("ͷɾ");
}


//�����±�ɾ��
void SeqListErase(SeqList *pSeq, int pos)
{
	int i = 0;//VS08

	assert(pSeq != NULL);
	assert(pSeq->size > 0);
	assert(pos>=0 && pos<pSeq->size);//�����insert��һ����û�е��ڵ����
    
	//int i = 0��
	//i�ĺ����ǿռ��±�
	for(i=pos; i<=pSeq->size-2; i++)
	{
		pSeq->array[i] = pSeq->array[i+1];
	}
	pSeq->size--;
	printf("���±���%dλ�õ����ݽ���ɾ��\n", pos);
}

//��������ɾ��
//��һ�֣�ɾ����һ��������data
void SeqListRemove(SeqList *pSeq, DataType data)
{
	int pos = 0;//VS08

	assert(pSeq != NULL);

	pos = SeqListFind(pSeq, data);
	if(-1 == pos)
	{
		printf("%d�ڱ��в����ڣ����ܶԴ����ݽ���ɾ��\n", data);
		return ;
	}
	SeqListErase(pSeq, pos);
    printf("�Ե�һ�γ��ֵ�����%d����ɾ��\n", data);
}

//�ڶ��֣�ɾ������������data
void SeqListRemoveAll(SeqList *pSeq, DataType data)
{
	/*while((pos = SeqListFind(pSeq, data)) != -1)
	{
		SeqListErase(pSeq, pos);
	}*/
	//���ַ�ʽ���ã���
	//�ٸ������������һ������1 1 1 ����
	//����ɾ��1�������������ѭ������ִ���˶��ٴ������������һֱ��ִ�б�����
	//ѭ����ѭ��

    
    /*
    //һ�α���
	//�������Ҳ���Ǻܺã��ô���һ�α����ͽ����ˣ�ʱ��ȽϿ죻�����ǿ����¿ռ䣬�ռ��С��size�й�ϵ
	DataType *newArray = (DataType *)malloc(sizeof(DataType) * pSeq->size);
	int i = 0, j = 0;
	for(i=0,j=0; i<pSeq->size; i++)                                       //���ű��ʽ������
	{
		if(data != array[i])
		{
			newArray[j++] = pSeq->array[i];
		}
	}
	//�����ݰ����
	for(i=0; i<j; i++)
	{
		pSeq->array[i] = newArray[i];
	}
	pSeq->size = j;
	//�ͷ�
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
	printf("�Ա������г��ֵ�����%d����ɾ��\n", data);
}

//���ң�����ģ��ҵ��˾ͷ����±꣬û�ҵ��ͷ���-1�������ҵ��Ļ��ͷ��ص�һ���������±�
int SeqListFind(SeqList *pSeq, DataType data)
{
	//���ֲ��ң�ǰ���������
	//˳���������
	int i = 0;

	assert(pSeq);

	for(i=0; i<pSeq->size; i++)
	{
		if(data == pSeq->array[i])
		{
			printf("�ҵ���,�±�Ϊ%d\n", i);
			return i;
		}
	}
	printf("û�ҵ�Ҫ���ҵ�����\n");
	return -1;
}

int SeqListSize(SeqList *pSeq)
{
	assert(pSeq != NULL);

	printf("��ʱ�������ݸ���Ϊ%d\n", pSeq->size);
	return pSeq->size;
}

//1��ʾtrue��0��ʾfalse
int SeqListIsFull(SeqList *pSeq)
{
	assert(pSeq != NULL);

	if(pSeq->size == MAXSIZE)
	{
		printf("������\n");
        return 1;
	}
	printf("��δ��\n");
	return 0;

	//return pSeq->size == MAXSIZE;
}

int SeqListEmpty(SeqList *pSeq)
{
	assert(pSeq != NULL);

	if(pSeq->size == 0)
	{
		printf("���ѿ�\n");
        return 1;
	}
	printf("��δ��\n");
	return 0;

	//return pSeq->size == 0;
}

//��ӡ��̬˳���
void SeqListPrint(const SeqList *pSeq)
{
    int i = 0;//VS08

	assert(pSeq != NULL);

	//д�������Ϊ�˴�ӡ����ʼ�����Ŀձ�
	if(0 == pSeq->size)
	{
		printf("��ʱ���ǿձ�\n");
        return;
	}
	//int i = 0;
	printf("��ʱ����������:");
	for(i=0; i<pSeq->size; i++)
	{
		printf("%d ", pSeq->array[i]);
	}
	printf("\n");
}

//������˳���Ľӿ� 
static void Swap(DataType *a, DataType *b)
{
	DataType t = *a;
	*a = *b;
	*b = t;
}
//1��ð��
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
//2��ѡ������
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
		//�����ֵ�嵽���
		if(maxPos != max)
		{
			Swap(pSeq->array+maxPos, pSeq->array+max);
		}
		//��ֹminPos�����ֵҪ�����λ��
		if(minPos == max)
		{
			minPos = maxPos;
		}
		//����Сֵ�嵽��ǰ��
		if(minPos != min)
		{
			Swap(pSeq->array+minPos, pSeq->array+min);
		}
		min++;
	    max--;
	}
}
