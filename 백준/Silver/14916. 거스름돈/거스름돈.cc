#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int money;
	cin >> money;
    
    int k{};
	int five{};
	const int INF = 987654321;
	int answer = INF;

	while (5*five <= money)
	{
		int temp = money;
		temp -= 5 * five;

		if (temp % 2 == 0)
		{
			int two = temp / 2;
			answer = min(answer, five + two);
		}
		++five;
	}

	if (answer == INF)
		cout << -1;
	else
		cout << answer;

	return 0;
}