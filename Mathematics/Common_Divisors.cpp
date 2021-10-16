#include <bits/stdc++.h>

#define MONKE 0
#define M 1000000007
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef long double ld;

using namespace std;

int main() {
    ios_base::sync_with_stdio(MONKE);  // unsync uWu
    cin.tie(MONKE);                    // cin-cout unsync uWu
    int n;
    cin >> n;
    // vector<int> numbers(n);

    const int maxN = 1e6 + 4;
    static int onNumberLine[maxN]{0};
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        onNumberLine[x]++;
    }

    for (int i = maxN - 1; i; --i) {
        int countsWithI = 0;
        for (int j = i; j < maxN; j += i) {
            countsWithI += onNumberLine[j];
        }
        if (countsWithI >= 2) {
            cout << i;
            return MONKE;
        }
    }
    cout << 1;
    return MONKE;
}