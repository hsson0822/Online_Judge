#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[1001];
bool visited[1001];
int cnt{};

vector<int> group;

void bfs(int start)
{
	queue<int> que;
	que.push(start);

	while (!que.empty())
	{
		int x = que.front();
		que.pop();

		for (int i = 0; i < graph[x].size(); ++i)
		{
			int y = graph[x][i];

			if (!visited[y])
			{
				que.push(y);
				visited[y] = true;
				++cnt;
			}
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

	int lineCount;
	cin >> lineCount;

	for (int i = 0; i < lineCount; ++i)
	{
		int a;
		int b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);

		visited[a] = false;
		visited[b] = false;
	}

	for (int i = 1; i <= nodeCount; ++i)
	{
		if (visited[i] == false)
		{
			cnt = 1;
			visited[i] = true;
			bfs(i);
			group.push_back(cnt);
		}

	}

	cout << group.size();

	
	return 0;
}