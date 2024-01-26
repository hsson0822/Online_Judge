#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> tree[1001];
bool route[1001];

void reset()
{
	memset(route, false, 1001 * sizeof(bool));
}

void dfs(int n)
{
	route[n] = true;
	cout << n << " ";

	for (int i = 0; i < tree[n].size(); ++i)
	{
		int x = tree[n][i];
		if (!route[x])
			dfs(x);
	}
}

void bfs(int start)
{
	queue<int> que;
	que.push(start);
	route[start] = true;
	
	while (!que.empty())
	{
		int x = que.front();
		que.pop();
		cout << x << " ";

		for (int i = 0; i < tree[x].size(); ++i)
		{
			int y = tree[x][i];

			if (!route[y])
			{
				que.push(y);
				route[y] = true;
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int node;
	cin >> node;

	int count;
	cin >> count;
	
	int start;
	cin >> start;



	for (int i = 0; i < count; ++i)
	{
		int a;
		int b;
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);

		sort(tree[a].begin(), tree[a].end());
		sort(tree[b].begin(), tree[b].end());
	}

	dfs(start);
	cout << endl;
	reset();

	bfs(start);

	return 0;
}