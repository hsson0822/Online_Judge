#include <bits/stdc++.h>

using namespace std;

int N, M, P;
int speed[10];

char board[1001][1001];

int dx[]{1, 0, -1, 0};
int dy[]{0, 1, 0, -1};

queue<pair<int, int>> area[10];
map<int, int> Count;

struct Type
{
	int type;
	int x, y;
};

void bfs()
{
	while (true)
	{
		bool expanded = false; 

		for (int type = 1; type <= P; ++type)
		{
			for (int s = 0; s < speed[type]; ++s)
			{
				int size = area[type].size();
				if(size == 0) break;

				while(size--)
				{
					int x = area[type].front().first;
					int y = area[type].front().second;
					area[type].pop();

					for (int i = 0; i < 4; ++i)
					{
						int nx = x + dx[i];
						int ny = y + dy[i];

						if (nx <= 0 || ny <= 0 || nx > N || ny > M)
							continue;
						if (board[nx][ny] == '#')
							continue;
						if (board[nx][ny] != '.')
							continue;

						board[nx][ny] = type + '0';
						area[type].push({nx, ny});
						expanded = true;
					}
				}
			}
		}

		if(!expanded) break;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> P;

	for (int i = 1; i <= P; ++i)
		cin >> speed[i];

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> board[i][j];

			if (board[i][j] != '.' && board[i][j] != '#')
			{
				area[board[i][j] - '0'].push({i, j});
			}
		}
	}

	bfs();

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			// cout << board[i][j] << " ";
			if (board[i][j] == '#')
				continue;
			if (board[i][j] == '.')
				continue;

			++Count[board[i][j] - '0'];
		}
		//cout << endl;
	}

	//cout << endl;
	for (auto m : Count)
		cout << m.second << " ";

	return 0;
}