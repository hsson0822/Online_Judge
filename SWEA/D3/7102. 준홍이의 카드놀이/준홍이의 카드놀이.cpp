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
        int A;
        int B;
        cin >> A >> B;
        
        map<int, int> nums;
        
        for(int i = 1; i <=A ; ++i)
        {
            for(int j = 1; j <=B ; ++ j)
            {
                int n = i+j;
                nums[n]++;
            }
        }
        
        int max{};
        for(auto m : nums)
        {
            if(m.second > max)
                max = m.second;
        }
        
        cout << "#" << test_case << " ";
        for(auto m : nums)
        {
            if(m.second == max)
                cout << m.first << " ";
        }
        cout << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}