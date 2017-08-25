/*
 *  Author:
 *      Indestinee
 *  Date:
 *      2017/08/08
 *  Name:
 *      euler001.cpp
 */

#include <bits/stdc++.h>
using namespace std;
int cas, n;
long long f(int a, long long x) {
    long long l = 0, r = x - x % a;
    return (l + r) * (r / a + 1) >> 1;
}

int main() {
    cin >> cas;
    while (cas--) {
        cin >> n;
        n--;
        cout << f(3, n) + f(5, n) - f(15, n) << endl;
    }

    return 0;
}
