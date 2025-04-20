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
int cnt{};
int r;
int c;

bool divide(int beginX, int beginY, int endX, int endY)
{
	int leng = endX - beginX;

	bool flag = false;

	if (leng != 2)
	{
		int halfX = beginX + leng/2;
		int halfY = beginY + leng/2;

		if (r >= beginX && r < halfX && c >= beginY && c < halfY)
		{
			flag = divide(beginX, beginY, halfX, halfY);
			if (flag)
				return true;
		}
		else
			cnt += (halfX-beginX) * (halfY-beginY);
			
		if (r >= beginX && r < halfX && c >= halfY && c < endY)
		{
			flag = divide(beginX, halfY, halfX, endY);
			if (flag)
				return true;
		}
		else
			cnt += (halfX-beginX) * (endY- halfY);

		if (r >= halfX && r < endX && c >= beginY && c < halfY)
		{
			flag = divide(halfX, beginY, endX, halfY);
			if (flag)
				return true;
		}
		else
			cnt += (endX-halfX) * (halfY- beginY);

		if (r >= halfX && r < endX && c >= halfY && c < endY)
		{
			flag = divide(halfX, halfY, endX, endY);
			if (flag)
				return true;
		}
		else
			cnt += (endX-halfX) * (endY-halfY);
	}
	else
	{
		for (int i = beginX; i < endX; ++i)
		{
			for (int j = beginY; j < endY; ++j)
			{
				if (i == r && j == c)
					return true;
				else
					++cnt;
			}
		}
	}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> r >> c;
	N = pow(2, N);

	divide(0, 0, N, N);

	cout << cnt;

	return 0;
}
