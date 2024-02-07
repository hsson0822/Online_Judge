#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int M;
int cnt;

vector<int> fri[101];
vector<int> friCnt;
int visited[101];


void bfs(int start)
{
	queue<int> que;
	que.push(start);

	while (!que.empty())
	{
		int x = que.front();
		que.pop();

		for (int i = 0; i < fri[x].size(); ++i)
		{
			int y = fri[x][i];

			if (visited[y] == 0)
			{
				visited[y] = visited[x] + 1;
				cnt += visited[y];
				que.push(y);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int a;
		int b;
		cin >> a >> b;

		fri[a].push_back(b);
		fri[b].push_back(a);
	}

	for (int i = 1; i <= N; ++i)
	{
		cnt = 0;
		bfs(i);
		friCnt.push_back(cnt);
		memset(visited, 0, sizeof(visited));
	}

	cout << distance(friCnt.begin(), min_element(friCnt.begin(), friCnt.end()))+1;

	return 0;
}