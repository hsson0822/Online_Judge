#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <sstream>
#include <climits>
#include <math.h>
#include <cstring>

using namespace std;

int L, R, C;
char building[31][31][31];
int visited[31][31][31];

int sz, sx, sy;
int ez, ex, ey;

int dz[]{1, -1, 0, 0, 0, 0};
int dx[]{0, 0, 1, -1, 0, 0};
int dy[]{0, 0, 0, 0, 1, -1};

struct Point {
    int z, x, y;
};

void bfs()
{
	queue<Point> Q;
	Q.push({sz, sx, sy});
	visited[sz][sx][sy] = 0;

	while (!Q.empty())
	{
		int z = Q.front().z;
		int x = Q.front().x;
		int y = Q.front().y;
		Q.pop();

		if (z == ez && x == ex && y == ey)
		{
			cout << "Escaped in " << visited[z][x][y] << " minute(s).\n";
			return;
		}

		for (int i = 0; i < 6; ++i)
		{
			int nz = z + dz[i];
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nz <= 0 || nx <= 0 || ny <= 0)
				continue;
			if (nz > L || nx > R || ny > C)
				continue;
			if (building[nz][nx][ny] == '#')
				continue;
			//if (visited[nz][nx][ny] >= visited[z][x][y] + 1)
				//continue;
			if (visited[nz][nx][ny] != -1) continue;

			visited[nz][nx][ny] = visited[z][x][y] + 1;
			Q.push({nz, nx, ny});
		}
	}

	cout << "Trapped!\n";
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		cin >> L >> R >> C;

		if(L == 0 && R == 0 && C == 0) break;

		memset(visited, -1, sizeof(visited));
		fill(&building[0][0][0], &building[L][R][C], '.');

		for (int i = L; i > 0; --i)
		{
			for (int j = 1; j <= R; ++j)
			{
				for (int k = 1; k <= C; ++k)
				{
					cin >> building[i][j][k];

					if (building[i][j][k] == 'S')
					{
						sz = i;
						sx = j;
						sy = k;
					}
					else if (building[i][j][k] == 'E')
					{
						ez = i;
						ex = j;
						ey = k;
					}
				}
			}
		}

		bfs();
	}

	return 0;
}