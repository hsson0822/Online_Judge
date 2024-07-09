#include <iostream>
#include <algorithm>

using namespace std;

int goods[5000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int C;
	cin >> N >> C;

	for (int i = 0; i < N; ++i)
	{
		cin >> goods[i];
	}

	sort(goods, goods + N);

	int start = 0;
	int end = N-1;
	int ans{};

	while (start < end)
	{
		if (ans) break;

		for (int i = 1; i < N; ++i)
		{
			if (i == start || i == end)
				continue;

			if (goods[start] == C || goods[end] == C || goods[i] == C) ans = 1;
			else if (goods[start] + goods[end] == C) ans = 1;
			else if (goods[start] + goods[end] + goods[i] == C) ans = 1;
		}

		if (goods[start] + goods[end] < C) ++start;
		else if (goods[start] + goods[end] > C) --end;
	}

	cout << ans << endl;

	return 0;
}