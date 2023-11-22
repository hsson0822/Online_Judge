#include<iostream>
#include<map>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        map<int,int> nums;
        int leng;
        
		for(int i = 0 ; i < 3; ++i)
        {
            int n;
            cin >> n;
            nums[n]++;
        }
        
        for(auto m : nums)
        {
            if(m.second % 2 == 1)
            {
                leng = m.first;
                break;
            }
        }
        cout << "#" << test_case << " " << leng << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}