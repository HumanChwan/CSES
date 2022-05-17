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
ostream& operator<<(ostream& os, vector<T> container) {
    os << "\n[ ";
    for (auto x : container)
        os << x << " ";
    os << "]\n";
    return os;
}

template <typename T1, typename T2>
bool sort_by_second_greater(const pair<T1, T2>& a, const pair<T1, T2>& b) {
    return (a.ss > b.ss);
}

vt(vt(int)) edges;
vt(long long) ways;
vt(bool) vis;

long long get_ways(int i, const int n) {
    if (i == n - 1)
        return 1LL;

    if (vis[i])
        return ways[i];

    vis[i] = true;

    long long w = 0;
    for (int child : edges[i]) {
        w = (w + get_ways(child, n)) % M;
    }

    return ways[i] = w;
}

int main() {
    // unsync with C stream :)
    ios_base::sync_with_stdio(MONKE);
    cin.tie(0);
    // todo
    int n, m;
    cin >> n >> m;
    edges = vt(vt(int))(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].pb(b);
    }
    ways = vt(long long)(n);
    vis = vt(bool)(n);

    cout << get_ways(0, n);

    return MONKE;
}