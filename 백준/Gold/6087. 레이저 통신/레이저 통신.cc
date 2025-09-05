#include <bits/stdc++.h>

using namespace std;

int N, M;
char world[101][101];

int SX, SY;
int EX, EY;
int visited[101][101][4];

int dx[]{1,0,-1,0};
int dy[]{0,1,0,-1};

struct Light
{
	int x, y, dir, cnt;
};

int answer = INT_MAX;

void bfs()
{
	queue<Light> Q;
	Q.push({SX,SY,-1,-1});

	while(!Q.empty())
	{
		int x = Q.front().x;
		int y = Q.front().y;
		int d = Q.front().dir;
		int cnt = Q.front().cnt;
		Q.pop();

		//cout << x << " " << y << " : " << cnt <<endl;

		if(x == EX && y == EY)
		{
			//cout << cnt <<"AAAAAAAAAAAAAAAA" << endl;
			answer = min(answer, cnt);
			continue;
		}
		
		if(visited[x][y][d] < cnt) continue;

		for(int i = 0 ; i < 4 ; ++i)
		{
			if(i == d) continue;

			if(d != -1)
			{
				if((i+2)%4 == d)
					continue;
			}
			

			int nx = x + dx[i];
			int ny = y + dy[i];

			if(world[nx][ny] == '*') continue;
			if(nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if(visited[nx][ny][i] <= cnt+1) continue;
			
			visited[nx][ny][i] = cnt+1;
			Q.push({nx,ny,i,cnt+1});
		}
		
		
		if(d == -1) continue;
		
		int nx = x + dx[d];
		int ny = y + dy[d];
		
		if(nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
		if(visited[nx][ny][d] <= cnt) continue;
		if(world[nx][ny] == '*') continue;

		visited[nx][ny][d] = cnt;
		Q.push({nx,ny,d,cnt});
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;

	for(int i = 1 ; i <= N ; ++i)
	{
		for(int j = 1; j <= M ; ++j)
		{
			cin >> world[i][j];

			if(SX == 0 && world[i][j] == 'C')
			{
				SX = i;
				SY = j;
			}
			else if(world[i][j] == 'C')
			{
				EX = i;
				EY = j;
			}

			for(int k = 0 ; k < 4 ; ++k)
				visited[i][j][k] = INT_MAX;
		}
	}

	bfs();

	cout <<answer;

	return 0;
}