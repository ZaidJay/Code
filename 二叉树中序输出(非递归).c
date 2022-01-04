/*
用非递归方式中序输出二叉树
输入样例
输入:12#4##3#56###
输出:241365
*/
#include<stdio.h>
#include<stdlib.h>
typedef int Status;
typedef char TElemType;
#define OK 1
#define ERROR 0

typedef struct BiTNode                             //二叉树
{
   TElemType data;
   struct BiTNode *leftchild,*rightchild;
}BiTNode,*BiTree;

typedef struct                                     //栈
{
    BiTree *base;
    BiTree *top;
    int stacksize;
}SqStack;

int InitStack(SqStack &S)                           //创建一个栈 
{
    S.base=(BiTree *)malloc(100*sizeof(BiTree));
    S.top=S.base;
    S.stacksize=100;
    return 1;
}

int Push(SqStack &S,BiTree e)                         //添加元素到栈顶 
{
    if(S.top-S.base>=S.stacksize)
    {
        S.base=(BiTree *)realloc(S.base,(S.stacksize+10)*sizeof(BiTree));
        S.top=S.base+S.stacksize;
        S.stacksize+=10;
    }
    *S.top++=e;
    return 1;
}

BiTree Pop(SqStack &S,BiTree &e)                         //推出栈顶并删除 
{
    if(S.top==S.base) return 0;
    e=*--S.top;
    printf("%c",e->data);
    return e;
}

BiTree GetTop(SqStack S)                       //获取栈顶元素 
{
   BiTree e;
   if(S.top==S.base) return 0;
   e=*(S.top-1);
   return e;   
}

int StackEmpty(SqStack S)                           // 判断是否为空 
{
   if(S.top==S.base) return 1;
   else return 0;
}

Status CreateTree_Preorder(BiTree &T)              //创建一个二叉树
{
   TElemType ch;
   scanf("%c",&ch);
   if(ch=='#') {T=NULL;}
   else
   {
      if(!(T=(BiTNode *)malloc(sizeof(BiTNode)))) exit(ERROR);
      T->data=ch;
      CreateTree_Preorder(T->leftchild);
      CreateTree_Preorder(T->rightchild);
   }
   return OK;
}

Status PrintElement(TElemType e)                   //输出一个元素
{
   printf("%c",e);
   return OK;
}

Status InOrderTraverse(BiTree T)                   //中序遍历
{
   SqStack S;
   InitStack(S);
   while (!StackEmpty(S)||T)
   {
      if(T)
      {
         Push(S,T);
         T=T->leftchild;
      }
      else
      {
         Pop(S,T);
         T=T->rightchild;
      }
   }
   return OK;
}

int main()
{
   BiTree T=NULL;
   CreateTree_Preorder(T);
   InOrderTraverse(T);
   printf("\n");
   system("pause");
}
