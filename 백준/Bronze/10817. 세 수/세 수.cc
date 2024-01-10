#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> nums;
    for (int i = 0; i < 3; ++i)
    {
	    int n;
	    cin >> n;
	    nums.push_back(n);
    }
    sort(nums.begin(), nums.end());
    cout << nums[1];
    return 0;
}