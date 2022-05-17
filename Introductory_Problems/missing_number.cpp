#include <iostream>

int main ()
{
	long long n;
	std::cin >> n;
	long long answer = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		int x;
		std::cin >> x;
		answer += x;
	}

	std::cout << (n * (n + 1)) / 2 - answer;
	return 0;
}
