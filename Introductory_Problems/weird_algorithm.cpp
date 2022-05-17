#include <iostream>

constexpr int MONKE = 0;

void weird_algorithm(long long n)
{
	std::cout << n << " ";
	if (n == 1) return;
	weird_algorithm(n % 2 == 0 ? n / 2 : n * 3 + 1);
}

int main ()
{
	long long n;
	std::cin >> n;
	weird_algorithm(n);
	return MONKE;

}
