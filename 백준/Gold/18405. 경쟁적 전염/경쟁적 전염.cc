#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int K;
int S;
int X;
int Y;

int virus[201][201];
vector<pair<int, int>> pos[1001];

int dX[] = { 1,0,-1,0 };
int dY[] = { 0,1,0,-1 };

void bfs(int n)
{
	queue<pair<int,int>> Q;
	for (int i = 0; i < pos[n].size(); ++i)
		Q.push({ pos[n][i].first,pos[n][i].second });
    pos[n].clear();
	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dX[i];
			int ny = y + dY[i];

			if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
			if (virus[nx][ny] != 0) continue;

			virus[nx][ny] = n;
			pos[n].push_back({ nx,ny });
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	for (int i = 1; i <= N; ++i)
	{

		for (int j = 1; j <= N; ++j)
		{
			cin >> virus[i][j];

			if (virus[i][j] != 0)
				pos[virus[i][j]].push_back({ i,j });
		}
	}

	cin >> S >> X >> Y;

	for (int t = 0; t < S; ++t)
	{
		for (int k = 1; k <= K; ++k)
			bfs(k);
	}

	cout << virus[X][Y];

	return 0;
}
