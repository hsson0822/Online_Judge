#include<iostream>
#include<climits>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int big = INT_MIN;
        int small = INT_MAX;
        
        for(int i = 0 ; i < 10 ; ++i)
        {
            int num;
        	cin >> num;
        	string str = to_string(num);
            int sum{};
            
        	for(char ch: str)
            {
                int k = ch - '0';
                sum += k;
            }
            
            if(sum > big)
                big = sum;
            
            if( sum < small)
                small = sum;
        }
        
        cout << "#" << test_case << " " << big << " " << small << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}