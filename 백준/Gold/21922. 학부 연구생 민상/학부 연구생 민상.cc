#include <iostream>
#include <queue>

using namespace std;

int N;
int M;
int lab[2001][2001];
bool visited[4][2001][2001];
int ans[2001][2001];

int dir[4][2]{ {-1,0},{0,1},{1,0},{0,-1} };

queue<pair<pair<int, int>, int>> Q;

void bfs()
{
	while (!Q.empty())
	{
		int d = Q.front().second;
		int nx = Q.front().first.first + dir[d][0];
		int ny = Q.front().first.second + dir[d][1];
		Q.pop();

		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (visited[d][nx][ny]) continue;

		visited[d][nx][ny] = true;
		ans[nx][ny] = 1;

		if (lab[nx][ny] == 1 && (d == 1 || d == 3)) continue;
		else if (lab[nx][ny] == 2 && (d == 0 || d == 2)) continue;
		else if (lab[nx][ny] == 9) continue;
		else if (lab[nx][ny] == 3)
		{
			if (d == 0)
				d = 1;
			else if (d == 1)
				d = 0;
			else if (d == 2)
				d = 3;
			else if (d == 3)
				d = 2;
		}
		else if (lab[nx][ny] == 4)
		{
			if (d == 0)
				d = 3;
			else if (d == 1)
				d = 2;
			else if (d == 2)
				d = 1;
			else if (d == 3)
				d = 0;
		}
		
		Q.push(pair(pair(nx, ny), d));

	}
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
			cin >> lab[i][j];
			if (lab[i][j] == 9)
			{
				ans[i][j] = 1;
				for (int k = 0; k < 4; ++k)
				{
					Q.push(pair(pair(i, j), k));
					visited[k][i][j] = true;
				}

			}
		}
	}

	bfs();

	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			sum += ans[i][j];
		}
	}

	cout << sum;
	return 0;
}