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

struct Node {
    int value;
    int size;
};

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
    SegmentTree(int n, T operative_identity) {
        size = 1;
        while (size < n) size <<= 1;
        tree = vector<T>(2 * size - 1, operative_identity);

        OPERATIVE_IDENTITY = operative_identity;
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
        tree[i] = new_data;

        for (int p = i - 1; p >= 0; --p) {
            p /= 2;
            tree[p] = operation(tree[2 * p + 1], tree[2 * p + 2]);
        }
    }

    int get_and_delete(int ind, int root = 0, int l_ind = 0);

    T evaluate_range(int l, int r) { return segment_recurs(l, r, 0, 0, size); }
};

template <>
Node SegmentTree<Node>::operation(Node a, Node b) {
    return {-1, a.size + b.size};
}

template <>
int SegmentTree<Node>::get_and_delete(int ind, int root, int l_ind) {
    tree[root].size--;
    if (root >= size - 1) {
        return tree[root].value;
    }

    if (tree[2 * root + 1].size > 0 && tree[2 * root + 1].size + l_ind > ind)
        return get_and_delete(ind, 2 * root + 1, l_ind);

    return get_and_delete(ind, 2 * root + 2, l_ind + tree[2 * root + 1].size);
}

int main() {
    // unsync with C stream :)
    ios_base::sync_with_stdio(MONKE);
    cin.tie(MONKE);
    // todo
    int n;
    cin >> n;
    vt(Node) a(n);
    for (auto &x : a) {
        cin >> x.value;
        x.size = 1;
    }
    SegmentTree<Node> tree(n, {-1, 0});
    tree.build(a);

    while (n--) {
        int ind;
        cin >> ind;
        --ind;
        cout << tree.get_and_delete(ind) << " ";
    }

    return MONKE;
}