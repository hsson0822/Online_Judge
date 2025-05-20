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

int V;
int E;
vector<pair<int, int>> graph[10001];
const int INF = INT_MAX;

int M, x;
queue<int> macQ;
int macCost[10001];

int S, y;
queue<int> starQ;
int starCost[10001];

int sum[10001];

struct cmp
{
	bool operator()(pair<int, int> A, pair<int, int> B)
	{
		return A.second > B.second;
	}
};

void mac()
{
	priority_queue < pair<int, int>, vector<pair<int,int>>, cmp> PQ;
	while (!macQ.empty())
	{
		PQ.push({ macQ.front(), 0 });
		macCost[macQ.front()] = 0;
		macQ.pop();
	}

	while (!PQ.empty())
	{
		int cur = PQ.top().first;
		int cost = PQ.top().second;
		
		PQ.pop();

		if (macCost[cur] < cost) continue;

		for (int i = 0; i < graph[cur].size(); ++i)
		{
			int next = graph[cur][i].first;
			int nCost = graph[cur][i].second;

			if (macCost[next] > cost + nCost)
			{
				macCost[next] = cost + nCost;
				PQ.push({ next,macCost[next] });
			}
		}
	}
}

void star()
{
	priority_queue < pair<int, int>, vector<pair<int, int>>, cmp> PQ;
	while (!starQ.empty())
	{
		PQ.push({ starQ.front(), 0 });
		starCost[starQ.front()] = 0;
		starQ.pop();
	}

	while (!PQ.empty())
	{
		int cur = PQ.top().first;
		int cost = PQ.top().second;
		PQ.pop();

		if (starCost[cur] < cost) continue;

		for (int i = 0; i < graph[cur].size(); ++i)
		{
			int next = graph[cur][i].first;
			int nCost = graph[cur][i].second;

			if (starCost[next] > cost + nCost)
			{
				starCost[next] = cost + nCost;
				PQ.push({ next,starCost[next] });
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E;

	for (int i = 0; i < E; ++i)
	{
		int a;
		int b;
		int w;
		cin >> a >> b >> w;

		graph[a].push_back({ b,w });
		graph[b].push_back({ a,w });
	}



	cin >> M >> x;

	for (int i = 0; i < M; ++i)
	{
		int n;
		cin >> n;
		macQ.push(n);
	}

	cin >> S >> y;
	for (int i = 0; i < S; ++i)
	{
		int n;
		cin >> n;
		starQ.push(n);
	}
	
	fill_n(macCost, V+ 1, INF);
	fill_n(starCost, V + 1, INF);

	mac();
	star();

	
	fill_n(sum, V + 1, INF);

	for (int i = 1; i <= V; ++i)
	{
		
		if (macCost[i] == 0) continue;
		if (macCost[i] <= x)
			sum[i] = macCost[i];
	}
	

	for (int i = 1; i <= V; ++i)
	{
	
		if (starCost[i] == 0)
		{
			sum[i] = INF;
			continue;
		}
		if (starCost[i] <= y && sum[i] != INF)
			sum[i] += starCost[i];
		else
			sum[i] = INF;
	}
	

	

	int answer = *min_element(&sum[1], &sum[V+1]);

	if (answer != INF)
		cout << answer;
	else
		cout << -1;

	return 0;
}
