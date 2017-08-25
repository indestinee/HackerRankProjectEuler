/*
 *  Author:
 *      Indestinee
 *  Date:
 *      2017/08/08
 *  Name:
 *      euler002.cpp
 */

#include <bits/stdc++.h>
using namespace std;
int cas;
long long a[128], n;
int main() {
    a[0] = a[1] = 1;
    for (int i = 2; i < 128; i++)
        a[i] = a[i - 1] + a[i - 2];
    scanf("%d", &cas);
    for (int i = 0; i < cas; i++) {
        long long ans = 0;
        scanf("%lld", &n);
        for (int j = 1; a[j] <= n; j++)
            if ((a[j] & 1) ^ 1)
                ans += a[j];
        printf("%lld\n", ans);
    }
    return 0;
}
