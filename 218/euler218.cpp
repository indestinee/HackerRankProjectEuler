/*
 *  Author:
 *      indestinee
 *  Date:
 *      2018/08/23
 *  Name:
 *      euler218.cpp
 */

#include <bits/stdc++.h>
using namespace std;
int gcd(const int &x, const int &y) {
    return y ? gcd(y, x % y) : x;
}
int main() {
    int n = 26;
    for (int i = 1; i < n; i++) {
        for (int j = i + 2; j < n; j++) {
            int sq = i * i + j * j, k = int(sqrt(sq + 0.5));
            if (k * k == sq) {
                if (gcd(i, j) == 1 && gcd(j, k) == 1) {
                    cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }
            


    return 0;
}
