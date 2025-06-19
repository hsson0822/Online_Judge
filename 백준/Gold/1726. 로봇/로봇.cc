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
int M;
int factory[101][101];
bool visited[101][101][5];

int SX, SY, SD;
int EX, EY, ED;

int dx[]{ 0,0,0,1,-1 };
int dy[]{ 0,1,-1,0,0 };

class Status
{
public:
	int x;
	int y;
	int d;
	int order;

	Status(int x, int y, int d, int o) : x(x), y(y), d(d), order(o) {}
};

int answer = INT_MAX;

void bfs()
{
	Status s = { SX, SY, SD, 0 };
	queue<Status> Q;
	Q.push(s);

	while (!Q.empty())
	{
		int x = Q.front().x;
		int y = Q.front().y;
		int d = Q.front().d;
		int order = Q.front().order;
		Q.pop();

		//cout << x << " , " << y << " : " << d <<" , " << s << " , " << c << " , " << order << endl;

		if (x == EX && y == EY && d == ED)
		{
			answer = min(answer, order);
			continue;
		}

		if (d == 1 || d == 2)
		{
			if (!visited[x][y][3])
			{
				Q.push({ x,y,3,order + 1 });
				visited[x][y][3] = true;
			}

			if (!visited[x][y][4])
			{
				Q.push({ x,y,4 ,order + 1 });
				visited[x][y][4] = true;
			}
		}
		else if (d == 3 || d == 4)
		{
			if (!visited[x][y][1])
			{
				Q.push({ x,y,1,order + 1 });
				visited[x][y][1] = true;
			}
			if (!visited[x][y][2])
			{
				Q.push({ x,y,2,order + 1 });
				visited[x][y][2] = true;
			}
		}


		for (int step = 1; step <= 3; step++) {
			int nx = x + dx[d] * step;
			int ny = y + dy[d] * step;

			if (nx < 1 || ny < 1 || nx > N || ny > M) break;

			// 장애물 검사
			if (factory[nx][ny] == 1) break;

			// 방문 검사 및 추가
			if (!visited[nx][ny][d]) {
				visited[nx][ny][d] = true;
				Q.push({ nx, ny, d, order + 1 });
			}
		}

	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			cin >> factory[i][j];

	cin >> SX >> SY >> SD;
	cin >> EX >> EY >> ED;

	bfs();

	cout << answer;

	return 0;
}
