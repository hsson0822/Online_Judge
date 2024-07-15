#include <iostream>

using namespace std;

int N;
int calendar[366];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int start = 987654321;
	int end = 0;
	
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int a;
		int b;
		cin >> a >> b;

		if (a < start)
			start = a;
		if (b > end)
			end = b;

		for(int j = a ; j <= b; ++j)
			calendar[j]++;
	}

	int answer{};
	int bigger{};
	int cnt{};
	for (int i = start; i <= end; ++i)
	{
		if (calendar[i] == 0)
		{
			answer += bigger * cnt;

			bigger = 1;
			cnt = 0;
			continue;
		}

		if (calendar[i] > bigger)
			bigger = calendar[i];
		++cnt;

		if (i == end)
		{
			answer += bigger * cnt;
		}
	}

	cout << answer;

	return 0;
}