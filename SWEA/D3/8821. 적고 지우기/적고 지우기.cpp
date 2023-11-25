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
        string str;
        cin >> str;

        vector<int> nums;

        for (char ch : str)
        {
            if (nums.size() == 0)
            {
                nums.push_back(ch - '0');
                continue;
            }

            auto iter = find(nums.begin(), nums.end(), ch - '0');

            if (iter != nums.end())
            {
                nums.erase(iter);
            }
            else
            {
                nums.push_back(ch - '0');
            }
        }

        cout << "#" << test_case << " " << nums.size() << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}