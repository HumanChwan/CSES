#include <iostream>
#include <map>

int main () {
	std::map<int, int> mp;
	for (int i = 0; i < 100000; ++i) {
		int a;
		std::cin >> a;
		mp[a]++; 
	}

	for (auto x: mp) {
		std::cout << x.first << ": " << x.second << "\n";
	}
}