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
int lab[51][51];
vector<pair<int, int>> virus;
bool active[51];
int safeCnt{};

int answer = INT_MAX;

int visited[51][51];
int dx[]{ 1,0,-1,0 };
int dy[]{ 0,1,0,-1 };
const int INF = INT_MAX;

int bfs()
{
	fill(&visited[0][0], &visited[N][N + 1], INF);

	queue < tuple<int, int, int> > Q;
	int cnt{};
	for (int i = 0; i < virus.size(); ++i)
	{
		//cout << active[i];
		if (active[i])
		{
			Q.push({ virus[i].first, virus[i].second, 0 });
			visited[virus[i].first][virus[i].second] = 0;
		}
		/*else
		{
			visited[virus[i].first][virus[i].second] = -1;
		}*/
	}
	//cout << "size : " << Q.size() << endl;
	//int maxT = {};
	while (!Q.empty())
	{
		int x = get<0>(Q.front());
		int y = get<1>(Q.front());
		int t = get<2>(Q.front());
		//maxT = max(maxT, t);
		Q.pop();


		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nt = t + 1;

			if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
			if (lab[nx][ny] == 1) continue;
			if (visited[nx][ny] != INF)
				continue;



			++cnt;
			visited[nx][ny] = nt;
			Q.push({ nx,ny,nt });



		}
	}

	/*for (int i = 1; i <= N; ++i)
	{

		for (int j = 1; j <= N; ++j)
		{
			if (visited[i][j] == INF)
				cout << "- ";
			else
				cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	cout << cnt << " : " << safeCnt << endl;
	cout << maxT << endl;
	cout << endl;*/


	/*if (safeCnt == cnt)
	{
		answer = min(answer, maxT);
	}*/

	int maxT{};
	for (int i = 1; i <= N; ++i)
	{

		for (int j = 1; j <= N; ++j)
		{
			if (lab[i][j] == 0)
			{
				if (visited[i][j] == INF) return -1;

				maxT = max(maxT, visited[i][j]);
			}
		}
	}
	
	return maxT;
}

void spread(int x, int left)
{
	if (x == M)
	{
		int temp = bfs();
		if(temp != -1)
			answer = min(answer,bfs());
	}
	else
	{
		for (int i = left; i < virus.size(); ++i)
		{
			if (!active[i])
			{
				active[i] = true;
				spread(x + 1, i + 1);
				active[i] = false;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> lab[i][j];

			if (lab[i][j] == 2)
				virus.push_back({ i,j });
			else if (lab[i][j] == 0)
			{
				++safeCnt;
				//cout << i << " , " << j <<endl;
			}
		}
	}

	//cout << endl;
	spread(0, 0);

	if (answer == INF)
		cout << -1;
	else
		cout << answer;

	return 0;
}
