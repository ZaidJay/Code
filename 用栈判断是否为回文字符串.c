//输入一串字符串判断是否为回文字符串
//输入:113212311
//输出:回文
//ps:不能对中文使用,中文一个字符占两个字节
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char *base;
    char *top;
    int stacksize;
}SqStack;

int InitStack(SqStack &S)                           //创建一个栈 
{
    S.base=(char *)malloc(100*sizeof(char));
    S.top=S.base;
    S.stacksize=100;
    return 1;
}

int GetTop(SqStack S,char &e)                       //获取栈顶元素 
{
    if(S.top==S.base) return 0;
    e=*(S.top-1);
    return 1;   
}

int Push(SqStack &S,char e)                         //添加元素到栈
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

int Pop(SqStack &S,char &e)                         //推出栈顶并删除
{
    if(S.top==S.base) return 0;
    e=*--S.top;
    // printf("%c",e);
    return 1;
}

int Rev(char C1[100])           //运算 
{
    SqStack S;
    InitStack(S);
    int n=strlen(C1);
    char C2[n];
    for(int i=0;i<n;i++)
    Push(S,C1[i]);
    for(int i=0;i<n;i++)
    Pop(S,C2[i]);
    C2[n]='\0';
    if(strcmp(C1,C2)==0) printf("1");
    else printf("0");
    return 1;
}

int main()
{
    char C1[100];
    scanf("%s",C1);
    Rev(C1);
    system("pause");
} 
