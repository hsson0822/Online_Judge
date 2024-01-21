#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int testCase;
	cin >> testCase;

	for (int t = 0; t < testCase; ++t)
	{
		vector<pair<int, int>> lis;
		int count;
		cin >> count;

		for (int i = 0; i < count; ++i)
		{
			int a;
			int b;
			cin >> a >> b;

			lis.push_back(make_pair(a, b));
		}

		sort(lis.begin(), lis.end());

		int sum=1 ;
		int temp = lis[0].second;

		for (int i = 1; i < lis.size(); ++i)
		{
			if (temp > lis[i].second)
			{
				temp = lis[i].second;
				++sum;
			}
		}
		cout << sum << endl;
	}

	return 0;
}