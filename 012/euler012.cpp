/*
 *  Author:
 *      indestinee
 *  Date:
 *      2018/08/15
 *  Name:
 *      euler012.cpp
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 50000;

long long a[maxn], b[maxn];

inline int calc(const long long &n) {
    long long cnt = 0;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i)
            continue;
        cnt++;
        if (i * i == n)
            continue;
        cnt++;
    }
    return cnt;
}
inline void work(const long long &x) {
    long long cnt = 0;
    if (x & 1) {
        cnt = calc(x) * calc((x + 1) >> 1);
    } else {
        cnt = calc(x >> 1) * calc(x + 1);
    }
    a[x] = x * (x + 1) >> 1, b[x] = cnt;
}
int main() {
    //  (n + 1) * n / 2
    
    for (int i = 1; i < maxn; i++)
        work(i);

    int n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i < maxn; i++) {
            if (b[i] > n) {
                cout << a[i] << endl;
                break;
            }
        }
    }

    

    return 0;
}
