#ifndef X   //XΪ��ı�ʶ��,����Ψһ�����Գ��㣬���� #ifndef _INCLUDE_XXXXXX_H_  
#define X  
#include "meta.h"
#endif 
//#include "SeqList.h"
void Initiate(AdjMGraph *G, int n);   //�ڽӱ�ĳ�ʼ��



void InsertVertex(AdjMGraph *G, DataType vertex); //���붥��

void InsertEdge(AdjMGraph *G, int v1, int v2, int weight);//�����

void DeleteEdge(AdjMGraph *G, int v1, int v2);// ɾ����

void DeleteNode(AdjMGraph *G, int v1);
