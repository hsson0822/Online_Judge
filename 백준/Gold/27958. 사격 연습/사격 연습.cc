#include <iostream>
#include <math.h>

using namespace std;

class Block
{
public:
	int total=0;
	int now=0;

	Block() { total = 0; now = 0; };

	Block(int total, int now) : total(total), now(now) {};
};

int N;
int bulletCount;
Block board[9][9][9];
bool visited[9][9];
int bullet[6];
int maxPoint;

void showBoard(int shotCount)
{
	cout << endl;
	cout << shotCount+1 << " 번째 샷 데미지" << bullet[shotCount] << endl;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout<< "[" << board[shotCount][i][j].now << ", " << board[shotCount][i][j].total << "] ";
		}
		cout << endl;
	}
	cout << endl;
}

void dfs(int point, int shotCount)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			board[shotCount + 1][i][j] = board[shotCount][i][j];
		}
	}

	

	if (shotCount == bulletCount)
	{
		//cout << "A " << point << endl;
		if (point > maxPoint)
			maxPoint = point;

		return;
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			bool cantshot = false;
			for (int k = 0; k < j; ++k)
				if (board[shotCount][i][k].now != 0) { cantshot = true; break; };
			if (cantshot)
				break;

			if (board[shotCount][i][j].now == 0) continue;

			bool broken = false;

			if (board[shotCount][i][j].now >= 10)
			{
				point += board[shotCount][i][j].total;
				board[shotCount + 1][i][j].now = 0;
				broken = true;
			}
			else
			{
				board[shotCount + 1][i][j].now -= bullet[shotCount];

				if (board[shotCount + 1][i][j].now <= 0)
				{
					board[shotCount + 1][i][j].now = 0;
					point += board[shotCount+1][i][j].total;
					broken = true;

					if (i != 0 && board[shotCount][i - 1][j].now == 0)
					{
						board[shotCount + 1][i - 1][j].now = floor(board[shotCount][i][j].total / 4.0);
						board[shotCount + 1][i - 1][j].total = floor(board[shotCount][i][j].total / 4.0);

					}

					if (j != 0 && board[shotCount][i][j - 1].now == 0)
					{
						board[shotCount + 1][i][j - 1].now = floor(board[shotCount][i][j].total / 4.0);
						board[shotCount + 1][i][j - 1].total = floor(board[shotCount][i][j].total / 4.0);
					}

					if (i < N - 1 && board[shotCount][i + 1][j].now == 0)
					{
						board[shotCount + 1][i + 1][j].now = floor(board[shotCount][i][j].total / 4.0);
						board[shotCount + 1][i + 1][j].total = floor(board[shotCount][i][j].total / 4.0);
					}

					if (j < N - 1 && board[shotCount][i][j + 1].now == 0)
					{
						board[shotCount + 1][i][j + 1].now = floor(board[shotCount][i][j].total / 4.0);
						board[shotCount + 1][i][j + 1].total = floor(board[shotCount][i][j].total / 4.0);
					}
				}
			}
			
			//showBoard(shotCount);
			dfs(point, shotCount + 1);

			if (broken)
				point -= board[shotCount][i][j].total;

			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < N; ++j)
				{
					board[shotCount + 1][i][j] = board[shotCount][i][j];
				}
			}

		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> bulletCount;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int n;
			cin >> n;

			board[0][i][j].total = n;
			board[0][i][j].now = n;
		}
	}

	for (int i = 0; i < bulletCount; ++i)
	{
		int n;
		cin >> n;

		bullet[i] = n;
	}

	dfs(0, 0);

	cout << maxPoint;

	return 0;
}