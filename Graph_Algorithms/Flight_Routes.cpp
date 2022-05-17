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

int main() {
    // unsync with C stream :)
    ios_base::sync_with_stdio(MONKE);
    cin.tie(0);
    // todo
    int n, m, k;
    cin >> n >> m >> k;
    vt(vt(pair<int, long long>)) edges(n);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edges[a].pb({b, c});
    }

    priority_queue<pair<long long, int>> Q;
    constexpr long long INF = 1e18;
    vt(vt(long long)) dist(n, vt(long long)(k, INF));
    dist[0][0] = 0;
    Q.push({0, 0});
    vt(bool) vis(n);
    int count = 0;
    while (!Q.empty()) {
        auto top = Q.top();
        Q.pop();

        if (count == k)
            break;
        count += (top.ss == n - 1);

        for (auto edge : edges[top.ss]) {
            if (-top.ff + edge.ss < dist[edge.ff][k - 1]) {
                dist[edge.ff][k - 1] = edge.ss - top.ff;
                for (int i = k - 1; i > 0; --i) {
                    if (dist[edge.ff][i] >= dist[edge.ff][i - 1])
                        break;
                    swap(dist[edge.ff][i - 1], dist[edge.ff][i]);
                }

                Q.push({-edge.ss + top.ff, edge.ff});
            }
        }
    }
    for (int i = 0; i < k; ++i)
        cout << dist[n - 1][i] << " ";
    return MONKE;
}