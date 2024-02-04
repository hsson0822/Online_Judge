#include <iostream>
#include <cstring>

using namespace std;

int ground[51][51];
bool visited[51][51];
int cnt;

int N;
int M;

int dx[8]{ 1,0,-1,0,1,1,-1,-1 };
int dy[8]{ 0,1,0,-1,-1,1,1,-1 };

void reset()
{
	memset(ground, 0, sizeof(ground));
	memset(visited, false, sizeof(visited));
	cnt = 0;
}

void bfs(int x, int y)
{
	
	for (int i = 0; i < 8; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

		if (ground[nx][ny] == 1 && visited[nx][ny] == false)
		{
			visited[nx][ny] = true;
			bfs(nx, ny);
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (true)
	{
		cin >> M >> N;

		if (N == 0 || M == 0) break;

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				int n;
				cin >> n;
				ground[i][j] = n;
			}
		}

		cnt = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (ground[i][j] == 1 && visited[i][j] == false)
				{
					++cnt;
					visited[i][j] = true;
					bfs(i, j);
				}
			}
		}

		cout << cnt << endl;
		reset();
	}

	return 0;
}