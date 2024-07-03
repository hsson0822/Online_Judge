#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int M;
vector<pair<int,int>> route[1001];

int dist[1001];
vector<int> path[1001];

const int INF = 987654321;

int start;
int goal;

void dijkstra(int start)
{
	priority_queue<pair<int, int>> PQ;
	PQ.push(pair(start, 0));
	dist[start] = 0;
	path[start].push_back(start);

	while (!PQ.empty())
	{
		int cur = PQ.top().first;
		int cost = PQ.top().second;
		PQ.pop();

        if (dist[cur] < cost) continue;
        
		for (int i = 0; i < route[cur].size(); ++i)
		{
			int next = route[cur][i].first;
			int nCost = route[cur][i].second;

			if (dist[next] > cost + nCost)
			{
				dist[next] = cost + nCost;
				PQ.push(pair(next, dist[next]));

				path[next] = path[cur];
				path[next].push_back(next);
			}
		}
		
	}
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

		route[a].push_back(pair(b, w));
	}

	for (int i = 1; i <= N; ++i)
		dist[i] = INF;

	cin >> start >> goal;

	dijkstra(start);

	cout << dist[goal] << "\n";
	cout << path[goal].size() << "\n";
	for (int i = 0; i < path[goal].size(); ++i)
		cout << path[goal][i] << " ";
	return 0;
}