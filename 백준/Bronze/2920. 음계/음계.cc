#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> um;
	for (int i = 0; i < 8; ++i)
	{
		int n;
		cin >> n;
		um.push_back(n);
	}

	if (is_sorted(um.begin(), um.end(), greater<int>()))
	{
		cout << "descending" << endl;
	}
	else if (is_sorted(um.begin(), um.end(), less<int>()))
	{
		cout << "ascending" << endl;
	}
	else
	{
		cout << "mixed" << endl;
	}

	return 0;
}