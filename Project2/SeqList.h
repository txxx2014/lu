#include<stdio.h>
#include<malloc.h>
#ifndef X   //X为你的标识符,保持唯一，可以长点，比如 #ifndef _INCLUDE_XXXXXX_H_  
#define X  
#include "meta.h"  
#endif 


void ListInitiate(SeqList *L);

int ListLength(SeqList *L);

int ListGet(SeqList L, int i, DataType *x);

int  ListInsert(SeqList *L, int i, DataType x);

int ListDelete(SeqList *L, int i, DataType *x);

void ListPrint(SeqList *L);
