#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N;
int M;
int X;
vector<pair<int, int>>  village[2][1001];
int dist[2][1001];
int ans[1001];
const int INF = INT_MAX;

void dijkstra(int a)
{
	priority_queue<pair<int, int>> PQ;
	PQ.push(pair(0, X));
	dist[a][X] = 0;
	
	while (!PQ.empty())
	{
		int cost = PQ.top().first;
		int cur = PQ.top().second;
		PQ.pop();

		if (cost > dist[a][cur]) continue;

		for (int i = 0; i < village[a][cur].size(); ++i)
		{
			int next = village[a][cur][i].first;
			int nCost = village[a][cur][i].second;

			if (dist[a][next] > cost + nCost)
			{
				dist[a][next] = cost + nCost;
				PQ.push(pair(dist[a][next], next));
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> X;

	for (int i = 0; i < M; ++i)
	{
		int a;
		int b;
		int w;
		cin >> a >> b >> w;
		village[0][a].push_back(pair(b, w));
		village[1][b].push_back(pair(a, w));
	}
	for (int i = 0; i <= N; ++i)
	{
		dist[0][i] = INF;
		dist[1][i] = INF;

	}

	dijkstra(1);

	dijkstra(0);

	int res = 0;
	for (int i = 1; i <= N; ++i)
	{
		res = max(res, dist[0][i] + dist[1][i]);
	}
	cout << res;

	return 0;
}