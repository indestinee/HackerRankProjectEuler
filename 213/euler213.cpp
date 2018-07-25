/*
 *  Author:
 *      indestinee
 *  Date:
 *      2018/07/25
 *  Name:
 *      euler213.cpp
 */

#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007LL, inv[5] = {
    0, 1, (mod + 1) >> 1, (mod + 1) / 3, (mod + 1) >> 2
};

long long f[2][1600], dp[40][40], *bef, *now;
int cas, n, m;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

inline long long work(int x, int y) {
    if (n == 1)
        return 0;
    x = min(x, n - 1 - x);
    y = min(y, n - 1 - y);
    if (x > y)
        swap(x, y);
    if (dp[x][y] != -1)
        return dp[x][y];

    memset(f, 0, sizeof f);
    now = f[0], bef = f[1];
    now[x*n+y] = 1;

    for (int i = 0; i < m; i++) {
        swap(now, bef);
        memset(now, 0, n*n<<3);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int d = 0; d < 4; d++) {
                    int nj = j + dx[d], nk = k + dy[d], 
                        cnt = 4 - int(nj==0||nj==n-1) - int(nk==0||nk==n-1);
                    if (nj > -1 && nj < n && nk > -1 && nk < n) {
                        now[nj * n + nk] = (
                            now[nj*n + nk] + bef[j*n+k] * inv[cnt]
                        ) % mod;
                    }
                }
            }
        }
    }
        
    long long p = 1;
    for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
            p = p * (mod + 1LL - now[j*n+k]) % mod;
    dp[x][y] = p;
    return p;
}

int main() {

    scanf("%d", &cas);
    while (cas--) {
        memset(dp, -1, sizeof dp);
        scanf("%d%d", &n, &m);
        long long ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans = (ans + work(i, j)) % mod;
        printf("%lld\n", ans);
    }


    return 0;
}
