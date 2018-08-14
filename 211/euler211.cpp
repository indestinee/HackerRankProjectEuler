/*
 *  Author:
 *      indestinee
 *  Date:
 *      2018/08/14
 *  Name:
 *      euler211.cpp
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 6e6 + 10, maxq = 1e5 + 10, maxv = 1e6 + 10;
int prime[maxn], vis[maxn];

long long sum[maxn], division[maxn], d[maxn], ans[maxq], c[maxv];

inline void calc(const long long &m, const long long &a, const long long &p) {
    if (a % p == 0) {
        division[m] = division[a] * p * p + 1;
        sum[m] = sum[a] / division[a] * division[m];
    } else {
        division[m] = (1 + p * p);
        sum[m] = sum[a] * division[m];
    }
}

inline int lowbit(const int &x) {
    return -x & x;
}
inline void modify(int x, const int &value) {
    if (x == 0) {
        c[0] += value;
        return;
    }
    while (x < maxv) {
        c[x] += value;
        x += lowbit(x);
    }
}

inline long long query(int x) {
    long long sum = c[0];
    while (x > 0) {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}

struct query{
    int n, k;
    int id;
    inline friend bool operator < (const query &a, const query &b) {
        return a.n < b.n;
    }
} a[maxq];

int q;



int main() {
    sum[1] = 1;
    int cnt = 0;
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[cnt++] = i;
            sum[i] = i * (long long) i + 1;
            division[i] = sum[i];
        }
        for (int j = 0; j < cnt && i * prime[j] < maxn; j++) {
            vis[i * prime[j]] = 1;
            calc(i * prime[j], i, prime[j]);
            if (i % prime[j] == 0)
                break;
        }
    }

    
    for (int i = 1; i < maxn; i++) {
        long long j = sqrt(sum[i] + 0.5);
        d[i] = min(sum[i] - j * j, (j + 1) * (j + 1) - sum[i]);
    }

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &a[i].n, &a[i].k);
        a[i].id = i;
    }       


    sort(a, a + q);
    
    int cur = 1;
    for (int i = 0; i < q; i++) {
        while (cur <= a[i].n) {
            if (d[cur] < maxv)
                modify(d[cur], cur);
            cur++;
        }
        ans[a[i].id] = query(a[i].k);
    }


    for (int i = 0; i < q; i++)
        printf("%lld\n", ans[i]);
    


    return 0;
}
