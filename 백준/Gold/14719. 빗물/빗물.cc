#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int H;
	int W;
	cin >> H >> W;

	vector<int> block;
	block.assign(W, 0);

	for (int i = 0; i < W; ++i)
	{
		cin >> block[i];
	}

	int answer{};
	for (int i = 1; i < W-1; ++i)
	{
		int left = 0;
		int right = 0;

		for (int j = 0; j < i; ++j)
			left = max(left, block[j]);

		for (int j = i; j < W; ++j)
			right = max(right, block[j]);

		answer += max(0, min(left, right) - block[i]);
	}

	cout << answer;

	return 0;
}