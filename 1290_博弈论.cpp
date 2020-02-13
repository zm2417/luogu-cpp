#include <iostream>
using namespace std;

int c, m, n;

// 对于这道题，我们考虑什么样的状态（假设状态为（x，y）假定y>=x）可以使当前操作的这个人胜利，显然，当x==y时，当前操作的这个人必胜了；或者当y为x的倍数是，当前这个人也会获胜。除此之外呐？于是，我们接下来要考虑y > x的情况。

// 假设y=kx+z（z为余数）

// 如果k>=2，那么该状态可以转移到（x,y-(k-1)x）即(x,x+z)，而(x,x+z)(z要小于x的，因为z是余数)，只能转移到(x,z)这一个状态，这个应该很好理解的。而（x,y）也可以直接转移到这个状态（x,z），所以不论（x,x+z）这个状态还是其下一个状态（x,z）为必胜状态，(x,y)均可到达，所以当k>=2时，当前操作者必胜。

// 如果k<2呢？那我们只好转到下一个人操作，我们再尝试在下一个人的状态中判断这个人是否必胜。因为k<2, 所以(x,y)只能转到(z,x)这个状态。那我们只要递归下去，知道找到必胜状态，返回当前操作者即可。
bool check(int x, int y)
{
    if (x == y)
        return true;
    if (y / x >= 2)
        return true;
    return !check(y - x, x);
}

int main()
{
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> m >> n;
        if (check(min(m, n), max(m, n)))
            cout << "Stan wins" << endl;
        else
            cout << "Ollie wins" << endl;
    }
    return 0;
}