#include <iostream>
#include <vector>

constexpr int MONKE = 0;
constexpr int M = 1e9 + 7;

int main()
{
	int n;
	std::cin >> n;
	std::vector<long long>	meth(n + 1, 1);
	for (int i = n - 1; i >= 0; --i)
	{
		meth[i] = (meth[i + 1] * (i + 1)) % M;
	}
	long long answer = 0;
	for (int i = 0; i <= n; ++i)
		answer = (answer + (i % 2 == 0 ? 1 : -1) * meth[i] + M) % M;
	std::cout << answer;
	return MONKE;
}
