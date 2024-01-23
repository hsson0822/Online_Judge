#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	cin >> count;

	long long stairs[400]{0};
	long long dp[400]{0};

	for (int i = 1; i <= count; ++i)
	{
		int n;
		cin >> n;
		stairs[i] = n;
	}
    
    dp[1] = stairs[1];

    if(count >=2)
	    dp[2] = stairs[1] + stairs[2];

    if(count >= 3)
	    dp[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);

	for (int i = 4; i <= count; ++i)
	{
		dp[i] = max(dp[i-2] + stairs[i], dp[i-3] + stairs[i-1] + stairs[i]);
	}

	cout << dp[count];

	return 0;
}