#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> need;

	for (int i = 0; i < 2; ++i)
	{
		int n;
		cin >> n;
		need.push_back(1 - n);
	}

	for (int i = 0; i < 3; ++i)
	{
		int n;
		cin >> n;
		need.push_back(2 - n);
	}

	int n;
	cin >> n;
	need.push_back(8 - n);

	for (int n : need)
		cout << n << " ";

	return 0;
}
