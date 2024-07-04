#include <iostream>

using namespace std;

int N;
int M;
int ground[501][501];
int visitCnt[501][501];

int dX[4]{ 1,0,-1,0 };
int dY[4]{ 0,1,0,-1 };

int dfs(int x, int y)
{
	if (x == N - 1 && y == M - 1) return 1;
	if (visitCnt[x][y] != -1) return visitCnt[x][y];

	visitCnt[x][y] = 0;

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dX[i];
		int ny = y + dY[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (ground[x][y] <= ground[nx][ny]) continue;

		visitCnt[x][y] = visitCnt[x][y] + dfs(nx, ny);
		
	}

	return visitCnt[x][y];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			cin >> ground[i][j];
			visitCnt[i][j] = -1;
		}

	cout << dfs(0, 0);

	return 0;
}
