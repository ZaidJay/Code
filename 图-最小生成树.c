/*
最小生成树
输入样例
输入:
6
7
A
B
C
D
E
F
A B 1
A E 2
A C 3
B E 4
B D 5
D C 6
E F 7
输出:
A-B 1
B-E 4
E-F 7
B-D 5
D-C 6
最小权之和为23
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
int graph[MAX][MAX]={0};
char S[MAX];int n,m,sum=0;
int visit[MAX]={0};								//是否遍历的数组
int visited()									//判断是否每个结点都遍历过
{
	int x=0;
	for(int i=1;i<=n;i++) if(visit[i]==1) x++;
	return x;
}
void Prim(int graph[][MAX])						//Prim算法来获取最小生成树
{
	int quene[MAX],q=1,min,minid,i=1;
    visit[1]=1;
	while(visited()!=n)
	{
		min=MAX;
		minid=0;
		for(int j=1;j<=n;j++)
		{
			if(graph[i][j]<min&&graph[i][j]!=0)	//找最小的权的弧 
			{   
				min=graph[i][j];
				minid=j;
			}
		}
		if(minid==0) {i=quene[q--];}			//退栈 
        else
        {
		    printf("%c-%c %d\n",S[i],S[minid],min);
		    sum+=min;
		    for(int k=1;k<=n;k++) graph[k][i]=0;
		    graph[i][minid]=0;
		    quene[q++]=minid;
		    visit[minid]=1;
		    i=minid;
        }
	}
}
int locate(char c)								//确认元素在表中的位置
{
	for(int i=1;i<=n;i++)
	if(c==S[i]) {return i;break;}
}
int main()
{
	char c1,c2;
	int x,y,w;
	fflush(stdin);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		fflush(stdin);
		printf("第%d个顶点名称:",i);
		scanf("%c",&S[i]);
	}
	for(int i=1;i<=m;i++)
	{
		fflush(stdin);
		printf("第%d个边(弧尾 弧头 弧权):",i);
		scanf("%c %c %d",&c1,&c2,&w);
		x=locate(c1);
		y=locate(c2);
		graph[x][y]=w;
		graph[y][x]=w;
	}
	Prim(graph);
	printf("最小权之和为%d\n",sum);
    system("pause");
}
