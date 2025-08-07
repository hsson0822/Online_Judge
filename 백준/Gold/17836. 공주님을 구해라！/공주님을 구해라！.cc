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

int N, M, T;
int castle[101][101];
int visited[101][101][2];
const int INF = INT_MAX;

int dx[]{1, 0, -1, 0};
int dy[]{0, 1, 0, -1};

struct Hero
{
	int x, y, t;
	bool sword;
};

int bfs()
{
	memset(visited, -1, sizeof(visited));
	
	queue<Hero> Q;
	Q.push({1, 1, 0, false});
	visited[1][1][0] = 0;

	while (!Q.empty())
	{
		int x = Q.front().x;
		int y = Q.front().y;
		int t = Q.front().t;
		bool s = Q.front().sword;
		Q.pop();

		//cout << x << " , " << y << " : " << t << " " << boolalpha << s << endl;
		
		if(t > T) continue;
		
		if (x == N && y == M)
		{
			return t;
		}
		
		
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			bool ns = s;
			
			if (nx <= 0 || ny <= 0 || nx > N || ny > M)
			continue;
			
			
			if (castle[nx][ny] == 1 && !s)
			continue;
			
			if (castle[nx][ny] == 2)
			ns = true;
			
			
			if (visited[nx][ny][ns] != -1)
				continue;
			
			visited[nx][ny][ns] = t+1;
			Q.push({nx, ny, t+1, ns});
		}
	}
	return INT_MAX;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> T;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			cin >> castle[i][j];

	int answer = bfs();

	if (answer <= T)
		cout << answer;
	else
		cout << "Fail";

	return 0;
}