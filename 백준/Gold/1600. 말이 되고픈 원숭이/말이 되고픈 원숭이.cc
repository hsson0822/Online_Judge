#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int K;
int N;
int M;
int world[200][200];
bool visited[31][200][200];

int dX[4]{ 1,0,-1,0 };
int dY[4]{ 0,1,0,-1 };

pair<int, int> jump[8]{ {-2,-1},{-1,-2},{-2,1},{-1,2},{1,-2},{2,-1},{1,2},{2,1} };

void bfs()
{

	queue<pair<pair<int, int>, pair<int,int>>> Q;
	Q.push(pair(pair(0, 0), pair(0,0)));
	visited[0][0][0] = 0;

	while (!Q.empty())
	{
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int c = Q.front().second.first;
		int h = Q.front().second.second;
		Q.pop();

		if (x == N - 1 && y == M - 1)
		{
			cout << c;
			return;
		}

		if (h < K)
		{
			for (int i = 0; i < 8; ++i)
			{
				int nx = x + jump[i].first;
				int ny = y + jump[i].second;

				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (world[nx][ny] == 1) continue;
				if (visited[h+1][nx][ny] == true) continue;

				visited[h + 1][nx][ny] = true;
				Q.push(pair(pair(nx, ny), pair(c+1,h+1)));
			}
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dX[i];
			int ny = y + dY[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (world[nx][ny] == 1) continue;
			if (visited[h][nx][ny] == true) continue;

			visited[h][nx][ny] = true;
			Q.push(pair(pair(nx, ny), pair(c+1,h)));
		}
	}
	cout << -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K >> M >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> world[i][j];

	bfs();

	return 0;
}