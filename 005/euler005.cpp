/*
 *  Author:
 *      indestinee
 *  Date:
 *      2018/07/25
 *  Name:
 *      euler005.cpp
 */

#include <bits/stdc++.h>
using namespace std;

int cas, n;
long long f[41];
long long gcd(const long long &x, const long long &y) {
    return y?gcd(y, x%y):x;
}
int main() {
    cin >> cas;
    f[0] = 1;
    for (int i = 1; i <= 40; i++) {
        f[i] = f[i-1] / gcd(f[i-1], i) * i;
    }
    while (cas--) {
        cin >> n;
        cout << f[n] << endl;
    }
    return 0;
}
