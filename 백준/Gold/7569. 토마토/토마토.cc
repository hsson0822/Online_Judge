#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N;
int M;
int H;

int tomato[101][101][101];
int dirZ[6]{ 1,-1,0,0,0,0 };
int dirX[6]{ 0,0,1,-1,0,0 };
int dirY[6]{ 0,0,0,0,1,-1 };
bool visited[101][101][101];
int bigger;
int cntMax;
int cnt;
queue<tuple<int, int, int>> q;

void bfs()
{
	while (!q.empty())
	{
		int z = get<0>(q.front());
		int x = get<1>(q.front());
		int y = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 6; ++i)
		{
			int nz = z + dirZ[i];
			int nx = x + dirX[i];
			int ny = y + dirY[i];

			if (nx < 0 || ny < 0 || nz < 0) continue;
			if (nx >= N || ny >= M || nz >= H) continue;
			if (visited[nz][nx][ny]) continue;
			if (tomato[nz][nx][ny] == -1) continue;
			if (tomato[nz][nx][ny] >= 1) continue;

			visited[nz][nx][ny] = true;
			tomato[nz][nx][ny] = tomato[z][x][y]+1;
			++cnt;

			if (bigger < tomato[nz][nx][ny])
				bigger = tomato[nz][nx][ny];

			q.push(tuple(nz, nx, ny));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> H;

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				int n;
				cin >> n;
				tomato[i][j][k] = n;

				if (n == 1)
				{
					visited[i][j][k] = true;
					q.push(tuple(i, j, k));
					++cnt;
				}

				if (n != -1)
					++cntMax;
			}
		}
	}
	
	if (cnt == cntMax)
	{
		cout << 0;
		return 0;
	}

	bfs();

	if (cnt != cntMax)
		cout << -1;
	else
		cout << bigger-1;

	return 0;
}