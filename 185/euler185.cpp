/*
 *  Author:
 *      Indestinee
 *  Date:
 *      2017/08/08
 *  Name:
 *      euler185.cpp
 */

#include <bits/stdc++.h>
using namespace std;
int n, good[30], cnt;
pair<long long, int> p[1000000];
long long a[30], f[1000000];

inline int work(int a, int b) {
    int cnt = 0;
    for (int i = 0; i < 6; i++, a /= 10, b /= 10)
        cnt += a % 10 == b % 10;
    return cnt;
}

inline int find(const long long &t) {
    int l = 0, r = cnt;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (p[m].first == t)
            return p[m].second;
        if (p[m].first < t) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}
int main() {
    scanf("%d", &n);
    long long status = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld%d", a + i, good + i);
        status = status << 2 | good[i];
    }
    
    for (int i = 0; i < 1000000; i++) {
        long long mask1 = 0, mask2 = 0;
        for (int j = 0; j < n; j++) {
            if (mask1 != -1) {
                int status1 = work(a[j] / 1000000, i);
                mask1 = (status1 > good[j]) ? -1 : (mask1 << 2 | status1);
            }
            if (mask2 != -1) {
                int status2 = work(a[j] % 1000000, i);
                mask2 = (status2 > good[j]) ? -1 : (mask2 << 2 | status2);
            }
        }
        f[i] = mask1;
        if (mask2 != -1)
            p[cnt++] = make_pair(mask2, i);
    }
    sort(p, p + cnt);
    for (int i = 0; i < 1000000; i++) {
        if (f[i] == -1)
            continue;
        int x = find(status - f[i]);
        if (x != -1) {
            printf("%06d%06d\n", i, x);
            break;
        }
    }
    return 0;
}
