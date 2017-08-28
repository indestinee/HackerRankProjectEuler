/*
 *  Author:
 *      Indestinee
 *  Date:
 *      2017/08/25
 *  Name:
 *      euler188.cpp
 */

#include <bits/stdc++.h>
using namespace std;

const long long test[] = {3, 7, 17, 31, 41, 47, 43, 65537, 1000000007, 1000000009};
vector<long long> prime;

inline long long quick_mul(long long a, long long b, const long long &mod) {/*{{{*/
    long long ret = 0;
    for (; b; b >>= 1, a = (a << 1) % mod)
        if (b & 1)
            ret = (ret + a) % mod;
    return ret;
}/*}}}*/
inline long long quick_pow(long long a, long long b, const long long &mod) {/*{{{*/
    long long ret = 1;
    for (; b; b >>= 1, a = quick_mul(a, a, mod))
        if (b & 1)
            ret = quick_mul(ret, a, mod);
    return ret;
}/*}}}*/
inline long long gcd(long long a, long long b) {/*{{{*/
    return b ? gcd(b, a % b) : a;
}/*}}}*/
inline bool witness(const long long &a, long long n) {/*{{{*/
    long long d = n - 1;
    if (n == a)
        return true;
    while (!(d & 1))
        d >>= 1;
    long long t = quick_pow(a, d, n);
    while ((d != n - 1) && (t != 1) && (t != n - 1)) {
        t = quick_mul(t, t, n);
        d = d << 1;
    }
    return t == n - 1 || (d & 1) == 1;
}/*}}}*/
inline bool miller_rabin(const long long &n) {/*{{{*/
    if (n == 2)
        return true;
    if (n < 2 || (n & 1) == 0)
        return false;
    for (auto p: test)
        if (!witness(p, n))
            return false;
    return true;
}/*}}}*/
inline long long pollard_rho(const long long &n, const long long &c) {/*{{{*/
    long long x, y, d, i = 1, k = 2;
    y = x = (((long long) rand()) << 31 | rand()) % (n - 1) + 1;
    while (true) {
        i++;
        x = (quick_mul(x, x, n) + c) % n;
        d = gcd((y - x + n), n);
        if (1 < d && d < n)
            return d;
        if (y == x)
            return n;
        if (i == k) {
            y = x;
            k <<= 1;
        }
    }

}/*}}}*/
void find(const long long &n) {/*{{{*/
    if (n == 1)
        return;
    if (miller_rabin(n)) {
        prime.push_back(n);
        return;
    }
    long long p = n;
    while (p == n)
        p = pollard_rho(p, rand() % p); 
    find(p);
    find(n / p);
}/*}}}*/
inline long long brute_force(long long m) {/*{{{*/
    long long phi = 1;
    for (long long i = 2; i * i <= m; i++) {
        if (m % i == 0) {
            m /= i;
            phi *= i - 1;
            while (m % i == 0)
                m /= i, phi *= i;
        }
    }
    if (m > 1)
        phi *= m - 1;
    return phi;
}/*}}}*/
inline long long phi(const long long &m) {/*{{{*/
    find(m);
    sort(prime.begin(), prime.end());
    long long q = 1;
    for (int j = 0; j < int(prime.size()); j++)
        q *= prime[j] - (j == 0 || prime[j] != prime[j - 1]);
    prime.clear();
    return q;

}/*}}}*/
inline long long pow(const long long &a, const long long &b, const long long &maxi) {/*{{{*/
    long long j = 1;
    for (long long i = 0; i < b; i++) {
        if (maxi / a >= j) {
            j *= a;
        } else {
            return maxi;
        }
    }
    return j;
}/*}}}*/
inline long long work(const long long &a, const long long &b) {/*{{{*/
    long long j = 1;
    for (long long i = 0; i < b; i++)
        if ((j = pow(a, j, 64)) == 64)
            return j;
    return j;
}/*}}}*/

inline pair<long long, long long> work(const long long &a, const long long &b, const long long &mod) {/*{{{*/
    if (b == 1)
        return make_pair(a % mod, 1);
    if (mod == 1)
        return make_pair(0, work(a, b - 1));
    
    long long p = phi(mod);
    auto res = work(a, b - 1, p);
    long long first = res.first, second = res.second, delta = (pow(a, second, mod) == mod) ? p : 0;
    if (second < 64)
        second = pow(a, second, 64);
    /* cout << res.first << " " << res.second << endl; */
    /* cout << a << " " << first << " " << delta << " " << mod << endl; */
    return make_pair(quick_pow(a, first + delta, mod), second);
}/*}}}*/
int cas;
long long a, b, mod;
int main() {/*{{{*/
    cin >> cas;
    while (cas--) {
        cin >> a >> b >> mod;
        if (a == 1) {
            cout << a % mod << endl;
        } else {
            cout << work(a, b, mod).first << endl;
        }
    }
    return 0;
}/*}}}*/
