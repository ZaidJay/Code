/*
活动图(AOE图)
输入样例
输入:
9
11
1 2 6
1 3 4
1 4 5
2 5 1
3 5 1
4 6 2
5 7 9
5 8 7
6 8 4
7 9 2
8 9 4
输出:
                        V1      V2      V3      V4      V5      V6      V7      V8      V9
事件的最早发生时间:     0       6       4       5       7       7       16      14      18
事件的最晚发生时间:     0       6       6       8       7       10      16      14      18
                        a1      a2      a3      a4      a5      a6      a7      a8      a9      a10     a11
弧最早发生时间:         0       0       0       6       4       5       7       7       7       16      14
弧最迟发生时间:         0       2       3       6       6       8       7       7       10      16      14
该开发项目的最短开发周期:18
一旦延期将影响开发进度的全部路径:a1 a4 a7 a8 a10 a11
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_VERTEX_NUM 30
typedef int VRType;
int ve[MAX_VERTEX_NUM]={0},vl[MAX_VERTEX_NUM],ee[MAX_VERTEX_NUM],el[MAX_VERTEX_NUM],tail[MAX_VERTEX_NUM],head[MAX_VERTEX_NUM],w[MAX_VERTEX_NUM];
typedef struct ArcNode                      //图的结点
{
    int adj;
    struct ArcNode *nextarc;
    int info;
}ArcNode;

typedef struct VNode
{
    ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct                              //图
{
    AdjList vertices;
    int vexnum,arcnum;
}Graph;

int Max(int a,int b)                        //二者取最大值
{
    return a>b?a:b;
}

int Min(int a,int b)                        //二者取最小值
{
    return a<b?a:b;
}

void link(Graph &G,int i,int j,int w)       //连接两个结点
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
void Vearly(Graph &G)                       //求事件(结点)最早发生时间函数
{
    ve[1]=0;
    for(int i=1;i<=G.vexnum;i++)
    {
        ArcNode *p=G.vertices[i].firstarc;
        while(p!=NULL)
        {
            ve[p->adj]=Max(p->info+ve[i],ve[p->adj]);
            p=p->nextarc;
        }
    }
}

void Vlate(Graph &G)                        //求事件(结点)最晚发生时间函数
{
    for(int i=1;i<=G.vexnum;i++) vl[i]=1000;
    vl[G.vexnum]=ve[G.vexnum];
    for(int i=G.vexnum;i>0;i--)
    {
        ArcNode *p=G.vertices[i].firstarc;
        while(p!=NULL)
        {
            vl[i]=Min(vl[p->adj]-p->info,vl[i]);
            p=p->nextarc;
        }
    }
}

void Eearly(Graph &G)                       //求弧最早发生时间函数
{
    for(int i=1;i<=G.arcnum;i++)
    ee[i]=ve[tail[i]];
}

void Elate(Graph &G)                        //求弧最迟发生时间函数
{
    for(int i=1;i<=G.arcnum;i++)
    el[i]=vl[head[i]]-w[i];
}
int main()
{
    Graph G;
    printf("输入图的顶点数:");scanf("%d",&G.vexnum);//输入图的结点数和弧数
    printf("输入图的弧数:");scanf("%d",&G.arcnum);
    for(int i=1;i<=G.vexnum;i++) G.vertices[i].firstarc=NULL;
    for(int i=1;i<=G.arcnum;i++)             //输入弧和权
    {
        fflush(stdin);
        printf("输入第%d条弧(弧尾 弧头 弧权):",i);
        scanf("%d %d %d",&tail[i],&head[i],&w[i]);
        link(G,tail[i],head[i],w[i]);
    }
    Vearly(G);
    Vlate(G);
    Eearly(G);
    Elate(G);
    printf("\t\t");                         //输出结果
    for(int i=1;i<=G.vexnum;i++) printf("\tV%d",i);
    printf("\n事件的最早发生时间:");
    for(int i=1;i<=G.vexnum;i++) printf("\t%d",ve[i]);
    printf("\n事件的最晚发生时间:");
    for(int i=1;i<=G.vexnum;i++) printf("\t%d",vl[i]);
    printf("\n\t\t");
    for(int i=1;i<=G.arcnum;i++) printf("\ta%d",i);
    printf("\n弧最早发生时间:\t");
    for(int i=1;i<=G.arcnum;i++) printf("\t%d",ee[i]);
    printf("\n弧最迟发生时间:\t");
    for(int i=1;i<=G.arcnum;i++) printf("\t%d",el[i]);
    printf("\n该开发项目的最短开发周期:%d\n",ve[G.vexnum]);
    printf("一旦延期将影响开发进度的全部路径:");
    for(int i=1;i<=G.arcnum;i++) if(ee[i]==el[i]) printf("a%d ",i);
    printf("\n");
    system("pause");
}
