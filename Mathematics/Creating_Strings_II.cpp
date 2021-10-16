#include <bits/stdc++.h>

#define MONKE 0
#define M 1000000007
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef long double ld;

using namespace std;
const int maxN = 1e6 + 5;
long long factorial[maxN];

void computeFactorials() {
    factorial[0] = 1;
    for (long long i = 1; i < maxN; ++i) {
        factorial[i] = (factorial[i - 1] * i) % M;
    }
}

long long power(long long num, long long exp, long long MOD = M) {
    long long res = 1;
    while (exp) {
        if (exp & 1) res = (res * num) % MOD;
        num = (num * num) % MOD;
        exp >>= 1;
    }
    return res;
}

long long invfactorial(long long n) {
    long long inv = factorial[n];
    return power(inv, M - 2);
}

int main() {
    ios_base::sync_with_stdio(MONKE);  // unsync uWu
    cin.tie(MONKE);                    // cin-cout unsync uWu
    computeFactorials();
    string patternString;
    cin >> patternString;
    int len = patternString.length();
    vector<int> alphaFrequency(26);
    for (char x : patternString) {
        alphaFrequency[(int)(x - 'a')]++;
    }

    long long ways = factorial[len];
    for (int i : alphaFrequency) {
        ways = (ways * invfactorial(i)) % M;
    }
    cout << ways;
    return MONKE;
}