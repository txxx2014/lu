#ifndef X   //X为你的标识符,保持唯一，可以长点，比如 #ifndef _INCLUDE_XXXXXX_H_  
#define X  
#include "meta.h"
#endif 
//#include "SeqList.h"
void Initiate(AdjMGraph *G, int n);   //邻接表的初始化



void InsertVertex(AdjMGraph *G, DataType vertex); //插入顶点

void InsertEdge(AdjMGraph *G, int v1, int v2, int weight);//插入边

void DeleteEdge(AdjMGraph *G, int v1, int v2);// 删除边

void DeleteNode(AdjMGraph *G, int v1);
