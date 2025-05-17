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

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N;
	long long M;
	cin >> N >> M;

	long long tX = N / 2;
	long long tY = M / 2;

	long long t = min(tX, tY);

	long long x = N - 2*t;
	long long y = M - 2*t;

	if (x == 0 || y == 0)
	{
		--t;
		x += 2;
		y += 2;
	}

	long long answer = t * 4;
	
	long long posX{};
	long long posY{};

	if (x == 1)
	{
		posX = x;
		posY = y;
	}
	else if (y == 1)
	{
		++answer;

		posX = x;
		posY = y;
	}
	else if (x == 2)
	{
		answer += 2;

		posX = x;
		posY = y - (y-x)-1;
	}
	else
	{
		answer += 3;

		posX = x-(x-y);
		posY = y-1;
	}

	posX += t;
	posY += t;


	cout << answer << "\n";
	cout << posX << " " << posY;

	return 0;
}