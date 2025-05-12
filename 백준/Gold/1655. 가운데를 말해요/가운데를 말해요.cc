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

	int N;
	cin >> N;

	priority_queue<int, vector<int>, less<int>> left;
	priority_queue<int, vector<int>, greater<int>> right;
	int center = INT_MAX;

	for (int i = 0; i < N; ++i)
	{
		int n;
		cin >> n;
		
		if (center == INT_MAX)
		{
			center = n;
			cout << center << "\n";
			continue;
		}

		if (n <= center)
			left.push(n);
		else
			right.push(n);

		if (left.size() > right.size())
		{
			right.push(center);
			center = left.top();
			left.pop();
		}
		else if (left.size() < right.size()-1)
		{
			left.push(center);
			center = right.top();
			right.pop();
		}

		cout << center << "\n";
	}



	return 0;
}
