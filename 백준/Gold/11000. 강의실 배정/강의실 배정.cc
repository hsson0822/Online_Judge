#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	cin >> count;

	priority_queue<int, vector<int>, greater<int>> subject;
	vector<pair<long long, long long>> nums;

	for (int i = 0; i < count; ++i)
	{
		int s;
		int t;
		cin >> s >> t;
		subject.push(t);
		nums.push_back(make_pair(s, t));
	}

	sort(nums.begin(), nums.end());

	for (int i = 0; i < count; ++i)
	{
		if (nums[i].first >= subject.top())
		{
			subject.pop();
			continue;
		}
	}

	cout << subject.size();
	
	return 0;
}