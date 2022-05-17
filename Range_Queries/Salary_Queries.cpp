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

#define get_lower(x) lower_bound(index.begin(), index.end(), x) - index.begin()
#define get_upper(x) upper_bound(index.begin(), index.end(), x) - index.begin()

constexpr int M = 1000000007;
constexpr int MONKE = 0;

using namespace std;

bool sort_by_second(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.ss > b.ss);
}

ll power(ll num, ll exp, ll MOD = M) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res = (res * num) % MOD;
        num = (num * num) % MOD;
        exp >>= 1;
    }
    return res;
}

template <typename T>
class SegmentTree {
   private:
    int size;
    vector<T> tree;
    T operation(T a, T b);
    T OPERATIVE_IDENTITY;

    T segment_recurs(int l, int r, int x, int lx, int rx) {
        if (rx <= l || r <= lx) return OPERATIVE_IDENTITY;
        if (l <= lx && rx <= r) return tree[x];

        int m = (lx + rx) / 2;
        T g1 = segment_recurs(l, r, 2 * x + 1, lx, m);
        T g2 = segment_recurs(l, r, 2 * x + 2, m, rx);

        return operation(g1, g2);
    }

   public:
    SegmentTree(int n, T operative_identity)
        : OPERATIVE_IDENTITY(operative_identity) {
        size = 1;
        while (size < n) size <<= 1;
        tree = vector<T>(2 * size - 1, operative_identity);
    }

    void build(vector<T> &init) {
        for (int i = size - 1; i < size - 1 + (int)init.size(); ++i)
            tree[i] = init[i - size + 1];

        for (int i = size - 2; i >= 0; --i) {
            tree[i] = operation(tree[2 * i + 1], tree[2 * i + 2]);
        }
    }

    void set(int i, T new_data) {
        i += size - 1;
        tree[i] += new_data;

        for (int p = i - 1; p >= 0; --p) {
            p /= 2;
            tree[p] = operation(tree[2 * p + 1], tree[2 * p + 2]);
        }
    }

    T evaluate_range(int l, int r) { return segment_recurs(l, r, 0, 0, size); }
};

template <>
int SegmentTree<int>::operation(int a, int b) {
    return a + b;
}

int main() {
    // unsync with C stream :)
    ios_base::sync_with_stdio(MONKE);
    cin.tie(0);
    // todo
    int n, q;
    cin >> n >> q;
    vt(int) a(n);

    map<int, int> coord;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        coord[a[i]]++;
    }

    vt(pair<char, pii>) queries;
    for (int i = 0; i < q; ++i) {
        char opt;
        int x, y;
        cin >> opt >> x >> y;
        if (opt == '!') {
            x--;
            coord[y];
        }
        queries.pb({opt, {x, y}});
    }

    SegmentTree<int> tree(sz(coord), 0);
    vt(int) build_arr;
    vt(int) index;
    int idx = 0;
    for (auto p : coord) {
        build_arr.pb(p.ss);
        index.pb(p.ff);
    }
    tree.build(build_arr);

    for (auto &query : queries) {
        if (query.ff == '!') {
            int prev_value = a[query.ss.ff];
            tree.set(get_lower(prev_value), -1);
            tree.set(get_lower(query.ss.ss), 1);
            a[query.ss.ff] = query.ss.ss;
        } else {
            cout << tree.evaluate_range(get_lower(query.ss.ff),
                                        get_upper(query.ss.ss))
                 << "\n";
        }
    }
    return MONKE;
}