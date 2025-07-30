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

int T;
int N;
int mine[10001][10001];
int erase = 10;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for(int t = 0 ; t < T ; ++t)
	{
		memset(mine, 0, sizeof(mine));

		cin >> N;
		int maxMine = 0;

		for(int n = 0 ; n < N ; ++n)
		{
			int x, y;
			cin >> x >> y;

			for(int i = y ; i <= y + 10 ; ++i)
			{
				if(i > 10000) break;

				for(int j = x ; j <= x + 10 ; ++j)
				{
					if(j > 10000) break;
					++mine[i][j];
					maxMine = max(maxMine, mine[i][j]);
				}
			}
		}


		cout <<maxMine<<"\n";
	}

	return 0;
}