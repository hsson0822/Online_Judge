#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N;
	cin >> N;

	vector<int> vec;

	for (int i = 0; i < N; ++i)
	{
		int k;
		cin >> k;
		vec.push_back(k);
	}

	sort(vec.begin(), vec.end());

	int max = 0;
	for (int i = 0; i < vec.size(); ++i)
	{
		int weight = vec[i] * (vec.size() - i);
		if (weight > max)
			max = weight;
	}
	cout << max;
}