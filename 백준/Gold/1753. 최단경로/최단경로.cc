#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V;
int E;
int start;
vector<pair<int, int>> graph[20001];
int dist[300001];
const int INF = 987654321;

void dijkstra()
{
	priority_queue<pair<int, int>> PQ;
	PQ.push(pair(0, start));
	dist[start] = 0;

	while (!PQ.empty())
	{
		int cost = -PQ.top().first;
		int Cur = PQ.top().second;
		PQ.pop();

		for (int i = 0; i < graph[Cur].size(); ++i)
		{
			int next = graph[Cur][i].first;
			int nCost = graph[Cur][i].second;

			if (dist[next] > cost + nCost)
			{
				dist[next] = cost + nCost;
				PQ.push(pair(-dist[next],next));
			}
		}
	}

	for (int i = 1; i <= V; ++i)
	{
		if (dist[i] == INF)
			cout << "INF" << "\n";
		else
			cout << dist[i] << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E >> start;

	for (int i = 1; i <= E; ++i)
	{
		int from;
		int to;
		int cost;
		cin >> from >> to >> cost;

		graph[from].push_back(pair(to, cost));
	}
	
	for (int i = 1; i <= V; ++i)
		dist[i] = INF;

	dijkstra();

	return 0;
}