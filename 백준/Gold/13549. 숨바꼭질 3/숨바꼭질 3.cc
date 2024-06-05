#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int K;
int dist[100001];
const int INF = 987654321;

void dijkstra()
{
	queue<pair<int,int>> PQ;
	dist[N] = 0;
	PQ.push(pair(N, 0));

	while (!PQ.empty())
	{

		int cur = PQ.front().first;
		int cost = PQ.front().second;
		PQ.pop();

		if (cur == K)
			break;

		if (cost > dist[cur]) continue;

		int next = cur * 2;
		int nCost = cost;

		if (0 <= next && next < 100001)
		{
			if (dist[next] > nCost)
			{
				dist[next] = nCost;
				PQ.push(pair(next, dist[next]));
			}
		}

		next = cur - 1;
		nCost = cost + 1;

		if (0 <= next && next < 100001)
		{
			if (dist[next] > nCost)
			{
				dist[next] = nCost;
				PQ.push(pair(next, dist[next]));
			}
		}

		next = cur + 1;
		nCost = cost + 1;

		if (0 <= next && next < 100001)
		{
			if (dist[next] > nCost)
			{
				dist[next] = nCost;
				PQ.push(pair(next, dist[next]));
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < 100001; ++i)
		dist[i] = INF;

	dijkstra();

	cout << dist[K];
	return 0;
}