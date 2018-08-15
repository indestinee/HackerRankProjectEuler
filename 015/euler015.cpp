/*
 *  Author:
 *      indestinee
 *  Date:
 *      2018/08/15
 *  Name:
 *      euler015.cpp
 */

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int c[1010][1010];
int main() {
    for (int i = 1; i <= 1000; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
    }
    int n, m, q;
    cin >> q;
    while (q--) {
        cin >> n >> m;
        cout << c[n+m][n] << endl;
    }

    return 0;
}
