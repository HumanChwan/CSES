#include <bits/stdc++.h>

#if ONLINE_JUDGE
#define DEBUG(...)
#else
#define DEBUG(kek) cout << "DEBUG: [ " << #kek << " = " << kek << " ]\n"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define ff first
#define ss second
#define vt(...) vector<__VA_ARGS__>
#define sz(...) (int)(__VA_ARGS__).size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

constexpr int M = 1000000007;
constexpr int MONKE = 0;

using namespace std;

template <typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2>& a) {
    os << "{" << a.first << ", " << a.second << "}";
    return os;
}

template <typename T>
void debug(T container) {
    cerr << "[ ";
    for (auto x : container)
        cerr << x << " ";
    cerr << "]";
}

template <typename T1, typename T2>
bool sort_by_second_greater(const pair<T1, T2>& a, const pair<T1, T2>& b) {
    return (a.ss > b.ss);
}

ll power(ll num, ll exp, ll MOD = M) {
    ll res = 1;
    while (exp) {
        if (exp & 1)
            res = (res * num) % MOD;
        num = (num * num) % MOD;
        exp >>= 1;
    }
    return res;
}

int main() {
    // unsync with C stream :)
    ios_base::sync_with_stdio(MONKE);
    cin.tie(0);
    // todo
    ll n;
    cin >> n;
    ll prev = n;
    ll ans = 0;
    for (ll i = 1; i * i <= n; ++i) {
        ans = (ans + ((n / i) * i) % M) % M;
        ll high_lim = (n / i);
        ll low_lim = max((n / (i + 1)), i);
        ll r = (high_lim - low_lim);
        ll other = 0;  // (r * (r + 2 * low_lim + 1)) / 2;
        if (r & 1) {
            ll half = (r + 2 * low_lim + 1) / 2;
            half %= M;
            other = ((r % M) * half);
        } else {
            ll half = r / 2;
            half %= M;
            other = (((r + 2 * low_lim + 1) % M) * half);
        }
        other %= M;
        ans = (ans + other * i) % M;
        prev = high_lim;
    }
    cout << ans;
    return MONKE;
}