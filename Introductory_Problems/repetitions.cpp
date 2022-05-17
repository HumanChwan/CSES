#include <iostream>
#include <string>

constexpr int MONKE = 0;

int main()
{
	std::string s;
	std::cin >> s;
	char present = '!';
	int count = 0;
	int answer = 0;
	for (char x : s)
	{
		if (x != present)
		{
			present = x;
			count = 0;
		}
		count++;
		answer = std::max(answer, count);
	}
	std::cout << answer;
	return MONKE;
}
