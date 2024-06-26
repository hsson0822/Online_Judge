#include <iostream>

using namespace std;

int nums[100000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	long long S;
	cin >> S;


	for (int i = 0; i < N; ++i)
		cin >> nums[i];

	int start = 0;
	int end = 0;

	int miniest{};
	int minStart{};
	int minEnd = N+1;
	long long sum{};

	while (true)
	{
		if (sum >= S)
		{
			sum -= nums[start];
			++start;
		}
		else if (end == N)
		{
			break;
		}
		else
		{
			sum += nums[end];
			++end;
		}
	
		if (sum >= S)
		{
			if (end - start < minEnd - minStart)
			{
				minEnd = end;
				minStart = start;
				miniest = end - start;
			}
		}
	}

	if (miniest == N+1)
		cout << 0;
	else
		cout << miniest;

	return 0;
}