#include <iostream>
#include <queue>

using namespace std;

int cube[6][6];
int answer[6][6];

int dirX[4]{1,0,-1,0};
int dirY[4]{0,1,0,-1};

const int INF = 987654321;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int time = 1;
	while (true)
	{
		int N;
		cin >> N;

		if (N == 0)
			break;

		int cave[125][125];
		int lost[125][125]{ 0 };

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> cave[i][j];
				lost[i][j] = INF;
			}
		}
				

		queue<pair<int, int>> Q;
		Q.push(pair(0, 0));
		lost[0][0] = cave[0][0];

		while (!Q.empty())
		{
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();

			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dirX[i];
				int ny = y + dirY[i];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (lost[nx][ny] <= lost[x][y] + cave[nx][ny]) continue;

				lost[nx][ny] = lost[x][y] + cave[nx][ny];
				Q.push(pair(nx, ny));
			}
		}

		cout << "Problem " << time++ << ": " << lost[N - 1][N - 1] << "\n";
	}

	return 0;
}