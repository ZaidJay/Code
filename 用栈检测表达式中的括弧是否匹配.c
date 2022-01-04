/*
用栈检测表达式中的括弧是否匹配
输入样例
输入:”if(var1<var2 && (3*(var1+var2)>1000)){var3=5;}”
输出:匹配成功
*/
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

int GetTop(SqStack S)                       //获取栈顶元素 
{
    char e;
    if(S.top==S.base) return 0;
    e=*(S.top-1);
    return e;   
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

int Pop(SqStack &S)                         //推出栈顶并删除 
{
    if(S.top==S.base) return 0;
    char e=*--S.top;
    return e;
}

int StackEmpty(SqStack S)                           // 判断是否为空 
{
    if(S.top==S.base) return 1;
    else return 0;
}

bool matching(char exp[],int n)                     // 配对
{
    SqStack S;
    int i=0,mat=1;
    InitStack(S);
    while(i<n&&mat)
    {
        switch (exp[i])
        {
            case '(':{Push(S,exp[i++]);break;}
            case ')':{
                if(!StackEmpty(S)&&GetTop(S)=='(')
                {
                    Pop(S);i++;
                }
                else {mat=0;}
                break;
                }
            default:{i++;continue;}
        }
    }
    return mat;
}

int main()
{
    char exp[100];
    scanf("%s",exp);
    int n=strlen(exp);
    if(matching(exp,n)==1) printf("匹配正确\n");
    else printf("匹配错误\n");
    system("pause");
} 
