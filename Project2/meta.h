typedef char VerT;
#define MaxSize 10
#define MaxVertices 10
#define MaxWeight 10000
typedef char DataType;

typedef struct
{
	DataType list[MaxSize];
	int size;
}SeqList;

typedef struct
{
	SeqList Vertices;
	int edge[MaxVertices][MaxVertices];
	int numOfEdges;
}AdjMGraph;

typedef struct
{
	VerT vertex;
	int weight;
}MinSpanTree;

typedef struct
{
	int row;
	int col;
	int weight;
}RowColWeight;
