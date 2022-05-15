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

const int MAX_N = 502;
int rect_min[MAX_N][MAX_N];

int main() {
    // unsync with C stream :)
    ios_base::sync_with_stdio(MONKE);
    cin.tie(0);
    // todo
    int a, b;
    cin >> a >> b;
    if (b > a)
        swap(a, b);
    const int INF = 1e9;
    for (int i = 0; i < MAX_N; ++i)
        for (int j = 0; j < MAX_N; ++j)
            rect_min[i][j] = INF;
    for (int i = 1; i <= a; ++i) {
        rect_min[i][i] = 0;
    }
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j < i; ++j) {
            for (int k = 1; k <= i / 2; ++k)
                rect_min[i][j] = min(
                    rect_min[i][j], 1 + rect_min[max(j, k)][min(j, k)] +
                                        rect_min[max(j, i - k)][min(j, i - k)]);

            for (int k = 1; k <= j / 2; ++k)
                rect_min[i][j] = min(rect_min[i][j],
                                     1 + rect_min[i][k] + rect_min[i][j - k]);
        }
    }
    cout << rect_min[a][b];
    return MONKE;
}