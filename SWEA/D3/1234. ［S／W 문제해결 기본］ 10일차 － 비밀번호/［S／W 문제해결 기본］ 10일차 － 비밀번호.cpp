#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;

    for (test_case = 1; test_case <= 10; ++test_case)
    {
        int numCount;
        cin >> numCount;

        string str;
        cin >> str;
        
        vector<int> nums;
        for (char ch : str)
        {
            int n = ch - '0';
            nums.push_back(n);
        }

        auto it = nums.begin();
        while (true)
        {
            it = adjacent_find(nums.begin(), nums.end());

            if (it == nums.end())
                break;
            nums.erase(it, it+2);
        }

        cout << "#" << test_case << " ";
        for (int n : nums)
            cout << n;
        cout << endl;
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}