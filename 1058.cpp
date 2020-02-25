#include<cstdio>
#include<iostream>
using namespace std;
int read(){
    int ans=0;
    char last=' ',ch=getchar();
    while(ch<'0'||ch>'9')
    last=ch,ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        ans=(ans<<1)+(ans<<3)+(ch^48);
        ch=getchar();
    }
    return last=='-'?-ans:ans;
}
char c[1001][1001],c1[10][10]={//倒着存储 
    "+---+",
    "|   |/",
    "|   | +",
    "+---+ |",
    " /   /|",
    "  +---+",
    };//6行7列 的方块 
int n,m,jz[51][51],maxh=-1,maxl=-1,zbx,zby;
inline void fg(int zbx,int zby)//覆盖操作 
{
    for(int i=0;i<=4;i++)c[zbx][zby+i]=c1[0][i];
    for(int i=0;i<=5;i++)c[zbx+1][zby+i]=c1[1][i];
    for(int i=0;i<=6;i++)c[zbx+2][zby+i]=c1[2][i];
    for(int i=0;i<=6;i++)c[zbx+3][zby+i]=c1[3][i];
    for(int i=1;i<=6;i++)c[zbx+4][zby+i]=c1[4][i];
    for(int i=2;i<=6;i++)c[zbx+5][zby+i]=c1[5][i];
}
int main(){
    m=read();n=read();
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            jz[i][j]=read();
        }
    }
    for(int i=1;i<=m;i++)//从输入的矩阵的左上角开始，满足先后，先左 
        for(int j=1;j<=n;j++)
        {
            zbx=(m-i)*2+1;zby=(m-i)*2+1+4*(j-1);
            for(int k=1;k<=jz[i][j];k++,zbx+=3)
            {
                fg(zbx,zby);
            }
            if(zbx+2>maxh)maxh=zbx+2;
            if(zby+6>maxl)maxl=zby+6;
        }
    for(int i=maxh;i>=1;i--)
    {
        for(int j=1;j<=maxl;j++)
        {
            if(c[i][j]=='\0') printf(".");
            else
            printf("%c",c[i][j]);
        }
        printf("\n");
    }
    return 0;    
}