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

char mountain[101][101];
bool visited[101][101][4];
const int INF = INT_MAX;

queue<pair<int, int>> wolfQ;
int dx[]{ 1,0,-1,0 };
int dy[]{ 0,1,0,-1 };

pair<int,int> goStraight(int dir, int x, int y)
{
	int nx = x;
	int ny = y;

	if (dir == 0)
	{
		while (mountain[nx][y] != '#' && mountain[nx][y] != '.')
			visited[nx++][y][dir] = true;

		if (mountain[nx][y] == '#')
			--nx;
	}
	else if (dir == 1)
	{
		while (mountain[x][ny] != '#' && mountain[x][ny] != '.')
			visited[x][ny++][dir] = true;

		if (mountain[nx][ny] == '#')
			--ny;
	}
	else if (dir == 2)
	{
		while (mountain[nx][y] != '#' && mountain[nx][y] != '.')
			visited[nx--][y][dir] = true;
		
		if (mountain[nx][ny] == '#')
			++nx;
	}
	else if (dir == 3)
	{
		while (mountain[x][ny] != '#' && mountain[x][ny] != '.')
			visited[x][ny--][dir] = true;
		
		if (mountain[nx][ny] == '#')
			++ny;
	}

	if (mountain[nx][ny] == '.')
		mountain[nx][ny] = 'X';

	return { nx,ny };
}

void bfs()
{
	queue<tuple<int,int,int>> Q;
	
	while (!wolfQ.empty())
	{
		Q.push({ wolfQ.front().first, wolfQ.front().second, -1});
		wolfQ.pop();
	}

	while (!Q.empty())
	{
		int x = get<0>(Q.front());
		int y = get<1>(Q.front());
		int d = get<2>(Q.front());
		Q.pop();

		//cout << x << " , " << y << endl;

		for (int i = 0; i < 4; ++i)
		{
			if (d != -1 && (d+2)%4 == i)
				continue;

			int nx = x + dx[i];
			int ny = y + dy[i];

			if (mountain[nx][ny] == '#') continue;
			if (mountain[nx][ny] == 'X') continue;
			if (visited[nx][ny][i]) continue;

			if (mountain[nx][ny] == '+')
			{
				visited[nx][ny][i] = true;
				pair<int,int> p = goStraight(i, nx, ny);
				Q.push({ p.first, p.second, i });
				continue;
			}

			if (mountain[nx][ny] == '.')
			{
				mountain[nx][ny] = 'X';
				visited[nx][ny][i] = true;
				Q.push({ nx,ny, i });
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
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> mountain[i][j];
			
			if (mountain[i][j] == 'W')
				wolfQ.push({ i,j });

		}
	}

	bfs();

	/*cout << endl;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cout << mountain[i][j];
		}
		cout << endl;
	}

	cout << endl;*/

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (mountain[i][j] == 'X')
				mountain[i][j] = '.';
			else if (mountain[i][j] == '.')
				mountain[i][j] = 'P';

			cout << mountain[i][j];
		}
		cout << "\n";
	}

	return 0;
}
