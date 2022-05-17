#include <iostream>

constexpr int MONKE = 0;

int main()
{
	int n;
	std::cin >> n;
	if (1 < n && n < 4)
	{
		std::cout << "NO SOLUTION";
		return MONKE;
	}

	for (int i = 2; i <= n; i += 2) std::cout << i << " ";
	for (int i = 1; i <= n; i += 2) std::cout << i << " ";
	return MONKE;
}
