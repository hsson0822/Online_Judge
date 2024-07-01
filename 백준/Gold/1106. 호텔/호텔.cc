#include <iostream>
#include <map>
#include <climits>

using namespace std;

const int INF = 987654321;

int dp[10001];
map<int,int> cost;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int C;
	int N;

	cin >> C >> N;

	int miniest = 1000;
	for (int i = 0; i < N; ++i)
	{
		int money;
		int people;
		cin >> money >> people;
		if (cost[people] != 0)
			cost[people] = min(money, cost[people]);
		else
			cost[people] = money;

		if (people < miniest)
			miniest = people;
	}

	for (int i = 0; i <= 1000; ++i)
		dp[i] = INF;

	dp[miniest] = cost[miniest];
	
	for (int i = miniest + 1; i <= 1000; ++i)
	{
		for (auto m : cost)
		{
			int n = i / m.first;
			if (i % m.first > 0)
				++n;

			dp[i] = min(dp[i], min(n * m.second, dp[i - m.first] + dp[m.first]));
		}
	}

	int min_value = INT_MAX;
	for (int i = C; i <= 1000; i++) {
		if (min_value > dp[i]) {
			min_value = dp[i];
		}
	}
	cout << min_value << '\n';

	return 0;
}