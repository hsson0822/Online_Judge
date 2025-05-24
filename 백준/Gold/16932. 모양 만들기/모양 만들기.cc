#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <sstream>
#include <climits>
#include <math.h>
#include <cstring>

using namespace std;

int N;
int M;
int shape[1001][1001];
int areas[1001][1001];
int areaCnt[1002001];
bool visited[1001][1001];

int dx[]{ 1,0,-1,0 };
int dy[]{ 0, 1, 0, -1 };

int area{};
int answer = INT_MIN;

void bfs(int i, int j)
{
	queue<pair<int, int>> Q;
	visited[i][j] = true;
	areas[i][j] = area;
	Q.push({ i,j });
	int cnt = 1;

	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		
		//cout << x << " , " << y << endl;

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if (visited[nx][ny]) continue;
			if (shape[nx][ny] == 0) continue;

			visited[nx][ny] = true;
			areas[nx][ny] = area;
			++cnt;
			Q.push({ nx,ny });
		}
	}
	areaCnt[area] = cnt;
	//cout << area << " : " << cnt << endl <<endl;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			cin >> shape[i][j];

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			if (shape[i][j] == 1 && !visited[i][j])
			{
				++area;
				bfs(i, j);
			}

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
		{
			if (shape[i][j] == 0)
			{
				set<int> s;

				for (int k = 0; k < 4; ++k)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					//cout << areas[nx][ny] << endl;
					s.insert(areas[nx][ny]);
				}

				int sum = 1;
				for (int n : s)
					sum += areaCnt[n];
				//cout << "sum : " << sum << endl;
				answer = max(answer, sum);
				//cout << endl << endl;
			}
		}

	cout << answer;

	return 0;
}
