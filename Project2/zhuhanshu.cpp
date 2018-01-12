#include<stdio.h>
#include "zhuhanshu.h"


AdjMGraph *g1 = (AdjMGraph *)malloc(sizeof(AdjMGraph));
int	*n1 = (int *)malloc(sizeof(int));        //结点的个数
int	*n2 = (int *)malloc(sizeof(int));        //结点对应的边的总条数


void xianshi()
{
	printf("****************************************\n");
	printf("1)建立路由器网络拓扑图\n");
	printf("2)输出路由器网络拓扑图\n");
	printf("3)增添路由器的结点以及该结点对应的边\n");
	printf("4)删除路由器两结点所连接的边\n");
	printf("5)输出路由表\n");
	printf("6)删除路由结点\n");
	printf("7)退出\n");
	printf("****************************************\n");
	printf("请输入所要完成的功能\n");
}


int menu(int n3)
{
	switch (n3)
	{
	case 1:     //建立路由器网络拓扑图
	{
		int i;

		printf("请输入所建节点的个数（最大不超过10）\n");
		scanf_s("%d%*c", n1);
		//getchar();
		printf("请输入节点的名称（字母）\n");
		DataType *a = (DataType *)malloc(sizeof(DataType)*(*n1));
		for (i = 0; i < *n1; i++)
		{
			scanf_s("%c%*c", &a[i]);
			//getchar();
		}
		printf("请输入各个节点的代号以及各个节点之间的关系（与前面对应的节点序号从0开始，节点之间的距离为1,10,64三种）\n");
		printf("请在输入完一对节点之间的关系后换行\n");
		printf("请输入所建立的图对应的边的总条数\n");
		scanf_s("%d%*c", &(*n2));
		printf("请输入各边之间的关系\n");
		RowColWeight *rcw = (RowColWeight *)malloc(sizeof(RowColWeight)*(*n2));
		for (i = 0; i < *n2; i++)
		{
			fflush(stdin);
			scanf_s("%d%d%d%*c", &rcw[i].row, &rcw[i].col, &rcw[i].weight);
		}
		//getchar();
		CreatGraph(g1, a, *n1, rcw, *n2);
		printf("您已经建立好了路由器的网络拓扑图，请选择所要完成的功能：\n");
		return n3;
		break;
	}
	case 2:    //输出路由器网络拓扑图
	{
		printf("顶点集合为：\n");
		for (int i1 = 0; i1 < g1->Vertices.size; i1++)
			printf("%c  ", g1->Vertices.list[i1]);
		printf("\n");
		for (int i = 0; i < g1->Vertices.size; i++)
		{
			for (int j = 0; j < g1->Vertices.size; j++)
				printf("%5d  ", g1->edge[i][j]);
			printf("\n");
		}
		return n3;
		break;
	}
	case 3:    //增添路由器的结点以及该结点对应的边
	{
		DataType vertex, m;
		int weight, v1, v2, n4;
		printf("请输入所要建立的新结点\n");
		fflush(stdin);
		scanf_s("%c%*c", &vertex);
		m = vertex;
		//getchar();
		//getchar();
		InsertVertex(g1, vertex);
		printf("请输入新建立的边的条数\n");
		scanf_s("%d%*c", &n4);
		//getchar();
		for (int i = 0; i < n4; i++)
		{
			printf("请输入与新结点相连的节点下标\n");
			scanf_s("%d%*c", &v2);
			//getchar();
			printf("请输入对应变得权值\n");
			scanf_s("%d%*c", &weight);
			//getchar();
			v1 = g1->Vertices.size - 1;
			InsertEdge(g1, v1, v2, weight);
			InsertEdge(g1, v2, v1, weight);
		}
		printf("新结点和边已经建立完成\n");
		return n3;
		break;
	}
	case 4:   //删除结点及其相邻的边
	{
		int v1, v2;
		printf("请输入所要删除的结点的下标v1,v2\n");
		scanf_s("%d%d%*c", &v1, &v2);
		DeleteEdge(g1, v1, v2);
		DeleteEdge(g1, v2, v1);
		return n3;
		break;
	}

	{
		int i;
		MinSpanTree *colseVertex = (MinSpanTree *)malloc(sizeof(MinSpanTree)*(*n1));
		Prim(*g1, colseVertex);
		printf("初始顶点 = %c\n", colseVertex[0].vertex);
		for (i = 1; i < *n1; i++)
			printf("顶点 =%c  边的权值 = %d\n", colseVertex[i].vertex, colseVertex[i].weight);
		return n3;
		break;
	}
	case 5:  //输出路由表
	{
		int *distance = (int *)malloc(sizeof(int)*(*n1));
		for (int a = 0; a<*n1; a++) {
			distance[a] = -1;
		}
		DataType *tables = (DataType *)malloc(sizeof(DataType)*(g1->Vertices.size));
		for (int c = 0; c<*n1; c++) {
			tables[c] = '0';
		}
		int *path = (int *)malloc(sizeof(int)*(*n1));
		for (int b = 0; b<*n1; b++) {
			path[b] = -1;
		}
		printf("请输入起始顶点\n");
		int qi,hi, i;
		scanf_s("%d%*c", &qi);
		hi = qi - 1;
		Dijkstra(*g1, hi, distance, path, tables);
		printf("顶点%c的路由表如下：\n", g1->Vertices.list[0]);
		printf(" 目的路由     下一跳\n");
		for (i = 0; i < g1->Vertices.size; i++)
			if (tables[i] != -1)
			{
				//printf("  %c ********** %c\n",g1->Vertices.list[i],g1->Vertices.list[path[i]]);
				printf("  %c ********** %c\n", g1->Vertices.list[i], tables[i]);
			}
		return n3;
		break;
	}
	case 6:  //删除路由结点
	{
		int v1, v2;
		printf("请输入要删除结点的下标\n");
		scanf_s("%d%*c", &v2);
		v1 = v2 - 1;
		DeleteNode(g1, v1);

		return n3;
		break;
	}

	}
}

void main()
{

	xianshi();
	int n3;
	scanf_s("%d", &n3);
	while (menu(n3) != 7)
	{
		xianshi();
		scanf_s("%d", &n3);
	}
}