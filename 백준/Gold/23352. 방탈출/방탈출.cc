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

int N, M;
int board[52][52];
int dist[52][52];

int dx[]{1,0,-1,0};
int dy[]{0,1,0,-1};

int adist{};
int answer{};

void bfs(int i , int j)
{
	memset(dist, 0 , sizeof(dist));

	queue<pair<int,int>> Q;
	Q.push({i,j});
	dist[i][j] = 1;

	while(!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		if (dist[x][y] > adist)
		{
			adist = dist[x][y];
			answer = board[i][j] + board[x][y];
		}
		else if (dist[x][y] == adist)
			answer = max(answer, board[i][j] + board[x][y]);
	
		for(int i = 0 ; i < 4 ; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if(dist[nx][ny]) continue;
			if(board[nx][ny] == 0) continue;

			dist[nx][ny] = dist[x][y] + 1;
			Q.push({nx,ny});
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
			cin >> board[i][j];
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if(board[i][j])
				bfs(i,j);
		}
	}

	cout << answer;

	return 0;
}