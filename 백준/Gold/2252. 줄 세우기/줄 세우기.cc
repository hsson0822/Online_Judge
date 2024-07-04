#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> inDegree;
vector<vector<int>> graph;
queue<int> Q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int M;
	cin >> N >> M;

	inDegree.assign(N + 1, 0);
	graph.assign(N + 1, vector<int>(0, 0));

	for (int i = 0; i < M ; ++i)
	{
		int a;
		int b;
		cin >> a >> b;
		graph[a].emplace_back(b);
		inDegree[b]++;
	}

	for (int i = 1; i <= N; ++i)
		if (inDegree[i] == 0)
			Q.push(i);

	while(!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		cout << cur << " ";

		for (int j = 0; j < graph[cur].size(); ++j)
		{
			int next = graph[cur][j];
			inDegree[next]--;
			if (inDegree[next] == 0) Q.push(next);
		}
	}

	return 0;
}