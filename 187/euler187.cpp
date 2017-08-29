/*
 *  Author:
 *      Indestinee
 *  Date:
 *      2017/08/29
 *  Name:
 *      euler187.cpp
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e7;
int n, cas, prime[maxn / 10], tot;
bool vis[maxn];
void euler_sieve() {
    for (int i = 2; i < maxn; i++) {
        if (!vis[i])
            prime[tot++] = i;
        for (int j = 0; j < tot && prime[j] * i < maxn; j++) {
            vis[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
int main() {
    euler_sieve();
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n);
        n--;
        int j = tot - 1, ans = 0;
        for (int i = 0; i < tot && (prime[i] << 1) <= n; i++) {
            while (prime[j] * prime[i] > n && j >= i)
                j--;
            if (j < i)
                break;
            ans += j - i + 1;
        }
        cout << ans << endl;
    }

    return 0;
}
