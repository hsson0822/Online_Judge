#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
vector<int> vec;
int answer{};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int k;
		cin >> k;
		vec.push_back(k);
	}

	sort(vec.begin(), vec.end());

	do
	{
		int sum{};
		for (int i = 0; i < N - 1; ++i)
		{
			sum += abs(vec[i] - vec[i + 1]);
		}

		if (sum > answer)
			answer = sum;

	} while (next_permutation(vec.begin(), vec.end()));

	cout << answer;

	return 0;
}