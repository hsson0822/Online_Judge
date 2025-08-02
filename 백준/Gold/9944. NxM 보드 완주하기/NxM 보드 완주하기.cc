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
char board[31][31];
bool visited[31][31];
int allBlankCnt{};
int blankCnt{};
int minStep = INT_MAX;

int dx[]{1, 0, -1, 0};
int dy[]{0, 1, 0, -1};

void dfs(int x, int y, int step)
{
	//cout << x << " " << y << " : " << step <<endl;

	if(allBlankCnt == blankCnt)
	{
		//cout <<"AAAAAAAAAAAAAAAAAAAAAAA" << step<<endl;
		minStep = min(minStep, step);
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int nx = x;
		int ny = y;

		//cout << x << " , " << y << " " <<"before : " << blankCnt<<endl;
		while( true)
		{
			nx += dx[i];
			ny += dy[i];

			if(nx <= 0 || ny <= 0 || nx > N || ny > M) break;
			if(visited[nx][ny]) break;
			if(board[nx][ny] == '*') break;
			
			visited[nx][ny] = true;
			++blankCnt;
		}
		
		nx -= dx[i];
		ny -= dy[i];
		//cout << "TO : " << nx << " " << ny << endl;

		if (!(nx == x && ny == y))
			dfs(nx,ny,step+1);
		
		while(!(nx == x && ny == y))
		{
			visited[nx][ny] = false;
			--blankCnt;
			
			nx -= dx[i];
			ny -= dy[i];
		}
		//cout << x << " , " << y << " " <<"after : " << blankCnt<<endl;
		//cout << "Return : " << nx << " " << ny << endl;

	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T = 1;
	while (cin >> N >> M)
	{
		allBlankCnt = 0;
		fill(&board[0][0], &board[N][M], '.');
		blankCnt = 0;
		minStep = INT_MAX;

		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= M; ++j)
			{
				cin >> board[i][j];
				if (board[i][j] == '.')
				{
					++allBlankCnt;
				}
			}
		}

		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= M; ++j)
			{
				if (board[i][j] == '.')
				{
					++blankCnt;
					visited[i][j] = true;

					dfs(i, j, 0);

					--blankCnt;
					visited[i][j] = false;
					//cout << endl;
				}
				//cout << endl;
			}
		}

		if (minStep == INT_MAX)
			cout << "Case " << T++ << ": -1" << "\n";
		else
			cout << "Case " << T++ << ": " << minStep << "\n";
	}

	return 0;
}