/*
 *  Author:
 *      indestinee
 *  Date:
 *      2018/07/23
 *  Name:
 *      euler215.cpp
 */

#include <bits/stdc++.h>
using namespace std;

int w, h, m;
vector<long long> v;
vector<int> g[200000];
int dp[51][200000];

void dfs(const int &sum, const long long &x) {
    if (sum == w) {
        v.push_back(x);
        return;
    } 
    if (sum > w)
        return;
    dfs(sum + 2, x << 2 | 2);
    dfs(sum + 3, x << 2 | 3);
}

inline int find(long long x) {
    long long m = 0;
    while (x) {
        m = m << 2 | (x & 3);
        x >>= 2;
    }
    int l = 0, r = int(v.size()) - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (v[mid] == m)
            return mid;
        if (v[mid] < m) { 
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int cnt = 0;
void dfs2(int id, int sum, long long mask, int value, long long nmask) {
    sum += mask & 3;
    mask >>= 2;

    if (mask == 0) {
        if (sum - value == 2) {
            g[id].push_back(find(nmask << 2 | 2));
        } else if (sum - value == 3) {
            g[id].push_back(find(nmask << 2 | 3));
        } else if (sum - value == 4) {
            g[id].push_back(find(nmask << 4 | 10));
        }
        return;
    }
    
    if (sum - value == 2) {
        dfs2(id, sum, mask, value + 3, nmask << 2 | 3);
    } else if (sum - value == 3) {
        dfs2(id, sum, mask, value + 2, nmask << 2 | 2);
    } else if (sum - value == 4) {
        dfs2(id, sum, mask, value + 3, nmask << 2 | 3);
        dfs2(id, sum, mask, value + 5, nmask << 4 | 11);
    } else if (sum - value == 1) {
        dfs2(id, sum, mask, value, nmask);
    } else if (sum - value == -1) {
        dfs2(id, sum, mask, value, nmask);
    }

}

int main() {
    scanf("%d%d%d", &w, &h, &m);
    /* w = 45, h = 100, m = 1<<30; */
    dfs(0, 0LL);
    sort(v.begin(), v.end());
    for (int i = 0; i < int(v.size()); i++)
        dfs2(i, 0, v[i], 0, 0LL);

    int n = v.size();

    for (int i = 0; i < n; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= h-(h>>1); i++) {
        memset(dp[i], 0, n << 2);
        for (int j = 0; j < n; j++)
            if (dp[i-1][j])
                for (int k = 0; k < int(g[j].size()); k++)
                    dp[i][g[j][k]] = (dp[i][g[j][k]] + dp[i-1][j]) % m;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < int(g[i].size()); j++)
            sum = (dp[h>>1][i] * (long long) dp[h-(h>>1)][g[i][j]] + sum) % m;
    }
    printf("%d\n", sum);
    


    return 0;
}

/*
    2 2 2 3  3 2 2 2 
    2 2 3 2  3 3 3 // 3 2
    2 3 2 2  3 3 3
    3 2 2 2  2 2 2 3
    3 3 3    2 3 2 2
             2 2 3 2

*/
