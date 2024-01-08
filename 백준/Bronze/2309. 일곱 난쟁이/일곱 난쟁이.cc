#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> heights;
	for (int i = 0; i < 9; ++i)
	{
		int n;
		cin >> n;
		heights.push_back(n);
	}

	sort(heights.begin(), heights.end());

	do
	{
		int sum{};
		for (int i = 0; i < 7; ++i)
			sum += heights[i];

		if (sum == 100)
			break;

	} while (next_permutation(heights.begin(), heights.end()));

	for (int i = 0; i < 7; ++i)
		cout << heights[i] << endl;

	return 0;
}