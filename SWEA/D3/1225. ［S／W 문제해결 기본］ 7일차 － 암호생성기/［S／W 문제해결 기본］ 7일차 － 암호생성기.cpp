#include<iostream>
#include<deque>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;

	for(test_case = 1; test_case <= 10; ++test_case)
	{
        deque<long> nums;
        int test;
        cin >> test;
        
        for(int i = 0 ; i < 8 ; ++i)
        {
            long n;
            cin>> n;
            nums.push_back(n);
        }
        
        int minus = 1;
        while(true)
        {
            long n  = nums.front();
            nums.pop_front();
            
            n -= minus;
            ++minus;
            if(minus > 5)
                minus = 1;
            
            if(n <= 0)
            {
                n = 0;
                nums.push_back(n);
                break;
            }
            
            nums.push_back(n);
            
        }
        
		cout << "#" << test_case << " ";
       	for(int n : nums)
            cout << n << " ";
        cout << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}