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
long long M;

vector<long long> nums;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		long long n;
		cin >> n;
		nums.push_back(n);
	}

	sort(nums.begin(), nums.end());

	int left{};
	int right{};

	long long miniest = LLONG_MAX;

	while (left <= right && right < N)
	{
		long long n = nums[right] - nums[left];

		if (n >= M && n < miniest)
			miniest = n;

		if (n < M)
			++right;
		else
			++left;		
	}
	
	cout << miniest;
	return 0;
}
