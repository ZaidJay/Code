//利用栈进行进制转换 输入数据和进制，输出结果
//输入:2713 2
//输出:101010011001
#include<stdio.h>
#include<stdlib.h>
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

int Push(SqStack &S,char e)                         //添加元素到栈顶 
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
    return 1;
}

int StackEmpty(SqStack S)                           // 判断是否为空 
{
    if(S.top==S.base) return 1;
    else return 0;
}

unsigned long conversion(int N,int system)          //运算 
{
    char e=0;
    SqStack S;
    InitStack(S);
    while(N)
    {
        if(N%system<10) Push(S,'0'+N%system);
        else Push(S,'A'+N%system-10);
        N=N/system;
    }
    while(!StackEmpty(S))
    {
        Pop(S,e);
        printf("%c",e);
    }
}

int main()
{
    int N,system;
    scanf("%d %d",&N,&system);
    conversion(N,system);
} 
