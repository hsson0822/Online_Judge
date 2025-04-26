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

vector<pair<int, int>> graph[201];
int road[201][201];
const int INF = 987654321;

struct House
{
	int dest = 0;
	int weight=0;
	int first=0;
};

void dfs(int start)
{
	queue<House> Q;
	Q.push(House{ start, 0, 0 });
	int costs[201];
	fill_n(costs, N+1, INF);

	while (!Q.empty())
	{
		int cur = Q.front().dest;
		int cost = Q.front().weight;
		int first = Q.front().first;
		Q.pop();

		if(costs[cur] > cur)

		if (costs[cur] < cost) continue;

		for (int i = 0; i < graph[cur].size(); ++i)
		{
			int next = graph[cur][i].first;
			int nCost = graph[cur][i].second;

			if (costs[next] > cost + nCost)
			{
				costs[next] = cost + nCost;
				int s{};
				if (first == 0)
				{
					s = next;
					road[start][next] = s;
					Q.push(House{ next,costs[next],s });
				}
				else
				{
					road[start][next] = first;
					Q.push(House{ next,costs[next],first });

				}
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int a;
		int b;
		int w;
		cin >> a >> b >> w;
		graph[a].push_back({ b,w });
		graph[b].push_back({ a,w });
	}

	for (int i = 1; i <= N; ++i)
	{
		dfs(i);
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (i == j)
				cout << "- ";
			else
				cout << road[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
