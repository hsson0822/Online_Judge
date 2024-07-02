#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int M;
const int INF = 987654321;
vector<pair<int,pair<int,int>>> route;
long long dist[501];


bool bellman(int start)
{
	dist[start] = 0;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int from = route[j].first;
			int to = route[j].second.first;
			int cost = route[j].second.second;

			if (dist[from] == INF) continue;

			if (dist[to] > dist[from] + cost)
			{
				dist[to] = dist[from] + cost;

				if (i == N) return true;
			}
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int a;
		int b;
		int w;
		cin >> a >> b >> w;
		route.push_back(pair(a,pair(b, w)));
	}

	for (int i = 1; i <= N; ++i)
		dist[i] = INF;

	fill_n(dist, 501, INF);

	bool negativeCycle = bellman(1);

	if (negativeCycle) {
		cout << "-1\n";
		return 0;
	}

	for (int i = 2; i <= N; ++i)
	{
		if (dist[i] == INF)
			cout << "-1\n";
		else
			cout << dist[i] << "\n";
	}

	return 0;
}