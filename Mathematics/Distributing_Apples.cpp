#include <bits/stdc++.h>

#define MONKE 0
#define M 1000000007
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef long double ld;

using namespace std;

long long power(long long num, long long exp, long long MOD = M) {
    long long res = 1;
    while (exp) {
        if (exp & 1) res = (res * num) % MOD;
        num = (num * num) % MOD;
        exp >>= 1;
    }
    return res;
}

long long factorial(long long n) {
    long res = 1;
    for (int i = 2; i <= n; ++i) {
        res = (res * i) % M;
    }
    return res;
}

long long invfactorial(long long n) {
    long long inv = factorial(n);
    return power(inv, M - 2);
}

long long Combination(long long n, long long r) {
    return ((((factorial(n) % M) * (invfactorial(r) % M)) % M) *
            invfactorial(n - r)) %
           M;
}

int main() {
    ios_base::sync_with_stdio(MONKE);  // unsync uWu
    cin.tie(MONKE);                    // cin-cout unsync uWu
    int children, apple;
    cin >> children >> apple;
    cout << Combination(children + apple - 1, children - 1);
    return MONKE;
}