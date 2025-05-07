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

vector<int> graph[201];
queue<int> travel;

bool dfs(int start, int to)
{
	bool visited[201]{ false };
	queue<int> Q;
	visited[start] = true;
	Q.push(start);

	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();

		if (now == to)
			return true;

		for (int i = 0; i < graph[now].size(); ++i)
		{
			int next = graph[now][i];

			if (start == next) continue;
			if (visited[next]) continue;

			visited[next] = true;
			Q.push(next);
		}
	}
	
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			int n;
			cin >> n;
			
			if (n == 1)
				graph[i].push_back(j);
		}
	}

	for (int i = 0; i < M; ++i)
	{
		int n;
		cin >> n;
		travel.push(n);
	}

	
	while (!travel.empty())
	{
		int start = travel.front();
		travel.pop();

		if (travel.empty())
			break;

		if (!dfs(start, travel.front()))
		{
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";

	return 0;
}
