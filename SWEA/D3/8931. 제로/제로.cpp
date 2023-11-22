#include<iostream>
#include<stack>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int numsCount;
        cin >> numsCount;
        
        stack<int> nums;
        for(int i = 0 ; i < numsCount; ++i)
        {
            int n;
            cin >>n ;
            if(n == 0)
                nums.pop();
            else
                nums.push(n);
        }
		
        int sum{};
        
        while(nums.size() != 0)
        {
         	int n = nums.top();
            nums.pop();
            sum += n;
        }
        cout << "#" << test_case << " " << sum << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}