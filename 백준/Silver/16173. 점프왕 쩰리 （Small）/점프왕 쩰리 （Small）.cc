#include <iostream>

using namespace std;

int N;
int game[3][3];
bool visited[3][3];

void dfs(int x, int y)
{
	int k = game[x][y];
	visited[x][y] = true;

	if (game[x][y] == -1) return;

	if (x + k < N && visited[x+k][y] == false)
		dfs(x + k, y);

	if (y + k < N && visited[x][y + k] == false)
		dfs(x, y + k);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int num;
			cin >> num;
			game[i][j] = num;
		}
	}

	dfs(0, 0);


	if (visited[N - 1][N - 1])
		cout << "HaruHaru";
	else
		cout << "Hing";

	return 0;
}