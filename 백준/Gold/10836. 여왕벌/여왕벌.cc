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
		fill(&grow[0][0], &grow[M][M], 0);

		int zero, one, two;
		cin >> zero >> one >> two;
		queue<int> Q;
		for (int i = 0; i < zero; ++i)
			Q.push(0);
		for (int i = 0; i < one; ++i)
			Q.push(1);
		for (int i = 0; i < two; ++i)
			Q.push(2);

		for (int i = M - 1; i >= 0; --i)
		{
			grow[i][0] += Q.front();
			Q.pop();
		}

		for (int i = 1; i < M; ++i)
		{
			grow[0][i] += Q.front();
			Q.pop();
		}

		for (int i = 1; i < M; ++i)
		{
			for (int j = 1; j < M; ++j)
			{
				grow[i][j] = max({grow[i - 1][j], grow[i][j - 1], grow[i - 1][j - 1]});
			}
		}

		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				bee[i][j] += grow[i][j];
			}
		}
	}

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << bee[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}