#include <iostream>
#include <vector>
#include <algorithm>

#define all(x) x.begin(), x.end()

using namespace std;

constexpr int MONKE = 0;
constexpr int INF = 1e9 + 5;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);

	for (int &x : arr) cin >> x;

	vector<int> length_term(n + 1, INF);
	length_term[0] = 0;
	for (int x : arr) {
		int index = upper_bound(all(length_term), x) - length_term.begin();
		if (length_term[index - 1] < x && x < length_term[index])
			length_term[index] = x;
	}

	int len = 0;
	while (++len <= n && length_term[len] != INF);

	cout << len - 1;

	return MONKE;
}
