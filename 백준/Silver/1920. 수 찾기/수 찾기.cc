#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count{};
	cin >> count;

	vector<int> N;
	for (int i = 0; i < count; ++i)
	{
		int n;
		cin >> n;
		N.push_back(n);
	}

	sort(N.begin(), N.end());

	cin >> count;

	for (int i = 0; i < count; ++i)
	{
		int n;
		cin >> n;
		
		if (binary_search(N.begin(), N.end(), n))
			cout << "1\n";
		else
			cout << "0\n";
	}
}