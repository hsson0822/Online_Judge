#include <iostream>
#include <map>

using namespace std;

int nums[200000];
map<int, int> cnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int K;
	cin >> N >> K;

	for (int i = 0; i < N; ++i)
		cin >> nums[i];

	int left = 0;
	int right = 0;
	
	int big{};
	int size{};

	while (right < N)
	{
		cnt[nums[right]]++;

		if (cnt[nums[right]] > K)
		{
			while (cnt[nums[right]] > K)
			{
				--cnt[nums[left]];
				++left;
				--size;
			}
		}

		++size;
		if (big < size)
			big = size;

		++right;
	}
	
	cout << big;

	return 0;
}