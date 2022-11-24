#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
long res;

inline int read()
{
    int t = 0;
    char c;
    while ((c = getchar_unlocked()) != '\n' && c != ' ' && c != EOF)
    {
        t = t * 10 + c - '0';
    }
    return t;
}

void out(long long x)
{
    char str[20];
    int pos = 0;
    do
    {
        str[pos++] = x % 10 + '0';
        x /= 10;
    } while (x);
    for (int i = pos - 1; i >= 0; i--)
        putchar_unlocked(str[i]);
    putchar_unlocked(' ');
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    res = read();
    out(res);

    while (res > 1)
    {
        if (res % 2 == 0)
            res /= 2;
        else
            res = (res * 3) + 1;
        out(res);
    }
    return 0;
}