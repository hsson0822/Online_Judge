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

int N;
int M;
int s;
int e;

class Edge
{
public:
	int a;
	int b;
	int w;

	Edge(int a, int b, int w) : a(a), b(b), w(w) {}

	bool operator<(Edge& E)
	{
		return w < E.w;
	}

};

vector<Edge> graph;
vector<pair<int, int>> newGraph[100001];
int parent[100001];

int getParent(int a)
{
	if (a == parent[a]) return a;

	return parent[a] = getParent(parent[a]);
}

bool isUnion(int a, int b)
{
	int pa = getParent(a);
	int pb = getParent(b);

	if (pa == pb) return false;

	parent[pb] =pa;
	return true;
}

bool visited[100001];
int answer;

void bfs()
{
	queue<pair<int, int>> Q;
	Q.push({ s,INT_MAX });
	visited[s] = true;

	while (!Q.empty())
	{
		int cur = Q.front().first;
		int cost = Q.front().second;
		Q.pop();

		if (cur == e)
		{
			answer = max(answer, cost);
		}

		for (int i = 0; i < newGraph[cur].size(); ++i)
		{
			int next = newGraph[cur][i].first;
			int nCost = newGraph[cur][i].second;

			if (visited[next]) continue;

			if (cost > nCost)
				Q.push({ next,nCost });
			else
				Q.push({ next,cost });

			visited[next] = true;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> s >> e;

	for (int i = 0; i < M; ++i)
	{
		int a, b, w;
		cin >> a >> b >> w;
		graph.push_back({ a,b,w });
	}

	for (int i = 1; i <= N; ++i)
		parent[i] = i;

	sort(graph.rbegin(), graph.rend());

	
	for (int i = 0; i < graph.size(); ++i)
	{
		if (isUnion(graph[i].a, graph[i].b))
		{
			newGraph[graph[i].a].push_back({ graph[i].b, graph[i].w });
			newGraph[graph[i].b].push_back({ graph[i].a, graph[i].w });
		}
	}
	
	bfs();

	cout << answer;

	return 0;
}
