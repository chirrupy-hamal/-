#pragma once
//#ifndef
//#define
//
//#endif

//���������ﵽ��Ŀ�Ķ���һ���ģ���ֹͷ�ļ����ظ�����

//#pragma once�����Ǵ������ļ��ĽǶ�ȥ��ֹ�����ظ����õģ�
//���Ǳ���������SeqList.h���������ˣ����Ͳ����ٰ�������ļ������ˣ���ֻ������һ���ļ���
//����������������忽��һ�ݣ���һ�������֣������ǿ��԰��������ġ�

//���궨��Ļ��������Ͼͱ�֤�������ᱻ�������Ρ�

typedef int DataType;

#define MAXSIZE (10)                           //��ȥ��һ�£�����

//��̬˳���
typedef struct SeqList
{
	DataType array[MAXSIZE];
	int size;//1�������˾�̬˳��������Ѵ�����ݸ���
	         //2����ǰ�����±�
} SeqList;//˳���Ķ��岻��Ψһ��

                                  //��С������

//���ݽṹ��һ�ֳ�������
//���ݱ������������֣����������еĶ������Ƕ����Խ����������ݣ�
//����ͼƬ�������ȶ������ݡ�

//�ӿڣ�������
 
//1����ʼ��/����

//��ʼ���ɿձ�
void SeqListInit/*��ʼ����VS��֧�ֺ��ֵ�*/(SeqList *pSeq);
                                        //1����ַ���ռ��С��
                                       //2������Ҫ�ı������ڲ�ֵ������ֻ��ͨ����ַ���������ô�ֵ�ķ�ʽ��
//���پ�̬˳���
void SeqListDestroy(SeqList *pSeq);

//2����/ɾ/��/��

//β��
void SeqListPushBack(SeqList *pSeq, DataType data);
//ͷ��
void SeqListPushFront(SeqList *pSeq, DataType data);
//�����±����
void SeqListInsert(SeqList *pSeq, int pos, DataType data);

//βɾ
void SeqListPopBack(SeqList *pSeq);
//ͷɾ
void SeqListPopFront(SeqList *pSeq);
//�����±�ɾ��
void SeqListErase(SeqList *pSeq, int pos);
//��������ɾ��
//��һ�֣�ɾ����һ��������data
void SeqListRemove(SeqList *pSeq, DataType data);
//�ڶ��֣�ɾ������������data
void SeqListRemoveAll(SeqList *pSeq, DataType data);

//���ң�����ģ��ҵ��˾ͷ����±꣬û�ҵ��ͷ���-1�������ҵ��Ļ��ͷ��ص�һ���������±�
int SeqListFind(SeqList *pSeq, DataType data);

//size_t�޷������ͣ�����
//ssize_t�з������ͣ������Ļ�������һЩͷ���������Ǹ�����ķ�������

int SeqListSize(SeqList *pSeq);
int SeqListIsFull(SeqList *pSeq);
int SeqListEmpty(SeqList *pSeq);

//��ӡ
void SeqListPrint(const SeqList *pSeq);

//�����ھ�̬˳���Ľӿ�
static void Swap(DataType *a, DataType *b);

//1��ð������
//for(i=1; i<size; i++)//i�ĺ��壬ð�ݵĴ���
//for(i=0; i<size-1; i++)
void SeqListBubbleSort(SeqList *pSeq);
//�Ѿ��ź�������ĸ�����һ��ʼһ����û�ź���0�����Ҫ��size-1��ʣ��1���Ͳ���Ҫ����
//for(i=size-1; i>0; i--)//����������±�

//2��ѡ������
void SeqListSelectSort(SeqList *pSeq);