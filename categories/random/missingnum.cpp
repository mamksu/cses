#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
long n;

char buffer[200000 * 8], *p_in{buffer}, *p_out{buffer};

inline ll read()
{
    ll t = 0;
    char c;
    while ((c = getchar_unlocked()) != '\n' && c != ' ' && c != EOF)
    {
        t = t * 10 + c - '0';
    }
    return t;
}

int main()
{
    n = read();

    int_fast64_t sum{static_cast<int_fast64_t>(n + 1) * n / 2};

    while (--n)
    {
        sum -= read();
    }

    printf("%d", sum);
}