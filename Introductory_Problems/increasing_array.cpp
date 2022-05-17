#include <iostream>

constexpr int MONKE = 0;

int main()
{
	int n;
	std::cin >> n;
	long long prev = 0;
	long long moves = 0;
	for (int i = 0; i < n; ++i)
	{
		long long x;
		std::cin >> x;
		if (x < prev)
		{
			moves += (prev - x);
			x = prev;
		}
		prev = x;
	}
	std::cout << moves;
	return MONKE;
}
