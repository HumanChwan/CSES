#include <bits/stdc++.h>

#if ONLINE_JUDGE
#define DEBUG(...)
#else
#define DEBUG(kek) cout << "DEBUG: [ " << kek << " ]\n"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define MONKE 0
#define pf printf
#define sf scanf
#define ff first
#define ss second
#define vt(...) vector<__VA_ARGS__>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define M 1000000007
#define fl(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

bool SortGrtScnd(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.ss > b.ss);
}

int gcd(int a, int b) { return (!b ? a : gcd(b, a % b)); }

ll power(ll num, ll exp, ll MOD = M) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res = (res * num) % MOD;
        num = (num * num) % MOD;
        exp >>= 1;
    }
    return res;
}

int main() {
    // unsync with C stream :)
    ios_base::sync_with_stdio(MONKE);
    cin.tie(MONKE);
    // todo
    int n, q;
    cin >> n >> q;
    vt(ll) a(n);
    for (ll &x : a) cin >> x;

    vt(ll) pref(n + 1);
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << pref[y] - pref[x - 1] << "\n";
    }
    return MONKE;
}