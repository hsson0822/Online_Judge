#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int K;
int root[101][101];
vector<int> graph[101];
queue<pair<int, int>> que;

void bfs()
{
	while (que.size() != 0)
	{
		auto q = que.front();
		que.pop();

		for (int i = 0; i < graph[q.second].size(); ++i)
		{
			if (root[q.first][graph[q.second][i]] == 1 && q.first == q.second) continue;
            if (root[q.first][graph[q.second][i]] == 1) continue;
            
			que.push(pair(q.first, graph[q.second][i]));
			root[q.first][graph[q.second][i]] = 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K;

	for (int i = 1; i <= K; ++i)
	{
		for (int j = 1; j <= K; ++j)
		{
			int n;
			cin >> n;

			if (n == 1)
				graph[i].push_back(j);
		}
	}

	for (int i = 1; i <= K; ++i)
	{
		que.push(pair(i, i));
		bfs();
	}

	for (int i = 1; i <= K; ++i)
	{
		for (int j = 1; j <= K; ++j)
		{
			cout << root[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}