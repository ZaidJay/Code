/*
用递归的方式中序输出二叉树
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
typedef struct BiTNode
{
   TElemType data;
   struct BiTNode *leftchild,*rightchild;
}BiTNode,*BiTree;

Status CreateTree_Preorder(BiTree &T)
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

Status PrintElement(TElemType e)
{
   printf("%c",e);
   return OK;
}

Status InOrderTraverse(BiTree T)
{
   if(T)
   {
      InOrderTraverse(T->leftchild);
      PrintElement(T->data);
      InOrderTraverse(T->rightchild);
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
