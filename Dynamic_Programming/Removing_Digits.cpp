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
    int count = 0;
    while (n) {
        int temp = n;
        int maxDigit = 0;
        for (; temp > 0; temp /= 10) maxDigit = max(maxDigit, temp % 10);
        count++;
        n -= maxDigit;
    }
    cout << count;
    return MONKE;
}