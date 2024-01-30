#include <iostream>

using namespace std;

char war[101][101];
bool visited[101][101];
int N;
int M;
int cnt;
int white;
int blue;

int dx[]{ 1,0,-1,0 };
int dy[]{ 0,1,0,-1 };

void dfs(int x, int y, char team)
{
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

		if (war[nx][ny] == team && visited[nx][ny] == false)
		{
			++cnt;
			visited[nx][ny] = true;
			dfs(nx, ny, team);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			char ch;
			cin >> ch;
			war[i][j] = ch;
		}
	}

	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (visited[i][j] == false)
			{
				cnt = 1;
				visited[i][j] = true;
				
				dfs(i,j, war[i][j]);

				if (war[i][j] == 'W')
					white += cnt * cnt;
				else if (war[i][j] == 'B')
					blue += cnt * cnt;
			}
		}
	}
	
	cout << white << " " << blue;

	return 0;
}