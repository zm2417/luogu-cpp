#include <iostream>
using namespace std;

void dfs(int n)
{
    if(n == 0)
    {
        cout << '0';
    }else if (n == 1)
    {
        cout <<"2(0)";
    }else if (n == 2)
    {
        cout << "2";
    }else
    {
        int k = n,j = 0;
        while (k>>=1)
        {
            j++;
        }
        bool pd = true;
        for(int i = j;i >=0;i--)
        {   
            if((n>>i) & 1)
            {
                if(pd)
                    pd = false;
                else
                {
                    cout << '+';
                }
                if(i == 1) 
                    cout << "2";
                else
                {
                    cout << "2(";
                    dfs(i);
                    if(i == 0) cout << ")";
                    else
                    {
                        cout << ")";
                    }
                }
            }
        }
    }
    
    
}

int main()
{
    int n;
    cin >> n;
    dfs(n);
}