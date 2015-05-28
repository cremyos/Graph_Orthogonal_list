#ifndef __ORTHOGONAL_LIST_H__
#define __ORTHOGONAL_LIST_H__

#define MAX_VERTEX_NUM 20

typedef struct ArcBox
{
	char tailvex,headvex;
	struct ArcBox *hlink,*tlink;
}ArcBox;

typedef struct VexNode
{
	char data;
	ArcBox *firstin,*firstout;
}VexNode;

typedef struct
{	
	VexNode xlist[MAX_VERTEX_NUM];
	int vexnum,arcnum;
}OLGraph;

#endif /*__ORTHOGONAL_LIST_H__*/
