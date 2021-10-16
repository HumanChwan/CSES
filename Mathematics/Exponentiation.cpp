#include <bits/stdc++.h>

#define MONKE 0
#define M 1000000007
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef long double ld;

using namespace std;

long long power(long long a, long long b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % M;
        a = (a * a) % M;
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
        int a, b;
        cin >> a >> b;
        cout << power(a, b) << endl;
    }
    return MONKE;
}