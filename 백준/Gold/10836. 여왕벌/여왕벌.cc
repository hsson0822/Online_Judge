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

int M, N;
int bee[701][701];
int grow[701][701];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;
	// memset(bee, 1, sizeof(bee));
	fill(&bee[0][0], &bee[M][M], 1);

	for (int n = 0; n < N; ++n)
	{
		int zero, one, two;
		cin >> zero >> one >> two;

		for (int i = M - 1; i >= 0; --i)
		{
			if (zero > 0)
			{
				bee[i][0] += 0;
				--zero;
			}
			else if (one > 0)
			{
				bee[i][0] += 1;
				--one;
			}
			else if (two > 0)
			{
				bee[i][0] += 2;
				--two;
			}
		}

		for (int i = 1; i < M; ++i)
		{
			if (zero > 0)
			{
				bee[0][i] += 0;
				--zero;
			}
			else if (one > 0)
			{
				bee[0][i] += 1;
				--one;
			}
			else if (two > 0)
			{
				bee[0][i] += 2;
				--two;
			}
		}
	}
	for (int i = 1; i < M; ++i)
	{
		for (int j = 1; j < M; ++j)
		{
			bee[i][j] = max({bee[i - 1][j], bee[i][j - 1], bee[i - 1][j - 1]});
		}
	}

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << bee[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}