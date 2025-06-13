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
int K;

queue<int> route[1001];
queue<int> buildList;
int parentCnt[1001];
int timer[1001];
int builded[1001];

void build()
{
	while (!buildList.empty())
	{
		int size = buildList.size();

		for (int i = 0; i < size; ++i)
		{
			int cur = buildList.front();
			buildList.pop();

			int size2 = route[cur].size();
			for (int j = 0; j < size2; ++j)
			{
				int next = route[cur].front();
				route[cur].pop();
				--parentCnt[next];

				builded[next] = max(builded[next], builded[cur] + timer[next]);
				if (parentCnt[next] == 0)
				{
					buildList.push(next);
					//cout << next << "A" << buildList.size() << endl;
					//cout << cur << " A: " << builded[cur] <<" , "<< timer[next] << endl;
				}
			}

			

		}
		
	}
}

void reset()
{
	for (int i = 0; i <= N; ++i)
	{
		route[i] = {};
		parentCnt[i] = 0;

		timer[i] = 0;
		builded[i] = 0;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int t = 0; t < T; ++t)
	{
		cin >> N >> K;

		reset();

		for (int i = 1; i <= N; ++i)
			cin >> timer[i];

		for (int i = 0; i < K; ++i)
		{
			int a, b;
			cin >> a >> b;

			route[a].push(b);
			++parentCnt[b];
		}

		for (int i = 1; i <= N; ++i)
		{
			if (parentCnt[i] == 0)
			{
				buildList.push(i);
				builded[i] = timer[i];
			}
		}
		
		build();


		int W;
		cin >> W;

		//cout << endl;
		//for (int i = 1; i <= N; ++i)
		//	cout << i << " : " << builded[i] << endl;

		cout << builded[W] << "\n";

		//cout << endl;
	}

	return 0;
}
