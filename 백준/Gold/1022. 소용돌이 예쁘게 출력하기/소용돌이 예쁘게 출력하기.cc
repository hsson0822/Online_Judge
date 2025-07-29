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

int tornado[100][50];

//       → ↑ ← ↓
int dX[]{0, -1, 0, 1};
int dY[]{1, 0, -1, 0};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	int big = max({abs(r1), abs(c1), abs(r2), abs(c2)});
	int N = (big * 2) + 1;
	int X = N / 2 + 1;
	int Y = N / 2 + 1;

	r1 = r1 + big + 1;
	c1 = c1 + big + 1;
	r2 = r2 + big + 1;
	c2 = c2 + big + 1;

	//cout << r1 << " " << c1 << " "  << r2 << " "  << c2 <<endl;

	int T{};
	int num = 1;
	int dir{};
	int l{};

	while (true)
	{
		int cnt = (T / 2) + 1;
		if (cnt >= N)
			cnt = N - 1;

		// cout <<"A" << endl;

		// cout <<"CNT : " << cnt << endl;
		for (int c = 0; c < cnt; ++c)
		{
			//cout << X << " , " << Y << " : " << num << endl;
			if (X >= r1 && Y >= c1 && X <= r2 && Y <= c2)
			{
				tornado[X-r1+1][Y-c1+1] = num++;
				 l = max(l, (int)to_string(num).length() );
			}
			else
			++num;
			
			X += dX[dir];
			Y += dY[dir];
			
			// cout << X <<" , " << Y << " : " << num << endl;
		}

		if (X == N && Y == N)
		{
			if (X >= r1 && Y >= c1 && X <= r2 && Y <= c2)
				tornado[X-r1+1][Y-c1+1] = num;
			// cout << num;
			break;
		}

		++dir;
		if (dir >= 4)
			dir -= 4;

		++T;
	}


	// for(int i = 1 ; i <= r2-r1+1; ++i)
	// {
	// 	for(int j = 1 ; j <= c2-c1+1; ++j)
	// 	{
	// 		cout.width(l);
	// 		cout << tornado[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }


	for (int i = 1 ; i <= r2-r1+1 ; ++i)
	{
		for (int j = 1; j <= c2-c1+1 ; ++j)
		{
			cout.width(l);
			//cout << i << " , " << j<< " : ";
			cout << tornado[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}