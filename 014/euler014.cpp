/*
 *  Author:
 *      indestinee
 *  Date:
 *      2018/08/15
 *  Name:
 *      euler014.cpp
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e6+10;
int dp[maxn], ans[maxn];
unordered_map<long long, int> mp;
int dfs(const long long &x) {
    if (x == 1)
        return 0;
    if (x < maxn && dp[x])
        return dp[x];
    if (x >= maxn) {
        int t = mp[x];
        if (t)
            return t;
    }

    int ans = dfs((x & 1) ? x * 3 + 1 : (x >> 1)) + 1;
    if (x < maxn) {
        dp[x] = ans;
    } else {
        mp[x] = ans;
    }
    
    return ans;
}
int main() {
    map<int, int> final;
    final[1] = 1;
    final[2] = 2;
    final[3] = 3;
    final[6] = 6;
    final[7] = 7;
    final[9] = 9;
    final[18] = 18;
    final[19] = 19;
    final[25] = 25;
    final[27] = 27;
    final[54] = 54;
    final[55] = 55;
    final[73] = 73;
    final[97] = 97;
    final[129] = 129;
    final[171] = 171;
    final[231] = 231;
    final[235] = 235;
    final[313] = 313;
    final[327] = 327;
    final[649] = 649;
    final[654] = 654;
    final[655] = 655;
    final[667] = 667;
    final[703] = 703;
    final[871] = 871;
    final[1161] = 1161;
    final[2223] = 2223;
    final[2322] = 2322;
    final[2323] = 2323;
    final[2463] = 2463;
    final[2919] = 2919;
    final[3711] = 3711;
    final[6171] = 6171;
    final[10971] = 10971;
    final[13255] = 13255;
    final[17647] = 17647;
    final[17673] = 17673;
    final[23529] = 23529;
    final[26623] = 26623;
    final[34239] = 34239;
    final[35497] = 35497;
    final[35655] = 35655;
    final[52527] = 52527;
    final[77031] = 77031;
    final[106239] = 106239;
    final[142587] = 142587;
    final[156159] = 156159;
    final[216367] = 216367;
    final[230631] = 230631;
    final[410011] = 410011;
    final[511935] = 511935;
    final[626331] = 626331;
    final[837799] = 837799;
    final[1117065] = 1117065;
    final[1126015] = 1126015;
    final[1501353] = 1501353;
    final[1564063] = 1564063;
    final[1723519] = 1723519;
    final[2298025] = 2298025;
    final[3064033] = 3064033;
    final[3542887] = 3542887;
    final[3732423] = 3732423;
    int q, n;
    cin >> q;
    while (q--) {
        cin >> n;
        cout << (--final.upper_bound(n))->second << endl;
    }
    return 0;

    for (int i = 1; i < maxn; i++)
        dfs(i);
    int maxi = 1;
    for (int i = 1; i < maxn; i++) {
        if (dp[i] >= dp[maxi])
            maxi = i;
        ans[i] = maxi;
    }
    for (int i = 2; i < maxn; i++)
        if (ans[i] != ans[i-1])
            cout << "final[" << i << "] = " << ans[i] << ";" << endl;
}
