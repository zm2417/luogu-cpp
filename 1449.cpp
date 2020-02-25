#include<bits/stdc++.h>
using namespace std;
#define N 1005
int main()
{
 char s[N];
 int stackk[N];
 int top=0,i=0,x;
 scanf("%s",s);
 while(s[i]!='@')
 {
     switch(s[i])
     {
        case'+':stackk[--top]+=stackk[top+1];break;
        case'-':stackk[--top]-=stackk[top+1];break;
        case'*':stackk[--top]*=stackk[top+1];break;
        case'/':stackk[--top]/=stackk[top+1];break;
        default:x=0;while(s[i]!='.')x=x*10+s[i++]-'0';
         stackk[++top]=x;break;
     }
     i++;
 }
 cout<<stackk[top]<<endl;
  return 0;
}