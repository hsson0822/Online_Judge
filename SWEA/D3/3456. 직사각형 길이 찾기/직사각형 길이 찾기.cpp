#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
    {
		vector<int> nums;

		for (int i = 0; i < 3; ++i)
		{
			int n;
			cin >> n;

			auto iter = find(nums.begin(), nums.end(), n);
			if(iter != nums.end())
			{
				nums.erase(iter, iter + 1);
			}
			else
				nums.push_back(n);
		}

        cout << "#" << test_case << " " << nums[0] << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}