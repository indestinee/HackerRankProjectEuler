/*
 *  Author:
 *      indestinee
 *  Date:
 *      2018/07/25
 *  Name:
 *      euler004.cpp
 */

#include <bits/stdc++.h>
using namespace std;
int cas, n;
set<int> s;
int main() {
    for (int i = 100; i < 1000; i++) {
        for (int j = 100; j < 1000; j++) {
            int k = i * j, l = 0;
            for (int u = k; u; u /= 10)
                l = l * 10 + u % 10;
            if (k == l)
                s.insert(k);
        }
    }
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n);
        printf("%d\n", *(--s.lower_bound(n)));
    }

    return 0;
}
