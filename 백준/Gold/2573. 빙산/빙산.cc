#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;
int M;
int ice[301][301];
int temp[301][301];
int area[301][301];
int dirX[4]{ 1,0,-1,0 };
int dirY[4]{ 0,1,0,-1 };

void bfs(int x, int y, int cnt)
{
	queue<pair<int, int>> Q;
	Q.push(pair(x, y));
	area[x][y] = cnt;

	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dirX[i];
			int ny = y + dirY[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (area[nx][ny] != 0) continue;
			if (ice[nx][ny] == 0) continue;

			area[nx][ny] = cnt;
			Q.push(pair(nx, ny));
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
			cin >> ice[i][j];
		}
	}
	
	int time = 1;
	while (true)
	{
		memset(temp, 0, sizeof(temp));
		memset(area, 0, sizeof(area));

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				int water{};
				for (int k = 0; k < 4; ++k)
				{
					int nx = i + dirX[k];
					int ny = j + dirY[k];
						
					if (ice[nx][ny] == 0)
						++water;
				}
				temp[i][j] = ice[i][j] - water;
				if (temp[i][j] < 0) temp[i][j] = 0;
			}
		}

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				ice[i][j] = temp[i][j];

		int cnt=1;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (ice[i][j] == 0) continue;
				if (area[i][j] != 0) continue;

				bfs(i, j, cnt);
				++cnt;
			}
		}

		if (cnt <= 1)
		{
			time = 0;
			break;
		}

		if (cnt >= 3)
			break;

		++time;
	}

	cout << time;

	return 0;
}