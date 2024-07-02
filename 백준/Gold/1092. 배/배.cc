#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int crane[50];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> crane[i];

	sort(crane, crane + N);

	int M;
	cin >> M;

	multiset<int> goods;
	for (int i = 0; i < M; ++i)
	{
		int k;
		cin >> k;
		goods.emplace(k);
	}

	if (*goods.rbegin() > crane[N - 1])
	{
		cout << -1;
		return 0;
	}

	int time{};
	
	while (!goods.empty())
	{
		for (int i = N-1; i >= 0; --i)
		{
			auto iter = goods.lower_bound(crane[i]);

			if (iter != goods.end() && *iter == crane[i])
			{
				goods.erase(iter);
			}
			else if (goods.empty())
				continue;
			else
			{
				if (iter == goods.begin())
					continue;
				iter--;
				goods.erase(iter);
			}
		}

		++time;
	}

	cout << time;

	return 0;
}