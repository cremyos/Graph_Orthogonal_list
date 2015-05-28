/*
 ************************************************
 *Name : graph_storage2.c                       *
 *Date : 2015-05-28                             *
 *Author : sniper                               *
 *Aim : The Orthogonal list storage the graph.  *
 ************************************************
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Orthogonal_list.h"

int CreateDG(OLGraph *G)
{
	int i,j;
	int node_pair1,node_pair2;
	ArcBox *arc;
	
	i=0;
	j=0;
	node_pair1 = 0;
	node_pair2 = 0;
	printf("please input the number of node and edge: ");
	scanf("%d %d",&G->vexnum,&G->arcnum);
	
	for(i=0;i<G->vexnum;i++)
	{
		G->xlist[i].data = 'A'+i;
		G->xlist[i].firstin = NULL;
		G->xlist[i].firstout = NULL;
	}
	printf("finish the Node!\n");

	for(j=0;j<G->arcnum;j++)
	{
		printf("please input the node pair: ");
		scanf("%d %d",&node_pair1,&node_pair2);
		node_pair1 -= 1;
		node_pair2 -= 1;
		arc = (ArcBox *)malloc(sizeof(struct ArcBox));
		arc->tailvex = 'A'+node_pair1;
		arc->headvex = 'A'+node_pair2;
		arc->hlink = G->xlist[node_pair1].firstin;
		arc->tlink = G->xlist[node_pair2].firstout;
		G->xlist[node_pair2].firstin = G->xlist[node_pair2].firstout = arc;	 
	}
}

int main()
{
	OLGraph *G;
	int i;

	i=0;
	G = (OLGraph *)malloc(sizeof(OLGraph));
	CreateDG(G);

	/* 
	 *print the adjacency list
	 */
	for(i=0;i<G->vexnum;i++)
	{
		printf("%c -> ",'A'+i);
		while(G->xlist[i].firstin!=NULL && G->xlist[i].firstout!=NULL)
		{
			printf("%c || %c -> ",G->xlist[i].firstin->tailvex,G->xlist[i].firstout->headvex);
			G->xlist[i].firstin = G->xlist[i].firstin->hlink;
			G->xlist[i].firstout = G->xlist[i].firstout->tlink;
		}
		printf("\n");
	}

	return 0;
}
