#include <iostream>

constexpr int MONKE = 0;

int main()
{
	int t;
	std::cin >> t;
	while (t--)
	{
		int y, x;
		std::cin >> y >> x;
		long long M = std::max(y, x);
		long long answer = (M - 1) * (M - 1);
		answer += M + (x - y) * (M % 2 == 0 ? -1 : 1);
		std::cout << answer << "\n";
	}
	return MONKE;
}
