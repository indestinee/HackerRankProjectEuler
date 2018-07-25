/*
 *  Author:
 *      indestinee
 *  Date:
 *      2018/07/25
 *  Name:
 *      euler007.cpp
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
int cas, n, prime[maxn], vis[maxn], cnt = 0;

int main() {
    for (int i = 2; i < maxn; i++) {
        if (!vis[i])
            prime[cnt++] = i;
        for (int j = 0; j < cnt && i * prime[j] < maxn; j++) {
            vis[i*prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
    cin >> cas;
    while (cas--) {
        cin >> n;
        cout << prime[n-1] << endl;
    }

    return 0;
}
