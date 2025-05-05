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

	string before;
	string after;

	cin >> before >> after;

	while (true)
	{
		if (*after.rbegin() == 'A')
		{
			after.erase(after.end() - 1);
		}
		else
		{
			after.erase(after.end() - 1);
			reverse(after.begin(), after.end());
		}

		if (before.size() == after.size())
		{
			if (before == after)
				cout << 1;
			else
				cout << 0;

			break;
		}
	}

	return 0;
}
