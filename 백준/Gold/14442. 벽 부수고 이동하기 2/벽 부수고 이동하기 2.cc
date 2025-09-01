#include <bits/stdc++.h>

using namespace std;

int N, M, K;
static unsigned char world[1001][1001];
static bool visited[1001][1001][11];

int dx[]{1, 0, -1, 0};
int dy[]{0, 1, 0, -1};

struct Walk
{
	short x, y;
	unsigned char erase;
};

int bfs()
{
	queue<Walk> Q;
	Q.push({1, 1, 0});
	visited[1][1][0] = true;

	int dist = 1;

	while (!Q.empty())
	{
		int size = Q.size();
		while (size--)
		{
			Walk cur = Q.front();
			Q.pop();

			// cout <<x << " " << y << endl;

			if (cur.x == N && cur.y == M)
				return dist;

			for (int i = 0; i < 4; ++i)
			{
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];

				if (nx <= 0 || ny <= 0 || nx > N || ny > M)
					continue;

				if (world[nx][ny] == 0)
				{
					if(!visited[nx][ny][cur.erase])
					{
						visited[nx][ny][cur.erase] = true;
						Q.push({(short)nx, (short)ny, (unsigned char)cur.erase});
					}
				}
				else
				{
					if (cur.erase < K && !visited[nx][ny][cur.erase + 1]) 
					{	
						visited[nx][ny][cur.erase + 1] = true;
						Q.push({(short)nx, (short)ny, (unsigned char)(cur.erase + 1)});
					}
				}
			}
		}
		++dist;
	}

	return -1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			char ch;
			cin >> ch;
			world[i][j] = (unsigned char)(ch - '0');
		}
	}

	cout << bfs();

	return 0;
}