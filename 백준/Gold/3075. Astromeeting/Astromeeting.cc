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

unsigned long long INF;
int N, P, Q;
unsigned long long dist[101][101];
map<int,int> startCnt;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int t = 0; t < T; ++t)
	{
		cin >> N >> P >> Q;

		INF = N * P * Q * 100;

		fill(&dist[0][0], &dist[P][P], INF);
		startCnt.clear();

		for (int n = 0; n < N; ++n)
		{
			int g;
			cin >> g;

			++startCnt[g];
		}

		for (int q = 0; q < Q; ++q)
		{
			int i, j;
			unsigned long long d;
			cin >> i >> j >> d;

			dist[i][j] = min(dist[i][j], d);
			dist[j][i] = min(dist[j][i], d);
		}

		for (int i = 1; i <= P; ++i)
			dist[i][i] = 0;

		for (int k = 1; k <= P; ++k)
		{
			for (int i = 1; i <= P; ++i)
			{
				for (int j = 1; j <= P; ++j)
				{
					if(i == j) continue;
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		// for (int i = 1; i <= P; ++i)
		// {
		// 	for (int j = 1; j <= P; ++j)
		// 	{
		// 		if (dist[i][j] == INF)
		// 		cout << "X ";
		// 		else
		// 		cout << dist[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		unsigned long long d[101];
		//memset(d,0,sizeof(d));
		fill(&d[0], &d[P], 0);
		
		unsigned long long dest{};
		unsigned long long leng = LLONG_MAX;
		
		for(auto m : startCnt)
		{
			int num = m.first;
			int cnt = m.second;
	
			for(int i = 1 ; i <= P ; ++i)
			{
				dist[num][i] = dist[num][i] * dist[num][i];
				dist[num][i] *= cnt;
				d[i] += dist[num][i];
			}
		}
		
		for(int i = 1 ; i <=P ; ++i)
		{
			//cout << i << " : " << d[i]<<endl;
			if(leng > d[i])
			{
				leng = d[i];
				dest = i;
			}

			//cout << i << " : " << d[i]<<endl;
		}

		unsigned long long answer{};
		for(auto m : startCnt)
		{
			answer += dist[m.first][dest];
		}

		cout << dest << " " << answer <<"\n";
	}

	return 0;
}