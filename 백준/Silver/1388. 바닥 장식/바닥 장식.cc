#include <iostream>

using namespace std;

int N;
int M;
int cnt;

char room[51][51];
bool visited[51][51];

int dx[4]{ 1,0,-1,0 };
int dy[4]{ 0,1,0,-1 };

void dfs(int x, int y, char ch)
{
	int nx = x;
	int ny = y;
	if (ch == '|')
		++nx;
	else if (ch == '-')
		++ny;

	if (nx < 0 || nx > N || ny < 0 || ny >= M) return;
	if (room[nx][ny] != ch || visited[nx][ny] == true) return;

	visited[nx][ny] = true;
	dfs(nx, ny, ch);
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
			char ch;
			cin >> ch;
			room[i][j] = ch;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (visited[i][j] == false)
			{
				++cnt;
				visited[i][j] = true;
				dfs(i, j, room[i][j]);
			}
		}
	}

	cout << cnt;

	return 0;
}