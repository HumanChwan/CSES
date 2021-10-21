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

constexpr ll INF = 1e16 + 5;

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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll> > > edges(n + 1), rev_edges(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        ll w;
        cin >> a >> b >> w;

        edges[a].pb({b, w});
        rev_edges[b].pb({a, w});
    }

    priority_queue<pair<ll, int> > Q;
    vector<bool> visited(n + 1);
    Q.push({0, 1});
    vector<ll> dist_nor(n + 1, INF), dist_rev(n + 1, INF);
    dist_nor[1] = 0;

    while (!Q.empty()) {
        auto top = Q.top();
        Q.pop();

        if (visited[top.ss]) {
            continue;
        }

        visited[top.ss] = true;
        for (auto edge : edges[top.ss]) {
            if (dist_nor[edge.ff] > dist_nor[top.ss] + edge.ss) {
                dist_nor[edge.ff] = dist_nor[top.ss] + edge.ss;
                Q.push({-dist_nor[edge.ff], edge.ff});
            }
        }
    }

    Q.push({0, n});
    for (int i = 1; i <= n; ++i) visited[i] = false;
    dist_rev[n] = 0;
    while (!Q.empty()) {
        auto top = Q.top();
        Q.pop();

        if (visited[top.ss]) {
            continue;
        }

        visited[top.ss] = true;
        for (auto edge : rev_edges[top.ss]) {
            if (dist_rev[edge.ff] > dist_rev[top.ss] + edge.ss) {
                dist_rev[edge.ff] = dist_rev[top.ss] + edge.ss;
                Q.push({-dist_rev[edge.ff], edge.ff});
            }
        }
    }

    ll lowest_cost = INF;

    for (int i = 1; i <= n; ++i) {
        for (auto edge : edges[i]) {
            lowest_cost =
                min(lowest_cost, edge.ss / 2 + dist_nor[i] + dist_rev[edge.ff]);
        }
    }

    cout << lowest_cost;
    return MONKE;
}