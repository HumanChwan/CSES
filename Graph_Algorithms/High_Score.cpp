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
#define vpll vector<pair<ll, ll> >
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
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, ll> > edges;

    while (m--) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        edges.pb(mp(mp(a, b), w));
    }
    constexpr ll NEGINF = -(1e16 + 5);
    constexpr ll INF = 1e16 + 5;
    vector<ll> score(n + 1, NEGINF);
    score[1] = 0;

    for (int i = 0; i < n; ++i) {
        for (auto edge : edges) {
            if (score[edge.ff.ff] == NEGINF) continue;
            score[edge.ff.ss] =
                max(score[edge.ff.ss], score[edge.ff.ff] + edge.ss);
        }
    }
    // bool neg_cycle = false;
    for (int i = 0; i < n; ++i) {
        for (auto edge : edges) {
            if (score[edge.ff.ff] == NEGINF) continue;
            if (score[edge.ff.ss] < score[edge.ff.ff] + edge.ss) {
                score[edge.ff.ss] = INF;
            }
        }
    }

    cout << (score[n] == INF ? -1 : score[n]);

    return MONKE;
}