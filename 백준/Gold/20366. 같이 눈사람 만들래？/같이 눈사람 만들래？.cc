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

	vector<int> nums(N, 0);
	for (int i = 0; i < N; ++i)
		cin >> nums[i];

	sort(nums.begin(), nums.end());
	// 2 3 5 5 9

	int answer = INT_MAX;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			int sum = nums[i] + nums[j];

			int left = i+1;
			int right = N-1;

			while (left < right)
			{
				if (right == j || right == i)
				{
					--right;
					continue;
				}
				
				if (left == j || left == i)
				{
					++left;
					continue;
				}

				int sum2 = nums[left] + nums[right];

				answer = min(answer, abs(sum - sum2));

				if (sum2 < sum)
					++left;
				else if (sum2 > sum)
					--right;
				else
				{
					answer = 0;
					break;
				}

			}
		}
	}
	
	cout << answer;

	return 0;
}
