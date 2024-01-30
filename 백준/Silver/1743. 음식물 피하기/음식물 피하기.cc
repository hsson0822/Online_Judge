#include <iostream>

using namespace std;

int route[101][101];
bool visited[101][101];
int N;
int M;
int food;
int cnt;
int bigger;

int dx[]{ 1,0,-1,0 };
int dy[]{ 0,1,0,-1 };

void bfs(int x, int y)
{
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 1 || ny < 1 || nx > N || ny > M) continue;

		if (route[nx][ny] == 1 && visited[nx][ny] == false)
		{
			++cnt;
			
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

	cin >> N >> M >> food;

	for (int i = 0; i < food; ++i)
	{
		int a;
		int b;
		cin >> a >> b;
		route[a][b] = 1;
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (route[i][j] == 1 && visited[i][j] == false)
			{

				visited[i][j] = true;
				cnt = 1;
				bfs(i, j);

				if (bigger < cnt)
					bigger = cnt;
			}
		}
	}

	cout << bigger;

	return 0;
}