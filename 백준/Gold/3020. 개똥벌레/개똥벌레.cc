#include <bits/stdc++.h>

using namespace std;

vector<int> under;
vector<int> top;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, H;
	cin >> N>>H;

	for(int i = 0 ; i < N/2 ; ++i)
	{
		int u, t;
		cin >> u >> t;

		under.push_back(u);
		top.push_back(t);

	}

	sort(under.begin(), under.end());
	sort(top.begin(), top.end());


	int miniest = INT_MAX;
	int cnt{};

	for(int i = 1 ; i <= H ; ++i)
	{
		int low = lower_bound(under.begin(), under.end(), i) - under.end();
		int high = lower_bound(top.begin(), top.end(), H-i+1) - top.end();

		low = -low;
		high = -high;

		if(miniest > low+high)
		{
			miniest = low+high;
			cnt = 1;
		}
		else if(miniest == low+high)
			++cnt;
	}

	cout << miniest<< " " << cnt;

	return 0;
}