#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int coun;
	cin >> coun;

	vector<int> nums;
	for (int i = 0; i < coun; ++i)
	{
		int n;
		cin >> n;
		nums.push_back(n);
	}

	int findNum;
	cin >> findNum;

	int c = count(nums.begin(), nums.end(), findNum);

	cout << c;
	
	return 0;
}