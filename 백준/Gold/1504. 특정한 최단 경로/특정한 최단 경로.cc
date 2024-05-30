#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int N;
int E;
vector<pair<int,int>> graph[801];
const int INF = 987654321;
int dist[801];
int routeA;
int routeB;

void dijkstra(int start)
{
	priority_queue<pair<int, int>> PQ;
	PQ.push(pair(0, start));

	for (int i = 1; i <= N; ++i)
		dist[i] = INF;
	dist[start] = 0;
    
	while (!PQ.empty())
	{
		int cost = PQ.top().first;
		int cur = PQ.top().second;
		PQ.pop();

		for (int i = 0; i < graph[cur].size(); ++i)
		{
			int next = graph[cur][i].first;
			int nCost = graph[cur][i].second;

			if (dist[next] > cost + nCost)
			{
				dist[next] = cost + nCost;
				PQ.push(pair(dist[next], next));
			}
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> E;

	for (int i = 0; i < E; ++i)
	{
		int a;
		int b;
		int c;

		cin >> a >> b >> c;

		graph[a].push_back(pair(b,c));
		graph[b].push_back(pair(a,c));
	}

	cin >> routeA >> routeB;

	dijkstra(1);
	int ToA = dist[routeA];
	int ToB = dist[routeB];

	dijkstra(routeA);
	int AToB = dist[routeB];
	int AToN = dist[N];

	dijkstra(routeB);
	int BToN = dist[N];

	int answer = min(INF, ToA + AToB + BToN);
	answer = min(answer, ToB + AToB + AToN);

	if (answer >= INF || answer < 0)
	    cout << -1;
    else
	    cout << answer;

	return 0;
}