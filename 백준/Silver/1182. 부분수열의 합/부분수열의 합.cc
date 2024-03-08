#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int goal;
int nums[21];
int cnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> goal;

	for (int i = 0; i < N; ++i)
	{
		int k;
		cin >> k;
		nums[i] = k;
	}

	for (int i = 0; i < N; ++i)
	{
		vector<int> idx;

		for (int j = 0; j <= i; ++j)
		{
			idx.push_back(1);
		}
		for (int j = 0; j < N-i-1; ++j)
		{
			idx.push_back(0);
		}
		
		sort(idx.begin(), idx.end());
		
		do
		{
			int sum{};

			for (int i = 0; i < N; ++i)
			{
				if (idx[i] == 1)
				{
					sum += nums[i];
				}
			}

			if (sum == goal)
				++cnt;

		} while (next_permutation(idx.begin(), idx.end()));
	}

	cout << cnt;

	return 0;
}