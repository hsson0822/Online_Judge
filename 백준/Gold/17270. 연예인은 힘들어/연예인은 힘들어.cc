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

int V;
int M;
vector<pair<int, int>> graph[101];
const int INF = INT_MAX;

void dijkstra(int start, int costs[])
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
	PQ.push({ 0, start });
	costs[start] = 0;

	while (!PQ.empty())
	{
		int cost = PQ.top().first;
		int cur = PQ.top().second;
		PQ.pop();

		if (costs[cur] < cost) continue;

		for (int i = 0; i < graph[cur].size(); ++i)
		{
			int next = graph[cur][i].first;
			int nCost = graph[cur][i].second;

			if (costs[next] > cost + nCost)
			{
				costs[next] = cost + nCost;
				PQ.push({ costs[next],next});
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> M;

	for (int i = 0; i < M; ++i)
	{
		int a, b, w;
		cin >> a >> b >> w;

		graph[a].push_back({ b,w });
		graph[b].push_back({ a,w });
	}

	int j, s;
	cin >> j >> s;

	int jiCost[101];
	int sungCost[101];

	fill_n(jiCost, V + 1, INF);
	fill_n(sungCost, V + 1, INF);

	dijkstra(j, jiCost);
	dijkstra(s, sungCost);

	int JS_distance = INF;
	int cost = INF;
	int answer = -1;

	for (int i = 1; i <= V; i++) {
		if (i == j || i == s) continue;
		JS_distance = min(JS_distance, jiCost[i] + sungCost[i]); // 최소거리를 저장
	}

	for (int i = V; i >= 1; --i)
	{
		if (i == s || i == j) continue;
		if (JS_distance != jiCost[i] + sungCost[i]) continue;
		if (jiCost[i] > sungCost[i]) continue;

		if (cost >= jiCost[i])
		{
			cost = jiCost[i];
			answer = i;
		}
	}

	cout << answer;

	return 0;
}
