#include <iostream>
#include <map>
#include <math.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string num{};
	cin >> num;

	map<char, int> nums;
	int answer{};

	for (char ch : num)
	{
		++nums[ch];	
	}
	//699

	double temp = nums['6'] + nums['9'];
	temp /= 2;
	temp = ceil(temp);
	nums['6'] = temp;
	nums['9'] = temp;

	for (auto& n : nums)
		answer = max(answer, n.second);

	cout << answer;
	
	return 0;
}