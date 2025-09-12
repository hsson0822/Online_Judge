#include <bits/stdc++.h>

using namespace std;

int N, M;
char forrest[51][51];
bool visited[51][51];

int sx, sy;
int fx, fy;

int dx[]{1,0,-1,0};
int dy[]{0,1,0,-1};

struct Walk
{
	int x, y;
	int cnt;
	int trash, near;

	bool operator<(const Walk& temp) const
	{
		if(trash == temp.trash)
		{
			if(near == temp.near)
				cnt > temp.cnt;

			return near > temp.near;
		}
		
		return trash > temp.trash;
	}
};

void bfs()
{
	priority_queue<Walk> Q;
	visited[sx][sy]=true;
	Q.push({sx,sy,0,0,0});

	while(!Q.empty())
	{
		Walk cur = Q.top();
		Q.pop();

		//cout << cur.x << " , " << cur.y << endl;

		if(forrest[cur.x][cur.y] == 'F')
		{
			cout << cur.trash << " " << cur.near;
			break;
		}

		for(int i = 0 ; i < 4; ++i)
		{
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if(nx <= 0 ||ny <= 0 || nx > N || ny > M) continue;
			if(visited[nx][ny]) continue;

			bool nearTrash = false;
			for(int j =  0 ; j < 4; ++j)
			{
				int nnx = nx + dx[j];
				int nny = ny + dy[j];
				
				if(nnx <= 0 ||nny <= 0 || nnx > N || nny > M) continue;
				if(forrest[nnx][nny]=='g')
				{
					nearTrash = true;
					break;
				}
			}

			visited[nx][ny] = true;

			if(forrest[nx][ny] == 'F')
			{
				Q.push({nx,ny,cur.cnt+1,cur.trash, cur.near});
			}
			else if(forrest[nx][ny] == 'g')
			{
				Q.push({nx,ny,cur.cnt+1,cur.trash+1, cur.near});
			}
			else if(nearTrash)
			{
				Q.push({nx,ny,cur.cnt+1,cur.trash, cur.near+1});
			}
			else
				Q.push({nx,ny,cur.cnt+1,cur.trash, cur.near});
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N>> M;
	for(int i = 1 ; i <= N ; ++i)
	{
		for(int j =1 ; j <= M ; ++j)
		{
			cin >> forrest[i][j];

			if(forrest[i][j] == 'S')
			{
				sx = i;
				sy = j;
			}
		}
	}

	bfs();

	return 0;
}