/*
用顺序结构实现完全二叉树
输入样例
输入:
4
1 2 3 -1 4 -1 5 -1 -1 -1 -1 -1 -1 6
输出:
       1

   2       3

     4       5

            6
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define MAX_TREE_SIZE 100
typedef int SqBiTree[MAX_TREE_SIZE];
int create_bitree(SqBiTree &tree)                //创建一个二叉树
{
       printf("请输入结点数:");
       scanf("%d",&tree[0]);
       printf("输入整数序列:\n");
       for(int i=1;i<=tree[0];i++) {scanf("%d",&tree[i]);}
       return 1;
}

int leftchild(SqBiTree tree,int cur_e)           //检测有没有左孩子
{
       return tree[cur_e*2];
}

int rightchild(SqBiTree tree,int cur_e)          //检测有没有右孩子
{
       return tree[cur_e*2+1];
}

void printtree(SqBiTree tree)                    //打印出二叉树
{
       int k=0,size=tree[0];

       while(size)
       {
              size/=2;
              k++;
       }

       for(int i=1;i<=k;i++)
       {
              for(int j=pow(2,i-1);j<pow(2,i)&&j<=tree[0];j++)
              {
                     for(int n=1;n<pow(2,k-i);n++) printf(" ");
                     if(tree[j]==-1) printf(" ");
                     else printf("%d",tree[j]);
                     for(int n=1;n<=pow(2,k-i);n++) printf(" ");
              }
              printf("\n\n");
       }
}

void print_leaves(SqBiTree tree)                 //打印出子叶结点
{
       for(int i=1;i<=tree[0];i++)
       {
              if(leftchild(tree,i)==-1&&rightchild(tree,i)==-1&&tree[i]!=-1) {printf("%d ",tree[i]);}
              else continue;
       }
       printf("\n");
}

int main()
{
       SqBiTree tree;
       memset(tree,-1,sizeof(tree));             //初始化二叉树
       create_bitree(tree);
       printf("二叉树:\n");
       printtree(tree);
       printf("子叶结点:\n");
       print_leaves(tree);
       system("pause");
}
