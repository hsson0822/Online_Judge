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
vector<int> graph[100001];
bool visited[100001];
int order[100001];
vector<int> bfs_order;

bool cmp(int& a, int& b)
{
	return order[a] < order[b];
}

void bfs()
{
	queue<int> Q;
	Q.push(1);
	visited[1] = true;
	bfs_order.push_back(1);

	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();

		for (int i = 0; i < graph[cur].size(); ++i)
		{
			int next = graph[cur][i];
			if (visited[next]) continue;

			visited[next] = true;
			Q.push(next);
			bfs_order.push_back(next);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N-1; ++i)
	{
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);

	}

	vector<int> temp(N+1);
	for (int i = 1; i <= N; ++i)
	{
		cin >> temp[i];
		order[temp[i]] = i;
	}
	
	for(int i = 1 ; i <= N ; ++i)
		sort(graph[i].begin(), graph[i].end(), cmp);
	
	bfs_order.push_back(0);
	if(temp[1] == 1) bfs();
	if(bfs_order == temp)
		cout << 1;
	else
		cout << 0;
	
	return 0;
}