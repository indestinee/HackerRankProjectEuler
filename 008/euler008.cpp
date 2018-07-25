/*
 *  Author:
 *      indestinee
 *  Date:
 *      2018/07/25
 *  Name:
 *      euler008.cpp
 */

#include <bits/stdc++.h>
using namespace std;

int cas, n, k;
char s[10000];

int main() {
    cin >> cas;
    while (cas--) {
        cin >> n >> k;
        cin >> s;
        int maxi = 0;
        for (int i = 0; i + k - 1 < n; i++) {
            int q = 1;
            for (int j = 0; j < k; j++)
                q *= s[i+j] - '0';
            maxi = max(maxi, q);
        }
        cout << maxi << endl;
    }


    return 0;
}
