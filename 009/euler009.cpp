/*
 *  Author:
 *      indestinee
 *  Date:
 *      2018/07/25
 *  Name:
 *      euler009.cpp
 */

#include <bits/stdc++.h>
using namespace std;


int n, cas, p2[3001], f[3001];

int main() {
    cin >> cas;
    memset(f, -1, sizeof f);
    for (int i = 0; i <= 3000; i++)
        p2[i] = i * i;

    for (int i = 1; i <= 1500; i++) {
        for (int j = 1; j <= i; j++) {
            int u = p2[i] + p2[j];
            auto x = lower_bound(p2, p2 + 3000, u);
            if (*x == u && x - p2 + i + j <= 3000) {
                f[x-p2+i+j] = max(f[x-p2+i+j], i * j * int(x-p2));
            }
        }
    }

    while (cas--) {
        cin >> n;
        cout << f[n] << endl;
    }


    return 0;
}
