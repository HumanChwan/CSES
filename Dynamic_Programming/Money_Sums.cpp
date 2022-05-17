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
    int n;
    cin >> n;
    int coins[n];
    for (int i = 0; i < n; ++i)
        cin >> coins[i];

    const int MAX = 1e5 + 5;
    static bool possible[MAX] = {0};
    possible[0] = true;

    for (int i = 0; i < n; ++i) {
        vt(int) add;
        for (int j = coins[i]; j <= MAX; ++j) {
            if (possible[j - coins[i]])
                add.pb(j);
        }
        for (int x : add)
            possible[x] = true;
    }
    vt(int) poss;
    for (int i = 1; i <= MAX; ++i)
        if (possible[i])
            poss.pb(i);
    cout << sz(poss) << "\n";
    for (int x : poss)
        cout << x << " ";
    return MONKE;
}