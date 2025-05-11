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
int start;
int goal;
vector<pair<int, int>> graph[5001];
int costs[5001];
const int INF = INT_MAX;

void dijkstra()
{
	queue<pair<int, int>> Q;
	Q.push({ start,0 });
	costs[start] = 0;

	while (!Q.empty())
	{
		int now = Q.front().first;
		int cost = Q.front().second;
		Q.pop();
	
		if (costs[now] < cost) continue;

		for (int i = 0; i < graph[now].size(); ++i)
		{
			int next = graph[now][i].first;
			int nCost = graph[now][i].second;

			if (costs[next] > cost + nCost)
			{
				costs[next] = cost + nCost;
				Q.push({ next,costs[next] });
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int a;
		int b;
		int w;
		cin >> a >> b >> w;

		graph[a].push_back({ b,w });
		graph[b].push_back({ a,w });
	}

	cin >> start >> goal;

	fill_n(costs, N + 1, INF);

	dijkstra();

	cout << costs[goal];

	return 0;
}
