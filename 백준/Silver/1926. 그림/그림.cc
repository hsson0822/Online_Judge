#include <iostream>
#include <queue>

using namespace std;

int N;
int M;
int paper[501][501];
bool visited[501][501];

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

int cnt;
int bigger;
int pic;

void bfs(int x, int y)
{
	queue<pair<int,int>> que;
	que.push(pair(x,y));
	visited[x][y] = true;

	while (!que.empty())
	{
		auto x = que.front();
		que.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x.first + dx[i];
			int ny = x.second + dy[i];

			if (nx >= N || nx < 0 || ny >= M || ny < 0) continue;
	
			if (paper[nx][ny] == 1 && visited[nx][ny] == false)
			{
				visited[nx][ny] = true;
				++cnt;
				que.push(pair(nx, ny));
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

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int a;
			cin >> a;
			paper[i][j] = a;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (paper[i][j] == 1 && visited[i][j] == false)
			{
				cnt = 1;
				bfs(i, j);
				if (bigger < cnt)
					bigger = cnt;
				++pic;
			}
		}
	}

	cout << pic << endl;
	cout << bigger << endl;
	return 0;
}