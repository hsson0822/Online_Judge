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

	int N{};
	queue<int> nums;
	queue<int> trash;

	cin >> N;

	for (int i = 1; i <= N; ++i)
		nums.push(i);

	while (!nums.empty())
	{
		int n = nums.front();
		nums.pop();
		trash.push(n);

		if (nums.empty())
		{
			break;
		}
		else if (nums.size() == 1)
		{
			int n = nums.front();
			nums.pop();
			trash.push(n);
		}
		else
		{
			int n = nums.front();
			nums.pop();
			nums.push(n);
		}

	}

	while (!trash.empty())
	{
		int n = trash.front();
		trash.pop();
		cout << n << " ";
	}

	return 0;
}
