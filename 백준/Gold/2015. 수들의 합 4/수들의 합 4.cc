#include <iostream>
#include <map>

using namespace std;

long long nums[200001];
map<int, long long> Map;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N;
	long long K;
	cin >> N >> K;

	long long ans{};
	
	for (int i = 1; i <= N; ++i)
	{
		cin >> nums[i];
		nums[i] += nums[i - 1];
		if (nums[i] == K) ans++;
	}

	for (int i = 1; i <= N; ++i)
	{
		ans += Map[nums[i] - K];
		Map[nums[i]]++;
	}

	cout << ans;

	return 0;
}