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

int N;
char house[51][51];
int visited[51][51][4];

int dx[]{1, 0, -1, 0};
int dy[]{0, 1, 0, -1};

int startX;
int startY;

const int INF = INT_MAX;
int answer = INT_MAX;

struct Light
{
	int x, y, dir, cnt;
};

void bfs()
{
	fill(&visited[0][0][0], &visited[N][N][4], INF);

	queue<Light> Q;

	//cout << startX<<endl;
	for(int i = 0 ; i < 4; ++i)
	{
		visited[startX][startY][i] = 0;	
		Q.push({startX, startY, i, 0});
	}
		
	while (!Q.empty())
	{
		Light cur = Q.front();
		Q.pop();

		int nx = cur.x + dx[cur.dir];
		int ny = cur.y + dy[cur.dir];
		//cout << cur.x << " , " << cur.y << endl;

		while (true)
		{
			if (nx <= 0 || ny <= 0 || nx > N || ny > N)
				break;

			if (house[nx][ny] == '*')
				break;

			if (house[nx][ny] == '#' && nx == startX && ny == startY)
				break;
			else if (house[nx][ny] == '#')
			{
				answer = min(answer,cur.cnt);
				break;
			}

			if (house[nx][ny] == '!')
			{
				if (cur.dir == 0 || cur.dir == 2)
				{
					if (visited[nx][ny][1] > cur.cnt+1)
					{
						visited[nx][ny][1] = cur.cnt+1;
						Q.push({nx, ny, 1, cur.cnt + 1});
					}

					if (visited[nx][ny][3] > cur.cnt+1)
					{
						visited[nx][ny][3] = cur.cnt+1;
						Q.push({nx, ny, 3, cur.cnt + 1});
					}
				}
				else if (cur.dir == 1 || cur.dir == 3)
				{
					if (visited[nx][ny][0] > cur.cnt+1)
					{
						visited[nx][ny][0] = cur.cnt+1;
						Q.push({nx, ny, 0, cur.cnt + 1});
					}

					if (visited[nx][ny][2] > cur.cnt+1)
					{
						visited[nx][ny][2] = cur.cnt+1;
						Q.push({nx, ny, 2, cur.cnt + 1});
					}
				}

				if (visited[nx][ny][cur.dir] > cur.cnt)
				{
					visited[nx][ny][cur.dir] = cur.cnt;
					Q.push({nx, ny, cur.dir, cur.cnt});
				}

				break;
			}

			nx += dx[cur.dir];
			ny += dy[cur.dir];
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> house[i][j];

			if (house[i][j] == '#' && startX == 0 && startY == 0)
			{
				startX = i;
				startY = j;
			}
		}
	}

	bfs();

	cout <<answer;

	return 0;
}