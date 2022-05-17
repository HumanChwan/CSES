#include <iostream>

constexpr int MONKE = 0;

int main()
{
	int n;
	std::cin >> n;
	for (long long i = 1; i <= n; ++i)
	{
		long long unsafe = std::max(0LL, (i - 1) * (i - 2)) * 4LL;
		std::cout << (i * i * (i * i - 1)) / 2 - unsafe << "\n"; 
	}
	return MONKE;
}
