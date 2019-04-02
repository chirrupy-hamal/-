#include"SeqList.h"

void Test()
{
	SeqList seqlist;
    //��ʼ���ɿձ�
	SeqListInit(&seqlist);
    SeqListPrint(&seqlist);
    SeqListSize(&seqlist);
	SeqListEmpty(&seqlist);
    //β��
	SeqListPushBack(&seqlist, 1);
	SeqListPushBack(&seqlist, 2);
    SeqListPushBack(&seqlist, 3);
	SeqListPushBack(&seqlist, 4);
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
	//ͷ��
	SeqListPushFront(&seqlist, 0);
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
    //�����±����
    SeqListInsert(&seqlist, 1, 5);
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
	SeqListInsert(&seqlist, seqlist.size, -1); 
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
    //βɾ
	SeqListPopBack(&seqlist);
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
    //ͷɾ
	SeqListPopFront(&seqlist);
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
	//�����±�ɾ��
    SeqListErase(&seqlist, 1);
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
	//SeqListErase(&seqlist, seqlist.size);���� 
	SeqListErase(&seqlist, seqlist.size-1); 
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
	//��������ɾ��
	//��һ�֣�ɾ����һ��������data
	SeqListRemove(&seqlist, 1);
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
	SeqListPushBack(&seqlist, 3);
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
	SeqListRemove(&seqlist, 3);
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
	//�ڶ��֣�ɾ������������data
	SeqListPushBack(&seqlist, 3);
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
	SeqListRemoveAll(&seqlist, 3);
	SeqListPrint(&seqlist);
	SeqListSize(&seqlist);
	//����
	SeqListPushBack(&seqlist, 1);
	SeqListPushBack(&seqlist, 3);
    SeqListPushBack(&seqlist, 1);
	SeqListPushBack(&seqlist, 4);
	SeqListPushBack(&seqlist, -1);//����-1��Ϊ�˼��ѡ��������������
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
