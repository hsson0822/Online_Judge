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
int X;
int Y;

int costs[1001];
const int INF = 987654321;
vector<pair<int,int>> graph[1001];

void dijkstra()
{
	priority_queue<pair<int, int>> Q;
	costs[Y] = 0;
	Q.push({ Y,0 });

	while (!Q.empty())
	{
		int cur = Q.top().first;
		int cost = Q.top().second;
		Q.pop();

		if (costs[cur] < cost) continue;

		for (int i = 0; i < graph[cur].size(); ++i)
		{
			int next = graph[cur][i].first;
			int nCost = graph[cur][i].second;

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

	cin >> N >> M >> X >> Y;

	for (int i = 0; i < M; ++i)
	{
		int a;
		int b;
		int w;
		cin >> a >> b >> w;

		graph[a].push_back({ b,w });
		graph[b].push_back({ a,w });
	}

	fill_n(costs, N, INF);
	dijkstra();

	priority_queue<int, vector<int>, greater<int>> PQ;
	for (int i = 0; i < N; ++i)
	{
		if (i == Y) continue;

		costs[i] *= 2;
		PQ.push(costs[i]);

		if (costs[i] > X || costs[i] == INF)
		{
			cout << -1;
			return 0;
		}
	}

	int answer=1;
	int sum{};
	while (!PQ.empty())
	{
		int cost = PQ.top();
		PQ.pop();

		if (sum + cost <= X)
		{
			sum += cost;
		}
		else
		{
			++answer;
			sum = cost;
		}
	}

	cout << answer;


	return 0;
}
