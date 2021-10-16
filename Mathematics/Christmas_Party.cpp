#include <bits/stdc++.h>

#define MONKE 0
#define M 1000000007
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef long double ld;

using namespace std;
const int maxN = 1e6 + 5;
long long factorial[maxN];

void ComputeFactorials() {
    factorial[0] = 1LL;
    for (long long i = 1LL; i < maxN; ++i) {
        factorial[i] = (i * factorial[i - 1]) % M;
    }
}

long long power(long long num, int exp) {
    long long res = 1;
    while (exp) {
        if (exp & 1) {
            res = (res * num) % M;
        }

        num = (num * num) % M;

        exp >>= 1;
    }

    return res;
}

long long inverseFactorial(int k) { return power(factorial[k], M - 2); }

int main() {
    ios_base::sync_with_stdio(MONKE);  // unsync uWu
    cin.tie(MONKE);                    // cin-cout unsync uWu
    ComputeFactorials();
    int n;
    cin >> n;

    long long ways = 0;
    for (int i = 0; i <= n; ++i) {
        long long part = (factorial[n] * inverseFactorial(i)) % M;
        ways = (ways + (i & 1 ? -1 : 1) * part) % M;
    }
    cout << (ways > 0 ? ways : ways + M);
    return MONKE;
}