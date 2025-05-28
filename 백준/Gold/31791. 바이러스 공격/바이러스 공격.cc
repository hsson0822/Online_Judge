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

int N, M;
int TG, TB, X, B;
char univ[1001][1001];
int spread[1001][1001];
priority_queue<
				pair<int, pair<int, int>>,
				vector<pair<int, pair<int, int>>>,
				greater<pair<int, pair<int, int>>>
				> virus;

const int INF = INT_MAX;

int dx[]{ 1,0,-1,0 };
int dy[]{ 0,1,0,-1 };

void bfs()
{
	while (!virus.empty())
	{
		int t = virus.top().first;
		int x = virus.top().second.first;
		int y = virus.top().second.second;

		virus.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;

			char& value = univ[nx][ny];

			if (value == '#')
			{
				int time = t + TB + 1;
				if (time <= TG)
				{
					value = '*';
					if (time < TG)
					{
						virus.push({ time,{nx,ny} });
					}
				}
				else
					value = '-';
			}
			else if (value == '.')
			{
				int time = t + 1;
				if (time <= TG)
				{
					value = '*';
					if (time < TG)
					{
						virus.push({ time,{nx,ny} });
					}
				}
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
	cin >> TG >> TB >> X >> B;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> univ[i][j];
			if (univ[i][j] == '*')
				virus.push({ 0,{ i,j} });
		}
	}

	/*for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (spread[i][j] == INF)
				cout << "- ";
			else
				cout << spread[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/


	bfs();



	//for (int i = 1; i <= N; ++i)
	//{
	//	for (int j = 1; j <= M; ++j)
	//	{
	//		if (spread[i][j] == INF)
	//			cout << "- ";
	//		else
	//			cout << spread[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << endl;

	int cnt{};
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (univ[i][j] == '#' || univ[i][j] == '.' || univ[i][j] == '-')
			{
				cout << i << " " << j << "\n";
				++cnt;
			}
		}
	}

	if (cnt == 0)
		cout << -1;

	return 0;
}
