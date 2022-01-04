/*
堆排序应用Top K问题
输入样例
输入:
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
0
5
输出:
<v5-v7>9.000000 <v5-v8>7.000000 <v1-v2>6.000000 <v1-v4>5.000000 <v1-v3>4.000000

输入:
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
1
5
输出:
<v3-v5>1.000000 <v2-v5>1.000000 <v4-v6>2.000000 <v7-v9>2.000000 <v8-v9>4.000000
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 30
typedef struct ArcNode                      //弧的建立
{
    int tail;
    double info;
    int head;
}ArcNode;
void Sort(ArcNode G[],int k,int m)          //堆排序
{
    ArcNode x;
    int i=k,j=2*i;
    while(j<=m)
    {
        if(j<m&&G[j].info<G[j+1].info) j++;//找到两者之间最小的
        if(G[i].info<G[j].info)            //替换
        {       
            x=G[i];
            G[i]=G[j];
            G[j]=x;
        }
        i=j;
        j=2*i;                              //对该结点下的堆再进行排序做准备
    }
}
void heapSort(ArcNode G[],int m)            //选择排序
{
    ArcNode x;
    for(int k=m/2;k>0;k--) Sort(G,k,m);     //对整体堆排序
    for(int k=1;k<m;k++)                    //当排序好一个对剩下的继续排序
    {
        x=G[1];
        G[1]=G[m-k+1];
        G[m-k+1]=x;
        Sort(G,1,m-k);
    }
}
int main()
{
    int flag,k,m;
    ArcNode G[MAX_VERTEX_NUM];
    printf("输入弧的条数:");
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {   
        fflush(stdin);
        printf("输入第%d条弧(弧尾 弧头 弧权):",i);
        scanf("%d %d %lf",&G[i].tail,&G[i].head,&G[i].info);
    }
    heapSort(G,m);
    printf("查找最大最小元素:0(最大)/1(最小):");
    scanf("%d",&flag);
    printf("查找多少个元素:");
    scanf("%d",&k);
    if(flag==0)
    {
        for(int i=m;i>=m-k+1;i--)
        printf("<v%d-v%d>%lf\t",G[i].tail,G[i].head,G[i].info);
    }
    else if(flag==1)
    {
        for(int i=1;i<=k;i++)
        printf("<v%d-v%d>%lf\t",G[i].tail,G[i].head,G[i].info);
    }
    printf("\n");
    system("pause");
}
