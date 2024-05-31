#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int N;
int M;
vector<pair<int, int>> farm[50001];
int dist[50001];
const int INF = 987654321;

void dijkstra()
{
	priority_queue<pair<int, int>> PQ;
	PQ.push(pair(0, 1));
	dist[1] = 0;

	while (!PQ.empty())
	{
		int cost = -PQ.top().first;
		int cur = PQ.top().second;
		PQ.pop();

		if (cost > dist[cur]) continue;

		for (int i = 0; i < farm[cur].size(); ++i)
		{
			int next = farm[cur][i].first;
			int nCost = farm[cur][i].second;

			if (dist[next] > cost + nCost)
			{
				dist[next] = cost + nCost;
				PQ.push(pair(-dist[next], next));
			}
		}
	}

	cout << dist[N];
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

		farm[a].push_back(pair(b,w));
		farm[b].push_back(pair(a,w));
	}

	for (int i = 1; i <= N; ++i)
		dist[i] = INF;

	dijkstra();

	return 0;
}