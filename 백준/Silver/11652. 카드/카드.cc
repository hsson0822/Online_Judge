#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map<long long, long long> nums;

	int count;
	cin >> count;

	for (int i = 0; i < count; ++i)
	{
		long long n;
		cin >> n;
		nums[n]++;
	}

	vector<pair<long long, long long>> vec{nums.begin(), nums.end()};
	
	sort(vec.begin(), vec.end(), [](auto& a, auto& b)
		{
			return a.first < b.first;
		});

	stable_sort(vec.begin(), vec.end(), [](auto& a, auto& b)
		{
			return a.second > b.second;
		});

	cout << vec[0].first;
}