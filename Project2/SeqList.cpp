
#include"SeqList.h"
//#include "meta.h"
void ListInitiate(SeqList *L)
{//��ʼ��˳���L,������һ����˳���
	L->size = 0;
}

int ListLength(SeqList *L)
{//��˳���L��
	return L->size;
}

int ListGet(SeqList L, int i, DataType *x)
{//ȡ˳���L�ĵ�i������Ԫ�أ��ɵ�������������
	if (i<0 || i>L.size - 1)
	{
		printf("i is error!\n");
		return 0;
	}
	*x = L.list[i];
	return 1;
}

int  ListInsert(SeqList *L, int i, DataType x)
{//��˳���L�ĵ�i������Ԫ��֮ǰ��������Ԫ��x
	int j;
	if (L->size >= MaxSize)
	{
		printf("The table is full!\n");
		return 0;
	}
	if (i<0 || i>L->size)
	{
		printf("i is error \n");
		return 0;
	}
	for (j = L->size; j>i; j--)
		L->list[j] = L->list[j - 1];
	L->list[i] = x;
	(L->size)++;
	return 1;
}

int ListDelete(SeqList *L, int i, DataType *x)
{  //ɾ��˳���L�е�i������Ԫ�أ���ͨ����������������
	int j;
	if (L->size <= 0)
	{
		printf("The table is empty! \n");
		return 0;
	}
	if (i<0 || i>L->size - 1)
	{
		printf("i is error! \n");
		return 0;
	}
	*x = L->list[i];
	for (j = i + 1; j <= L->size - 1; j++)
		L->list[j - 1] = L->list[j];
	(L->size)--;
	return 1;
}

void ListPrint(SeqList *L)
{
	int i;
	DataType x;
	for (i = 0; i<ListLength(L); i++)
	{
		if (ListGet(*L, i, &x) == 0)
		{
			printf("Error!\n");
		}
		else
			printf("%d   ", x);
	}
	printf("\n");
}