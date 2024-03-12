#include <iostream>
#include <deque>
#include <climits>
using namespace std;

class Point
{
public:
	int x;
	int y;
	int type;

	Point(int x, int y, int t) : x(x), y(y), type(t) {}
};

int N;
int M;
int answer = INT_MAX;
char room[9][9];
deque<pair<Point, int>> cctv;

void GoBottom(int x, int y)
{
	for (int i = x + 1; i < N; ++i)
	{
		if (room[i][y] == '6')
			break;

		if (room[i][y] == '0')
			room[i][y] = '#';
	}
}

void GoTop(int x, int y)
{
	for (int i = x - 1; i >= 0; --i)
	{
		if (room[i][y] == '6')
			break;

		if (room[i][y] == '0')
			room[i][y] = '#';
	}
}

void GoLeft(int x, int y)
{
	for (int i = y - 1; i >= 0; --i)
	{
		if (room[x][i] == '6')
			break;

		if (room[x][i] == '0')
			room[x][i] = '#';
	}
}

void GoRight(int x, int y)
{
	for (int i = y + 1; i < M; ++i)
	{
		if (room[x][i] == '6')
			break;

		if (room[x][i] == '0')
			room[x][i] = '#';
	}
}

void first(int x, int y, int dir)
{
	if (dir == 1)
	{
		GoTop(x, y);
	}
	else if (dir == 2)
	{
		GoRight(x, y);
	}
	else if (dir == 3)
	{
		GoBottom(x, y);
	}
	else if (dir == 4)
	{
		GoLeft(x, y);
	}
}

void second(int x, int y, int dir)
{
	if (dir == 1)
	{
		GoLeft(x, y);
		GoRight(x, y);
	}
	else if (dir == 2)
	{
		GoBottom(x, y);
		GoTop(x, y);
	}
}

void third(int x, int y, int dir)
{
	if (dir == 1)
	{
		GoTop(x, y);
		GoRight(x, y);
	}
	else if (dir == 2)
	{
		GoBottom(x, y);
		GoRight(x, y);
	}
	else if (dir == 3)
	{
		GoBottom(x, y);
		GoLeft(x, y);
	}
	else if (dir == 4)
	{
		GoLeft(x, y);
		GoTop(x, y);
	}
}

void fourth(int x, int y, int dir)
{
	if (dir == 1)
	{
		GoTop(x, y);
		GoRight(x, y);
		GoLeft(x, y);
	}
	else if (dir == 2)
	{
		GoBottom(x, y);
		GoRight(x, y);
		GoLeft(x, y);
	}
	else if (dir == 3)
	{
		GoBottom(x, y);
		GoTop(x, y);
		GoLeft(x, y);
	}
	else if (dir == 4)
	{
		GoBottom(x, y);
		GoTop(x, y);
		GoRight(x, y);
	}
}

void fifth(int x, int y)
{
	GoBottom(x, y);
	GoTop(x, y);
	GoRight(x, y);
	GoLeft(x, y);
}

void calcu()
{
	for (int i = 0; i < cctv.size(); ++i)
	{
		auto d = cctv[i];

		if (d.first.type == 1)
		{
			first(d.first.x, d.first.y, d.second);
		}
		else if (d.first.type == 2)
		{
			second(d.first.x, d.first.y, d.second);
		}
		else if (d.first.type == 3)
		{
			third(d.first.x, d.first.y, d.second);
		}
		else if (d.first.type == 4)
		{
			fourth(d.first.x, d.first.y, d.second);
		}
		else if (d.first.type == 5)
		{
			fifth(d.first.x, d.first.y);
		}
	}

	int cnt{};
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (room[i][j] == '0')
				++cnt;
		}
	}
	if (answer > cnt)
		answer = cnt;
}

void reset()
{

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (room[i][j] == '#')
				room[i][j] = '0';
		}
	}
}

void dfs(int cnt)
{
	if (cctv.size() == cnt)
	{
		calcu();
		reset();
		return;
	}

	if (cctv[cnt].first.type == 1)
	{
		for (int i = 1; i <= 4; ++i)
		{
			cctv[cnt].second = i;
			dfs(cnt + 1);
			cctv[cnt].second = 1;
		}
	}
	else if (cctv[cnt].first.type == 2)
	{
		for (int i = 1; i <= 2; ++i)
		{
			cctv[cnt].second = i;
			dfs(cnt + 1);
			cctv[cnt].second = 1;
		}
	}
	else if (cctv[cnt].first.type == 3)
	{
		for (int i = 1; i <= 4; ++i)
		{
			cctv[cnt].second = i;
			dfs(cnt + 1);
			cctv[cnt].second = 1;
		}
	}
	else if (cctv[cnt].first.type == 4)
	{
		for (int i = 1; i <= 4; ++i)
		{
			cctv[cnt].second = i;
			dfs(cnt + 1);
			cctv[cnt].second = 1;
		}
	}
	else
		dfs(cnt + 1);

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
			char k;
			cin >> k;
			room[i][j] = k;

			if (k != '0' && k != '6')
			{
				Point poi(i, j, k - '0');
				cctv.push_back(pair(poi, 1));

			}
		}
	}

	dfs(0);

	cout << answer;

	return 0;
}