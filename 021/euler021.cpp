/*
 *  Author:
 *      indestinee
 *  Date:
 *      2018/08/23
 *  Name:
 *      euler021.cpp
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int d[maxn], cnt[maxn];
int main() {
    for (int i = 1; i < maxn; i++) {
        d[i] = -i;
        for (int j = 1; j * j <= i; j++) {
            if (i % j)
                continue;
            d[i] += j;
            if (j * j != i)
                d[i] += i / j;
        }
    }
    
    for (int i = 1; i < maxn; i++)
        if (d[i] < maxn && d[d[i]] == i && i != d[i])
            cnt[i] += i;

    for (int i = 1; i < maxn; i++)
        cnt[i] += cnt[i-1];

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << cnt[n] << endl;
    }

    return 0;
}
