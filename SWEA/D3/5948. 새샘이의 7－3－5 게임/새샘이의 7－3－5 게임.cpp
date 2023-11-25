#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
    {
        int nums[7];
        for (int i = 0; i < 7; ++i)
        {
            int n;
            cin >> n;
            nums[i] = n;
        }

        set<int, greater<int>> sums;
        for (int i = 0; i < 5; ++i)
        {
            for (int j = i+1; j < 6; ++j)
            {
                for (int k = j + 1; k < 7; ++k)
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    sums.insert(sum);
                }
            }
        }

        vector<int> vec{ sums.begin(), sums.end() };

        cout << "#" << test_case << " " << vec[4] << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}