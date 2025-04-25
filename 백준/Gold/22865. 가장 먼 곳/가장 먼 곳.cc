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
int A;
int B;
int C;
vector<pair<int, int>> road[100001];
int costs[100001];
map<int, priority_queue<int,vector<int>,greater<int> >> m;
const int INF = 987654321;

void dfs(int start)
{
	queue<pair<int, int>> Q;
	costs[start] = 0;
	Q.push({ start, 0 });

	while (!Q.empty())
	{
		int cur = Q.front().first;
		int cost = Q.front().second;
		Q.pop();

		for (int i = 0; i < road[cur].size(); ++i)
		{
			int next = road[cur][i].first;
			int nCost = road[cur][i].second;

			if (costs[next] > cost + nCost)
			{
				costs[next] = cost + nCost;
				Q.push({ next,costs[next] });
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> A >> B >> C >> M;

	for (int i = 0; i < M; ++i)
	{
		int a;
		int b;
		int w;
		cin >> a >> b >> w;
		road[a].push_back({ b,w });
		road[b].push_back({ a,w });
	}

	fill_n(costs, N+1, INF);
	dfs(A);
	for (int i = 1; i <= N; ++i)
	{
		if (i == A || i == B || i == C) continue;
		m[i].push(costs[i]);
	}

	fill_n(costs, N, INF);
	dfs(B);
	for (int i = 1; i <= N; ++i)
	{
		if (i == A || i == B || i == C) continue;
		m[i].push(costs[i]);
	}

	fill_n(costs, N, INF);
	dfs(C);
	for (int i = 1; i <= N; ++i)
	{
		if (i == A || i == B || i == C) continue;
		m[i].push(costs[i]);
	}

	
	int answer{};
	int leng{};
	for (auto& a : m)
	{

		if (leng < a.second.top())
		{
			answer = a.first;
			leng = a.second.top();
		}
		else if (leng == a.second.top())
		{
			answer = min(answer, a.first);
		}
		
	}

	cout << answer;

	return 0;
}
