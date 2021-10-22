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

#if ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) std::cout << x
#endif

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

int recurs(int n, int k) {
    if (n == 1 && k == 1) {
        return 1;
    }
    if (k <= n / 2) {
        return k * 2;
    }
    int abs_ans = (recurs((n + 1) / 2, k - n / 2) * 2 - (n & 1 ? 3 : 1));
    (abs_ans < 0 && (abs_ans += (1 + n)));
    return abs_ans;
}

int main() {
    ios_base::sync_with_stdio(MONKE);
    cin.tie(MONKE);
    // todo
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        cout << recurs(n, k) << "\n";
    }
    return MONKE;
}