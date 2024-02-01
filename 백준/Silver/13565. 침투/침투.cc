#include <iostream>

using namespace std;

int N;
int M;
int material[1001][1001];
bool visited[1001][1001];

int dx[4]{ 1,0,-1,0 };
int dy[4]{ 0,1,0,-1 };

void dfs(int x, int y)
{
	visited[x][y] = true;

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

		if (material[nx][ny] == 0 && visited[nx][ny] == false)
			dfs(nx,ny);
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
			char ch;
			cin >> ch;
			material[i][j] = ch - '0';
		}
	}

	for (int i = 0; i < M; ++i)
	{
		visited[0][i] = true;
		dfs(0,i);
	}
	
	bool flag = false;
	for (int i = 0; i < M; ++i)
	{
		if (visited[N-1][i])
		{
			flag = true;
			break;
		}
	}

	if (flag)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}