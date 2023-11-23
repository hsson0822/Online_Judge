#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int numCount;
        cin >> numCount;

        vector<int> nums;
        for (int i = 0; i < numCount; ++i)
        {
            int n;
            cin >> n;
            nums.push_back(n);
        }

        long buy{};
        long buyCount{};
        long gain{};
        long max = *max_element(nums.begin(), nums.end());
        for (auto iter = nums.begin(); iter != nums.end(); ++iter)
        {
            if (*iter != max)
            {
                buy += *iter;
                ++buyCount;
            }
            else
            {
                gain += ((*iter) * buyCount) - buy;
                buy = 0;
                buyCount = 0;
                if(iter +1 != nums.end())
                    max = *max_element(iter+1, nums.end());
            }
        }
        cout << "#" << test_case << " " << gain << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}