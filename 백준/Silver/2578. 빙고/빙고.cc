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


bool bingo[6][6];
pair<int, int> pos[26];

bool checkGa(int x, int y)
{
	int cnt{};
	for (int i = 1; i <= 5; ++i)
		if (bingo[x][i])
			++cnt;

	if (cnt == 5)
		return true;

	return false;
}

bool checkSe(int x, int y)
{
	int cnt{};
	for (int i = 1; i <= 5; ++i)
		if (bingo[i][y])
			++cnt;

	if (cnt == 5)
		return true;

	return false;
}

bool checkCro(int x, int y)
{
	int cnt{};
	for (int i = 1; i <= 5; ++i)
		if (bingo[i][i])
			++cnt;

	if (cnt == 5)
		return true;
	
	return false;
}

bool checkCroRe(int x, int y)
{
	int cnt{};
	for (int i = 1; i <= 5; ++i)
		if (bingo[i][6-i])
			++cnt;

	if (cnt == 5)
		return true;

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i <= 5; ++i)
	{
		for (int j = 1; j <= 5; ++j)
		{
			int n;
			cin >> n;
			pos[n] = { i,j };
		}
	}
	
	int i{};
	int bingoCnt{};
	for (i = 1; i <= 25; ++i)
	{
		int n;
		cin >> n;

		int x = pos[n].first;
		int y = pos[n].second;

		bingo[x][y] = true;

		if (checkGa(x, y))
		{
			++bingoCnt;
		}

		if (checkSe(x, y))
		{
			++bingoCnt;
		}

		if (x == y && checkCro(x, y))
		{
			++bingoCnt;
		}

		if (x+ y == 6 && checkCroRe(x, y))
		{
			++bingoCnt;
		}

		if (bingoCnt >= 3)
			break;
	}
	cout << i;
	
	return 0;
}
