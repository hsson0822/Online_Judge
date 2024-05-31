#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N;
int M;
vector<pair<long long, long long>> rift[100001];
long long dist[100001];
long long look[100001];
const long long INF = LLONG_MAX;

void dijkstra()
{
	priority_queue<pair<long long, long long>> PQ;
	PQ.push(pair(0, 0));
	dist[0] = 0;

	while (!PQ.empty())
	{
		long long cost = -PQ.top().first;
		long long cur = PQ.top().second;
		PQ.pop();

		if (cost > dist[cur]) continue;

		for (int i = 0; i < rift[cur].size(); ++i)
		{
			long long next = rift[cur][i].first;
			long long nCost = rift[cur][i].second;

			if (next < N - 1 && look[next] == 1) continue;

			if (dist[next] > cost + nCost)
			{
				dist[next] = cost + nCost;
				PQ.push(pair(-dist[next], next));
			}
		}
	}

	if (dist[N - 1] == INF)
		cout << -1;
	else
		cout << dist[N - 1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (long long i = 0; i < N; ++i)
	{
		long long k;
		cin >> k;
		look[i] = k;
	}

	for (long long i = 0; i < M; ++i)
	{
		long long a;
		long long b;
		long long w;
		cin >> a >> b >> w;

		rift[a].push_back(pair(b, w));
		rift[b].push_back(pair(a, w));
	}

	for (long long i = 0; i < N; ++i)
	{
		dist[i] = INF;
	}

	dijkstra();

	return 0;
}