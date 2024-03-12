#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> vec;
	for (int i = 1; i <= n; ++i)
	{
		vec.push_back(i);
	}

	do
	{
		for (int i = 0; i < vec.size(); ++i)
		{
			cout << vec[i] << " ";
		}
		cout << "\n";
	} while (next_permutation(vec.begin(), vec.end()));
	
	return 0; 
}