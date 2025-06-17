#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <sstream>
#include <climits>
#include <math.h>
#include <cstring>

using namespace std;

int N;
int M;
int W;
const int INF = INT_MAX;
vector<pair<int, pair<int, int>>> route;
long long dist[501];

bool bellman()
{
	fill_n(dist, N + 1, 0);

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j < route.size(); ++j)
		{
			int from = route[j].first;
			int to = route[j].second.first;
			int cost = route[j].second.second;

			if (dist[from] == INF) continue;

			if (dist[to] > dist[from] + cost)
			{
				dist[to] = dist[from] + cost;
			}
		}
	}

	for (int j = 0; j < route.size(); ++j)
	{
		int from = route[j].first;
		int to = route[j].second.first;
		int cost = route[j].second.second;

		if (dist[from] == INF) continue;

		if (dist[to] > dist[from] + cost)
		{
			return true;
		}
	}

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int t = 0; t < T; ++t)
	{
		cin >> N >> M >> W;


		for (int i = 0; i < M; ++i)
		{
			int a, b, w;
			cin >> a >> b >> w;
			route.push_back({ a,{b,w} });
			route.push_back({ b,{a,w} });
		}

		for (int i = 0; i < W; ++i)
		{
			int a, b, w;
			cin >> a >> b >> w;
			route.push_back({ a,{b,-w} });
		}

		if (bellman())
			cout << "YES\n";
		else
			cout << "NO\n";

		route.clear();
	}

	return 0;
}
