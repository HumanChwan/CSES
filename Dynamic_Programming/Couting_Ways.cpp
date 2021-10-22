#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define MONKE 0
#define pf printf
#define sf scanf
#define ff first
#define ss second
#define vt(x) vector<x>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define M 1000000007
#define fl(i, a, b) for (int i = a; i < b; i++)

using namespace std;

bool SortGrtScnd(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.second > b.second);
}

int gcd(int a, int b) {
    if (!b)
        return a;
    else
        return (gcd(b, a % b));
}

ll pow(ll num, ll exp, ll MOD = M) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res = (res * num) % MOD;
        num = (num * num) % MOD;
        exp /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(MONKE);
    cin.tie(MONKE);
    // todo
    string a, b;
    cin >> a >> b;
    if (a.length() > b.length()) {
        a.swap(b);
    }
    int n = a.length(), b = a.length();

    for (int i = 0; i < n; ++i) {
    }
    return MONKE;
}