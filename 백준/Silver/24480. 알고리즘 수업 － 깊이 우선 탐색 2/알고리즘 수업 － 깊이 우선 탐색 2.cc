#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[100001];
int visited[100001];
int cnt;

void dfs(int start)
{
	visited[start] = cnt++;

	for (int i = 0; i < graph[start].size(); ++i)
	{
		int x = graph[start][i];

		if (visited[x] == 0)
		{
			dfs(x);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int node;
	int line;
	int start;
	cin >> node >> line >> start;

	for (int i = 0; i < line; ++i)
	{
		int a;
		int b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);

	}

	for (int i = 1; i <= node; ++i)
	{
		sort(graph[i].rbegin(), graph[i].rend());
	}

	cnt = 1;
	dfs(start);

	for (int i = 1; i <= node; ++i)
	{
		cout << visited[i] << "\n";
	}

	return 0;
}