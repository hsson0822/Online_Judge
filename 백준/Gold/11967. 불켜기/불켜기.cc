#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> room[101][101];
bool visited[101][101];

int light = 1;
bool lightOn[101][101];

bool ifVisit[101][101];

int dx[]{1, 0, -1, 0};
int dy[]{0, 1, 0, -1};

void bfs()
{
	queue<pair<int, int>> Q;
	visited[1][1] = true;
	lightOn[1][1] = true;
	Q.push({1, 1});


	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int i = 0; i < room[x][y].size(); ++i)
		{
			int a = room[x][y][i].first;
			int b = room[x][y][i].second;

			if (lightOn[a][b])
				continue;

			++light;
			lightOn[a][b] = true;

			if(ifVisit[a][b])
				Q.push({a,b});
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx<=0 ||ny <= 0 ||nx > N || ny > N) continue;
			if(visited[nx][ny]) continue;
			if(!lightOn[nx][ny])
			{
				ifVisit[nx][ny]= true;
				continue;
			}

			visited[nx][ny] = true;
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

	for (int i = 0; i < M; ++i)
	{
		int x, y, a, b;
		cin >> x >> y >> a >> b;

		room[x][y].push_back({a, b});
	}

	bfs();

	cout << light;

	return 0;
}