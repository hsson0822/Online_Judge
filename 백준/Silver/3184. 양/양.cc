#include <iostream>

using namespace std;

int N;
int M;
int cnt;

char ground[251][251];
bool visited[251][251];

int dx[4]{ 1,0,-1,0 };
int dy[4]{ 0,1,0,-1 };

int totalSheep;
int totalWolf;
int sheep;
int wolf;

void dfs(int x, int y)
{
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

		if (ground[nx][ny] == '#' || visited[nx][ny] == true) continue;

		if (ground[nx][ny] == 'o') ++sheep;
		else if (ground[nx][ny] == 'v') ++wolf;
		
		visited[nx][ny] = true;
		dfs(nx, ny);
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
			ground[i][j] = ch;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (ground[i][j] != '#' && visited[i][j] == false)
			{
				visited[i][j] = true;

				sheep = 0;
				wolf = 0;

				if (ground[i][j] == 'o') ++sheep;
				else if (ground[i][j] == 'v') ++wolf;

				dfs(i, j);

				if (sheep > wolf)
					totalSheep += sheep;
				else
					totalWolf += wolf;
			}
		}
	}
	cout << totalSheep << " " << totalWolf;
	return 0;
}