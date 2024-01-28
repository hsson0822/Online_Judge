#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[100001];
bool visited[100001];
vector<int> parent;

void dfs(int start)
{
	visited[start] = true;

	for (int i = 0; i < graph[start].size(); ++i)
	{
		int x = graph[start][i];

		if (!visited[x])
		{
			parent[x] = start;
			dfs(x);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nodeCount;
	cin >> nodeCount;

	parent.push_back(0);
	parent.push_back(0);

	for (int i = 0; i < nodeCount - 1; ++i)
	{
		int a;
		int b;

		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
		parent.push_back(0);
	}

	visited[1] = true;
	dfs(1);

	for (int i = 2; i < parent.size(); ++i)
		cout << parent[i] << "\n";
	
	return 0;
}