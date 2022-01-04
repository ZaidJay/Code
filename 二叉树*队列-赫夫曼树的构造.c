/*
赫夫曼树的构造,编码与译码
请根据自己需求改写出现概率等数值
输入样例
输入:000110000110011100000001
输出:ABABFEGH
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int weight,parent,lchild,rchild;
}HTNode,*HuffmanTree;
typedef char* HuffmanCode[8];
void Select(HuffmanTree &HT,int n,int &s1,int &s2)
{
    int min1=100,min2=100;
    for(int j=0;j<=n;j++)
    if(HT[j].parent==-1&&HT[j].weight<min1)
    {
        min2=min1;
        min1=HT[j].weight;
        s2=s1;
        s1=j;      
    }
    else if(HT[j].parent==-1&&HT[j].weight<min2)
    {
        min2=HT[j].weight;
        s2=j;
    }
}

void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n)
{
    int i,s1,s2;
    HT=(HuffmanTree)malloc((2*n)*sizeof(HTNode));
    for(i=0;i<n;i++)
    {
        HT[i].weight=w[i];
        HT[i].parent=-1;
        HT[i].lchild=-1;
        HT[i].rchild=-1;
    }
    for(i=n;i<2*n-1;i++)
    {
        HT[i].weight=0;
        HT[i].parent=-1;
        HT[i].lchild=-1;
        HT[i].rchild=-1;
    }
    for(i=n;i<2*n-1;++i)
    {
        Select(HT,i-1,s1,s2);
        HT[s1].parent=i;
        HT[s2].parent=i;
        HT[i].lchild=s1;
        HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
    char *cd=(char*)malloc(8*sizeof(char));
    int s,c,x;
    cd[n]='\0';
    for(i=0;i<n;i++)
    {
        s=n-1;
        c=i;
        x=HT[i].parent;
        while(x!=-1)
        {
            --s;
            if(HT[x].lchild==c) cd[s]='0';
            else cd[s]='1';
            c=x;
            x=HT[x].parent;
        }
        HC[i]=(char*)malloc((n-s)*sizeof(char));        
        strcpy(HC[i],&cd[s]);
    }
}

void PrintCode(char s[],HuffmanCode HC)
{ 
    for(int i=0;i<8;i++)
    {
        printf("%c:",s[i]);
        printf("%s\n",HC[i]);
    }
}

void  numtochar(char ns[],HuffmanTree HT,char s[]){   //输出译码串 
    char *p=ns;
    int k;
    HTNode g;
    while(*p)
    {
        g=HT[14];             
        while(g.lchild!=-1&&g.rchild!=-1&&*p)
        {
            switch(*p)
            {              
            case '0':
                    k=g.lchild;
                    g=HT[g.lchild];
                    break;
            case '1':
                    k=g.rchild;
                    g=HT[g.rchild];
                    break;
            }
            p++;
        }
        printf("%c",s[k]);
    }
}

int main()
{
    int n=8;
    int w[n]={5,29,7,8,14,23,3,11};
    char s[n]={'A','B','C','D','E','F','G','H'},ns[100];
    HuffmanCode HC;
    HuffmanTree HT;
    HuffmanCoding(HT,HC,w,n);
    PrintCode(s,HC);
    printf("输入编码进行译码\n");
    scanf("%s",&ns);
    numtochar(ns,HT,s);
    system("pause");
}
