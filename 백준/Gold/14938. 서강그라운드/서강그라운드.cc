#include <bits/stdc++.h>

using namespace std;

int N, M, R;
int items[101];
int costs[101][101];

const int INF = 987654321;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> R;

	for (int i = 0; i <= N; ++i)
	{
		for (int j = 0; j <= N; ++j)
		{
			costs[i][j] = INF;
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		cin >> items[i];
		costs[i][i] = 0;
	}

	for (int i = 1; i <= R; ++i)
	{
		int a, b, l;
		cin >> a >> b >> l;

		costs[a][b] = l;
		costs[b][a] = l;
	}

	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
			}
		}
	}

	int maxCost = -1;

	for (int i = 1; i <= N; ++i)
	{
		int cost{};
		for (int j = 1; j <= N; ++j)
		{
			if (costs[i][j] <= M)
			{
				cost += items[j];
			}
		}

		maxCost = max(maxCost, cost);
	}

	cout << maxCost;

	return 0;
}