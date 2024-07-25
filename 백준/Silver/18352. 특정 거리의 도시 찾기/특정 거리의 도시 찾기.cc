#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int N;
int M;
int K;
int Start;
vector<int> graph[300001];
int leng[300001];

void dijkstra()
{
	queue<pair<int,int>> Q;
	leng[Start] = 0;
	Q.push({ Start,0 });

	while (!Q.empty())
	{
		int cur = Q.front().first;
		int cost = Q.front().second;
		Q.pop();

		for (int i = 0; i < graph[cur].size(); ++i)
		{
			int next = graph[cur][i];
			int nCost = cost + 1;

			if (leng[next] > nCost)
			{
				leng[next] = nCost;
				Q.push({ next, nCost });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K >> Start;

	for (int i = 0; i < M; ++i)
	{
		int a;
		int b;
		cin >> a >> b;

		graph[a].push_back(b);
	}

	fill_n(leng, N+1, INF);

	dijkstra();

	vector<int> ans;
	for (int i = 1; i <= N; ++i)
	{
		if (leng[i] == K)
			ans.push_back(i);
	}

	if (ans.size() == 0)
		cout << -1;
	else
	{
		for (int i = 0; i < ans.size(); ++i)
			cout << ans[i] << "\n";
	}

	return 0;
}