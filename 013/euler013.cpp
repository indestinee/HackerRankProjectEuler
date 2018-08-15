/*
 *  Author:
 *      indestinee
 *  Date:
 *      2018/08/15
 *  Name:
 *      euler013.cpp
 */

#include <bits/stdc++.h>
using namespace std;
int n;
char a[1010];

int main() {
    cin >> n;
    long long ans0 = 0, ans1 = 0, ans2 = 0, t0, t1, t2;
    for (int i = 0; i < n; i++) {
        cin >> a;
        sscanf(a + 36, "%lld", &t2);
        a[32] = 0;
        sscanf(a + 18, "%lld", &t1);
        a[14] = 0;
        sscanf(a + 00, "%lld", &t0);
        ans2 += t2;
        ans1 += t1 + ans2 / 1000000000000000000LL;
        ans0 += t0 + ans1 / 1000000000000000000LL;
        ans1 %= 1000000000000000000LL;
        ans2 %= 1000000000000000000LL;
    }
    sprintf(a, "%lld", ans0);
    a[10] = 0;
    cout << a << endl;
    return 0;
}
