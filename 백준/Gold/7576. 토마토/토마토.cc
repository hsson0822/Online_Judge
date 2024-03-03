#include <iostream>
#include <queue>

using namespace std;

class Point
{
public:
	Point(int x, int y, int c) : x(x), y(y), cnt(c)
	{
		;
	}

	int x;
	int y;
	int cnt;
};

int	N;
int M;

queue<Point> que;
int farm[1001][1001];
int bigger;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs()
{
	while (que.size() != 0)
	{
		Point point = que.front();
		que.pop();

		if (point.cnt > bigger)
			bigger = point.cnt;

		for (int i = 0; i < 4; ++i)
		{
			int nx = point.x + dx[i];
			int ny = point.y + dy[i];

			if (nx <= 0 || nx > N || ny <= 0 || ny > M) continue;

			if (farm[nx][ny] == 0)
			{
				farm[nx][ny] = 1;
				Point temp = Point(nx, ny, point.cnt + 1);
				que.push(temp);
			}
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			int k;
			cin >> k;
			farm[i][j] = k;

			if (k == 1)
			{
				Point c = Point(i, j, 0);
				que.push(c);
			}
		}
	}

	bfs();

	bool flag = false;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (farm[i][j] == 0)
			{
				flag = true;
				bigger = -1;
				break;
			}
		}
		if (flag)
			break;
	}

	cout << bigger;

	return 0;
}