#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const long long INF = 987654321;

int N;
int M;

long long costs[101][101];
vector<pair<int,long long>> route[101];

void dijkstra(int start)
{
	priority_queue<pair<int, long long>> PQ;
	PQ.push(pair(start, 0));
	costs[start][start] = 0;

	while (!PQ.empty())
	{
		int cur = PQ.top().first;
		long long cost = PQ.top().second;
		PQ.pop();

		for (int i = 0; i < route[cur].size(); ++i)
		{
			int next = route[cur][i].first;
			long long nCost = route[cur][i].second;

			if (costs[start][next] > cost + nCost)
			{
				costs[start][next] = cost + nCost;
				PQ.push(pair(next, costs[start][next]));
			}
		}
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		int a;
		int b;
		long long w;
		cin >> a >> b >> w;
		route[a].push_back(pair(b, w));
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			costs[i][j] = INF;
		}
	}

	for (int i = 1; i <= N; ++i)
		dijkstra(i);

	for (int i = 1; i <= N; ++i)
    {
	    for (int j = 1; j <= N; ++j)
	    {
		    if (costs[i][j] == INF)
			    cout << "0 ";
		    else
			    cout << costs[i][j] << " ";
    	}
	    cout << endl;
    }

	return 0;
}