#include <iostream>

using namespace std;

int maze[1001][1001];
int drop[1001][1001];

int bigger(int a, int b, int c)
{
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int M;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			int n;
			cin >> n;
			maze[i][j] = n;
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (i == 1 && j == 1)
			{
				drop[1][1] = maze[1][1];
				continue;
			}

			drop[i][j] = maze[i][j];
			drop[i][j] += bigger(drop[i - 1][j], drop[i - 1][j - 1], drop[i][j - 1]);
		}
	}

	cout << drop[N][M];
	
	return 0;
}