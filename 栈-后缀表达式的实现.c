/*
后缀表达式实现
输入样例
输入:a+c/d*(e-f)#
输出:
#       a
#+      a
#+      ac
#+/     ac
#+/     acd
#+      acd/
#+*     acd/
#+*(    acd/
#+*(    acd/e
#+*(-   acd/e
#+*(-   acd/ef
#+*(    acd/ef-
#+*     acd/ef-
#+      acd/ef-*
#       acd/ef-*+
#       acd/ef-*+
*/
#include<stdio.h>
#include<stdlib.h>
int length,anslen=0;
char answer[1000];
typedef struct
{
    char *base;
    char *top;
    int stacksize;
}SqStack;
int InitStack(SqStack &S)                           //建栈 
{
    S.base=(char *)malloc(100*sizeof(char));
    S.top=S.base;
    S.stacksize=100;
    return 1;
}
char GetTop(SqStack S)                       //获取栈顶元素 
{
	char e=*(S.top-1);
    return e;   
}
int Push(SqStack &S,char e)                         //元素进栈 
{
    if(S.top-S.base>=S.stacksize)
    {
        S.base=(char *)realloc(S.base,(S.stacksize+10)*sizeof(char));
        S.top=S.base+S.stacksize;
        S.stacksize+=10;
    }
    *S.top++=e;
    return 1;
}
char Pop(SqStack &S,char &e)                         //退出栈顶元素并且删除
{
    e=*--S.top;
    return e;
}
void Show_Stack(SqStack S)							//展示栈内元素
{
	SqStack P=S;
	for(;P.base!=P.top;)
	printf("%c",*P.base++);
}
int ProJu(char x1,char x2)							//判断优先级
{
	if((x1=='*'||x1=='/')&&(x2=='+'||x2=='-')) return 1;
	else if(((x1=='*'||x1=='/')&&(x2=='*'||x2=='/'))||((x1=='+'||x1=='-')&&(x2=='+'||x2=='-'))) return 1; 
	else if(x2=='(') return 0;
	else return 0;
}
void SuffixSort(SqStack S,char X[])					//后缀表达排序
{
	char e;
	for(int i=0;i<length;i++)
	{
		if(X[i]=='+'||X[i]=='-'||X[i]=='*'||X[i]=='/'||X[i]=='('||X[i]==')')
		{
			if(GetTop(S)=='#') Push(S,X[i]);
			else if(X[i]==')') {if(GetTop(S)=='(') Pop(S,e);else {Pop(S,answer[anslen++]);i--;}}
			else if(ProJu(GetTop(S),X[i])) {Pop(S,answer[anslen++]);i--;}
			else if(!ProJu(GetTop(S),X[i])) Push(S,X[i]);	
		}
		else if(X[i]=='#') while(GetTop(S)!='#') {Pop(S,answer[anslen++]);Show_Stack(S);printf("\t%s\n",answer);}
		else answer[anslen++]=X[i];
	Show_Stack(S);printf("\t%s\n",answer);
	}
}
int main()
{
	SqStack S;
	InitStack(S);
	char X[1000];
	for(length=0;;length++)
	{
		scanf("%c",&X[length]);
		if(X[length]=='#') break;					//当遇到#停止输入
	}
	length++;
	Push(S,'#');									//为栈底添加#
	SuffixSort(S,X);
} 
