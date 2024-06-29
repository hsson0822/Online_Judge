#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N;
int M;
int cheese[101][101];
bool visited[101][101];
int temp[101][101];

int dirX[4]{ 1,0,-1,0 };
int dirY[4]{ 0,1,0,-1 };

int before;
int after;

void bfs()
{
	queue<pair<int, int>> Q;
	visited[1][1] = true;
	Q.push(pair(1, 1));
	
	memset(temp, 0, sizeof(temp));
	memset(visited, false, sizeof(visited));

	before = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			temp[i][j] = cheese[i][j];
			if (cheese[i][j] == 1)
				++before;
			
		}
	}

	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dirX[i];
			int ny = y + dirY[i];

			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if (visited[nx][ny]) continue;

			visited[nx][ny] = true;

			if (cheese[nx][ny] == 1)
			{
				temp[nx][ny] = 0;
				continue;
			}

			Q.push(pair(nx, ny));
		}
	}

	after = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cheese[i][j] = temp[i][j];
			if (temp[i][j] == 1)
				++after;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> cheese[i][j];
		}
	}

	int time{};
	while (true)
	{
		bfs();
		++time;
		if (after == 0)
			break;
	}

	cout << time << "\n" << before;
	
	return 0;
}