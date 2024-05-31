#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int M;
int start;
int goal;

vector<pair<int, int>> cities[1001];
int dist[100001];
const int INF = 987654321;

void dijkstra()
{
	priority_queue<pair<int,int>> PQ;
	dist[start] = 0;
	PQ.push(pair(0, start));

	while (!PQ.empty())
	{
		int cost = -PQ.top().first;
		int cur = PQ.top().second;
		PQ.pop();

        if (cost > dist[cur]) continue;
        
		for (int i = 0; i < cities[cur].size(); ++i)
		{
			int next = cities[cur][i].first;
			int nCost = cities[cur][i].second;

			if (dist[next] > cost + nCost)
			{
				dist[next] = cost + nCost;
				PQ.push(pair(-dist[next], next));
			}
		}
	}

	cout << dist[goal];

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

		cities[a].push_back(pair(b, w));
	}
	cin >> start >> goal;

	for (int i = 0; i <= N; ++i)
	{
		dist[i] = INF;
	}

	dijkstra();

	return 0;
}