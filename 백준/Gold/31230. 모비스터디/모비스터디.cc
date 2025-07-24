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

int N, M, A, B;
vector<pair<int,long long>> graph[200001];
long long visited[200001];
vector<int> pre[200001];
bool marked[200001];

const long long INF = LLONG_MAX;

class Node
{
public:
	int num;
	long long cost;
	queue<int> road;

	Node(int n, long long c, queue<int> r) : num(n), cost(c), road(r){}
};

struct cmp
{
	bool operator()(auto& A, auto& B)
	{
		return A.first > B.first;
	}
};

void dijkstra()
{
	fill_n(visited, N+1, INF);

	priority_queue<pair<long long, int>, vector<pair<long long, int>>, cmp> PQ;
	visited[A] = 0;
	PQ.push({0,A});


	while(!PQ.empty())
	{
		int cur = PQ.top().second;
		long long cost = PQ.top().first;
		PQ.pop();

		if(visited[cur] < cost) continue;

		for(int i = 0 ; i < graph[cur].size() ; ++i)
		{
			int next = graph[cur][i].first;
			long long nCost = cost + graph[cur][i].second;

			if(visited[next] > nCost)
			{
				visited[next] = nCost;
				pre[next].clear();
				pre[next].push_back(cur);
				PQ.push({nCost,next});
			}
			else if(visited[next] == nCost)
			{
				pre[next].push_back(cur);
			}
		}
	}
}

void dfs(int cur)
{
	if(marked[cur]) return;

	marked[cur] = true;

	for(int p : pre[cur])
		dfs(p);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> A >> B;

	for(int i = 0 ; i < M ; ++i)
	{
		int a, b;
		long long w;
		cin >>a >> b >> w;

		graph[a].push_back({b,w});
		graph[b].push_back({a,w});
	}

	dijkstra();
	dfs(B);

	
	vector<int> route;
	for(int i = 1; i <= N ; ++i)
		if(marked[i])
			route.push_back(i);

	sort(route.begin(), route.end());

	cout << route.size() << "\n";
	for(int n : route)
		cout << n << " ";

	return 0;
}