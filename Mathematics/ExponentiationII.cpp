#include <bits/stdc++.h>

#define MONKE 0
#define M 1000000007
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef long double ld;

using namespace std;

long long power(long long a, long long b, long long MOD = M) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(MONKE);  // unsync uWu
    cin.tie(MONKE);                    // cin-cout unsync uWu
    int n;
    cin >> n;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << power(a, power(b, c, M - 1)) << endl;
    }
    return MONKE;
}