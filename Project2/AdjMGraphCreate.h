#ifndef X   //X为你的标识符,保持唯一，可以长点，比如 #ifndef _INCLUDE_XXXXXX_H_  
#define X  
#include "meta.h"  
#endif 
#ifndef Y   //Y为你的标识符,保持唯一，可以长点，比如 #ifndef _INCLUDE_XXXXXX_H_  
#define Y  
#include "AdjMGraph.h"
#endif 

void CreatGraph(AdjMGraph *G, DataType V[], int n, RowColWeight E[], int e);
