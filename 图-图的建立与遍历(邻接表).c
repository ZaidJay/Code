/*
图的建立与遍历(优先深度遍历/优先广度遍历)
输入样例
输入:
输入样例:
12 13
A B C D E F G H I J K L
A B 1
A C 1
B D 1
B E 1
D H 1
E H 1
C F 1
C G 1
G K 1
F I 1
F J 1
I L 1
J L 1 
输出:
优先深度遍历:A B D H E C F I L J G K
优先广度遍历:A B C D E F G H I J K L
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_VERTEX_NUM 30
#define OK 1
typedef int VRType;
int visited[MAX_VERTEX_NUM]={0};
typedef struct ArcNode
{
    int adj;
    struct ArcNode *nextarc;
    int info;
}ArcNode;

typedef struct VNode
{
    char data;
    ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct
{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;
int LocateVex(ALGraph G,char v)
{
    for(int i=0;i<G.vexnum;i++)
    if(G.vertices[i].data==v) return i;
}
int FirstAdjVex(ALGraph G,char v)
{
    int i=LocateVex(G,v);
    ArcNode *p;
    p=G.vertices[i].firstarc;
    if(p) return p->adj;
    else return -1;
}
int NextAdjVex(ALGraph G,char v,char w)
{
    ArcNode *p,*q;
    int i=LocateVex(G,v),j=LocateVex(G,w);
    if(i==-1||j==-1||i==j) return -1;
    p=G.vertices[i].firstarc;
    while(p->nextarc&&p->adj!=j) p=p->nextarc;
    if(p->nextarc)
    {
        q=p->nextarc;
        return q->adj;
    }
    else return -1;
}
void DFS(ALGraph G,int v)
{
    visited[v]=1;
    printf("%c ",G.vertices[v].data);
    int w=FirstAdjVex(G,G.vertices[v].data);
    for(;w>=0;w=NextAdjVex(G,G.vertices[v].data,G.vertices[w].data))
    if(visited[w]==0) DFS(G,w);
}
void DFSTraverse(ALGraph G)
{
    int v;
    for(v=0;v<G.vexnum;v++) visited[v]=0;
    for(v=0;v<G.vexnum;v++)
    if(visited[v]==0) DFS(G,v);
}
void BFSTraverse(ALGraph G)
{
    int v,w,head=0,tail=0,quene[100];
    for(v=0;v<G.vexnum;v++) visited[v]=0;
    for(v=0;v<G.vexnum;v++)
    if(visited[v]==0)
    {
        visited[v]=1;
        quene[tail++]=v;
        while(head!=tail) 
        {
            printf("%c ",G.vertices[head++].data);
            for(w=FirstAdjVex(G,head-1);w>=0;w=NextAdjVex(G,head-1,w))
            if(visited[w]==0)
            {
                visited[w]==1;
                quene[tail++]=w;
            }
        }
    }
}
void link(ALGraph &G,int i,int j,int w)
{
    ArcNode *p,*q;
    p=(ArcNode *)malloc(sizeof(ArcNode));
    p->adj=j;
    p->nextarc=NULL;
    p->info=w;
    if(!G.vertices[i].firstarc) G.vertices[i].firstarc=p;
    else
    {
        for(q=G.vertices[i].firstarc;q->nextarc;q=q->nextarc);
        q->nextarc=p;
    }
}
int CreateUDN(ALGraph &G)
{
    int i,j,k,w;
    char v1,v2;
    scanf("%d %d",&G.vexnum,&G.arcnum);
    for(i=0;i<G.vexnum;i++) 
    {
        fflush(stdin);
        printf("%d:",i+1);
        scanf("%c",&G.vertices[i].data);
        G.vertices[i].firstarc=NULL;
    }
    for(k=0;k<G.arcnum;k++)
    {
        fflush(stdin);
        printf("弧%d(首 尾 权):",k+1);
        scanf("%c %c %d",&v1,&v2,&w);
        i=LocateVex(G,v1);
        j=LocateVex(G,v2);
        link(G,i,j,w);
        link(G,j,i,w);
    }
    return OK;
}
int main()
{
    ALGraph G;
    CreateUDN(G);
    printf("优先深度遍历:");
    DFSTraverse(G);
    printf("\n");
    printf("优先广度遍历:");
    BFSTraverse(G);
    system("pause");
}
