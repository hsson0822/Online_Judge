#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	cin >> count;

	int size;
	cin >> size;

	vector<int> vec;
	vec.reserve(count);

	for (int i = 0; i < count; ++i)
	{
		int n;
		cin >> n;
		vec.push_back(n);
	}

	sort(vec.begin(), vec.end());
	for (int n : vec)
	{
		if (n <= size)
			++size;
	}

	cout << size;
}