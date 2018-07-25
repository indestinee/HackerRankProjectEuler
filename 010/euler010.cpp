/*
 *  Author:
 *      indestinee
 *  Date:
 *      2018/07/25
 *  Name:
 *      euler010.cpp
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
int prime[maxn], vis[maxn], cnt = 0, cas, n;
long long s[maxn];
int main() {
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[cnt++] = i;
        }
        for (int j = 0; j < cnt && prime[j] * i < maxn; j++) {
            vis[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
    s[0] = prime[0];
    for (int i = 1; i < cnt; i++)
        s[i] = s[i-1] + prime[i];
    
    cin >> cas;
    while (cas--) {
        cin >> n;
        cout << s[upper_bound(prime, prime+cnt, n)-prime-1] << endl;
    }


    return 0;
}
