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

constexpr ll INF = 1e16 + 5;

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
vt(pair<pii, ll>) edges;
int n, m;
vt(ll) dist;
vt(bool) visited;
vt(int) parent;

bool bellman() {
    for (int i = 0; i < n; ++i) {
        for (auto edge : edges) {
            if (dist[edge.ff.ss] > dist[edge.ff.ff] + edge.ss) {
                dist[edge.ff.ss] = dist[edge.ff.ff] + edge.ss;
            }
        }
    }

    for (auto edge : edges) {
        if (dist[edge.ff.ss] > dist[edge.ff.ff] + edge.ss) {
            return false;
        }
    }

    return true;
}

int cycle_printer(int source) {
    if (parent[source] == -1) return -1;

    if (visited[source]) {
        return source;
    }

    visited[source] = true;
    int ans = cycle_printer(parent[source]);
    visited[source] = false;

    return ans;
}

int main() {
    // unsync with C stream :)
    ios_base::sync_with_stdio(MONKE);
    cin.tie(MONKE);
    // todo
    cin >> n >> m;
    edges = vt(pair<pii, ll>)(n + 1);

    while (m--) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edges.pb({{a, b}, c});
    }

    dist = vt(ll)(n + 1, INF);

    if (bellman()) {
        cout << "NO";
        return MONKE;
    }

    cout << "YES\n";
    visited = vt(bool)(n + 1, false);
    parent = vt(int)(n + 1, -1);

    for (int i = 1; i <= n; ++i) {
        for (auto edge : edges) {
            if (dist[edge.ff.ss] > dist[edge.ff.ff] + edge.ss) {
                dist[edge.ff.ss] = dist[edge.ff.ff] + edge.ss;
                if (parent[edge.ff.ss] == -1) parent[edge.ff.ss] = edge.ff.ff;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        int cycle_start = cycle_printer(i);
        if (cycle_start != -1) {
            stack<int> path;
            int st = cycle_start;
            do {
                path.push(st);
                st = parent[st];
            } while (st != cycle_start);
            path.push(st);
            while (!path.empty()) {
                cout << path.top() << " ";
                path.pop();
            }
            break;
        }
    }

    return MONKE;
}