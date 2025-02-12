#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int n;
vector<int> liquid;
int miniest = 2000000000;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int n;
		cin >> n;
		liquid.push_back(n);
	}

	sort(liquid.begin(), liquid.end());

	int left = 0;
	int right = n - 1;

	int leftAns{};
	int rightAns{};
	

	while (left < right)
	{
		int m = liquid[left] + liquid[right];

		if (abs(m) < miniest)
		{
			leftAns = liquid[left];
			rightAns = liquid[right];
			miniest = abs(m);

			if (m == 0)
				break;
		}

		if (m > 0)
		{
			--right;
		}
		else
		{
			++left;
		}


	}

	cout << leftAns << " " << rightAns;

	return 0;
}

