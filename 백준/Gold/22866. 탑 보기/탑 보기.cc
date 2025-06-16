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

int building[100001];
pair<int,int> info[100001];
stack<pair<int, int>> leftStack;
stack<pair<int, int>> rightStack;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i)
		cin >> building[i];

	for (int i = N; i > 0; --i)
	{
		while (!leftStack.empty() && (leftStack.top().first <= building[i])) leftStack.pop();
		info[i].first += leftStack.size();
		if (!leftStack.empty()) info[i].second = leftStack.top().second;
		leftStack.push({ building[i], i });
	}

	for (int i = 1; i <= N; ++i)
	{
		while (!rightStack.empty() && (rightStack.top().first <= building[i])) rightStack.pop();
		info[i].first += rightStack.size();
		if (!rightStack.empty())
		{
			if (info[i].second == 0)
				info[i].second = rightStack.top().second;
			else if (abs(i - info[i].second) >= abs(i - rightStack.top().second))
				info[i].second = rightStack.top().second;
		}
		rightStack.push({ building[i],i });
	}

	for (int i = 1; i <= N; ++i)
	{
		if (info[i].first == 0)
			cout << 0 << "\n";
		else
			cout << info[i].first << " " << info[i].second << "\n";
	}

	return 0;
}
