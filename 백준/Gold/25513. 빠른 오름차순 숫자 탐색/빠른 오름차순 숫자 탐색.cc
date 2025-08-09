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

int px, py;
int board[5][5];
bool visited[5][5];
int dist{};

int dx[]{1, 0, -1, 0};
int dy[]{0, 1, 0, -1};

struct Point
{
	int x, y, d;
};

bool bfs(int dest)
{
	memset(visited, false, sizeof(visited));
	//cout << "now : " << px << " , " << py<<endl; 
	queue<Point> Q;
	visited[px][py] = true;
	Q.push({px, py, 0});

	while (!Q.empty())
	{
		int x = Q.front().x;
		int y = Q.front().y;
		int d = Q.front().d;
		Q.pop();

		//cout << x << " , " << y << endl;

		if (board[x][y] == dest)
		{
			//cout << "A " << d << endl;
			dist += d;
			px = x;
			py = y;
			return true;
		}
		
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
			continue;
			if (board[nx][ny] == -1)
			continue;
			if (visited[nx][ny])
			continue;
			
			//cout << nx << " " <<ny << endl;
			visited[nx][ny] = true;
			Q.push({nx, ny, d + 1});
		}
	}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cin >> board[i][j];
		}
	}

	cin >> px >> py;

	for (int i = 0; i < 6; ++i)
	{
		if (!bfs(i + 1))
		{
			dist = -1;
			break;
		}
		//cout << endl;
	}

	cout << dist;

	return 0;
}