#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
    {
        int size;
        cin >> size;

        vector<int> nums;

        for (int i = 0; i < size; ++i)
        {
            int n;
            cin >> n;
            nums.push_back(n);
        }

        int answer{};
        for (int i = 1; i < nums.size() - 1; ++i)
        {
            if (nums[i - 1] > nums[i] && nums[i + 1] > nums[i]) continue;
            if (nums[i - 1] < nums[i] && nums[i + 1] < nums[i]) continue;
            ++answer;
        }


        cout << "#" << test_case << " " << answer << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}