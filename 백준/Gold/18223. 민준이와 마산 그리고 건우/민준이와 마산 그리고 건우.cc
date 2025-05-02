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
int P;

vector <pair< int,int>> road[5001];
int costs[5001];
const int INF = INT_MAX;

struct Pos
{
	int x;
	int cost;
	bool visit;
};

pair<int, bool> check = { INF, false };

void dijkstra()
{
	queue<Pos> PQ;
	costs[1] = 0;

	if(P == 1)
		PQ.push(Pos{ 1,0,true });
	else
		PQ.push(Pos{ 1,0,false });

	while (!PQ.empty())
	{
		int cur = PQ.front().x;
		int cost = PQ.front().cost;
		bool visited = PQ.front().visit;
		PQ.pop();

		if (cur == V)
		{
		
			if (check.first > cost)
			{
				check.first = cost;
				check.second = visited;
			}
			else if (check.first == cost)
			{
				if (check.second || visited)
					check.second = true;
			}
		}

		if (cur == P)
			visited = true;
		
		for (int i = 0; i < road[cur].size(); ++i)
		{
			int next = road[cur][i].first;
			int nCost = road[cur][i].second;

			if (costs[next] >= cost + nCost)
			{
				costs[next] = cost + nCost;

				PQ.push(Pos{ next,costs[next],visited});
			}
			

		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E >> P;

	for (int i = 0; i < E; ++i)
	{
		int a;
		int b;
		int w;
		cin >> a >> b >> w;
		road[a].push_back({ b,w });
		road[b].push_back({ a,w });
	}

	fill_n(costs, V + 1, INF);

	dijkstra();

	/*for (int i = 1; i <= V; ++i)
		cout << costs[i] << " ";*/

	if (check.second)
		cout << "SAVE HIM";
	else
		cout << "GOOD BYE";

	return 0;
}
