#include <iostream>
#include <queue>

using namespace std;

int N;
int M;
int cnt;

int paper[101][101];
bool visited[101][101];

int dx[4]{ 1,0,-1,0 };
int dy[4]{ 0,1,0,-1 };

priority_queue<int, vector<int>, greater<int>> area;

void dfs(int x, int y)
{
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

		if (paper[nx][ny] == 0 && visited[nx][ny] == false)
		{
			visited[nx][ny] = true;
			++cnt;
			dfs(nx, ny);
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int K;
	cin >> M >> N >> K;

	for (int i = 0; i < K; ++i)
	{
		int lbX;
		int lbY;
		int rtX;
		int rtY;

		cin >> lbX >> lbY >> rtX >> rtY;

		for (int j = lbX; j < rtX; ++j)
		{
			for (int k = lbY; k < rtY; ++k)
			{
				paper[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (paper[i][j] == 0 && visited[i][j] == false)
			{
				visited[i][j] = true;
				cnt = 1;
				dfs(i, j);
				area.push(cnt);
			}
		}
	}

	cout << area.size() << endl;
	int size = area.size();
	for (int i = 0 ; i < size ; ++i)
	{
		int n = area.top();
		area.pop();
		cout << n << " ";
	}

	return 0;
}