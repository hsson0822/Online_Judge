#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N;
        cin >> N;
        
        int input;
        cin >> input;
        
        vector<int> nums;
        for(int i = 0 ; i < N ; ++i)
        {
            int k;
            cin >>k;
            nums.push_back(k);
        }
        sort(nums.rbegin(), nums.rend());
        
        int sum{};
        for(int i =  0; i < input ; ++i)
            sum += nums[i];
        
        cout << "#" << test_case << " " << sum << "\n";
            
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}