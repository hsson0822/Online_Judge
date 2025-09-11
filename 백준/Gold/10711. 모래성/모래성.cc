#include <bits/stdc++.h>

using namespace std;

int H, W;
char castle[1001][1001];

queue<pair<int, int>> wave;
int sands[1001][1001];

int dx[]{1, 0, -1, 0, 1, 1, -1, -1};
int dy[]{0, 1, 0, -1, 1, -1, 1, -1};

int answer{};

void bfs()
{
	while (!wave.empty())
	{
		int size = wave.size();

		while (size--)
		{
			int x = wave.front().first;
			int y = wave.front().second;
			wave.pop();

			for (int i = 0; i < 8; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx <= 0 || ny <= 0 || nx > H || ny > W)
					continue;
				if(castle[nx][ny] =='.') continue;

				--sands[nx][ny];

				if (sands[nx][ny] <= 0)
				{
					wave.push({nx, ny});
					castle[nx][ny] = '.';
				}
			}
		}

		++answer;

	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> H >> W;

	for (int i = 1; i <= H; ++i)
	{
		for (int j = 1; j <= W; ++j)
		{
			cin >> castle[i][j];
			if (castle[i][j] == '.')
			{
				wave.push({i, j});
				sands[i][j] = 0;
			}
			else
				sands[i][j] = castle[i][j] - '0';
		}
	}

	bfs();

	// for (int i = 1; i <= H; ++i)
	// {
	// 	for (int j = 1; j <= W; ++j)
	// 	{
	// 		cout << castle[i][j];
	// 	}
	// 	cout << "\n";
	// }



	cout <<answer-1;

	return 0;
}