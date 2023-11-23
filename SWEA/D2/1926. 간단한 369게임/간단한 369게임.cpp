#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		string str = to_string(test_case);
        
        int three{};
        for(char ch : str)
        {
            int n = ch- '0';
            if(n != 0 && n % 3 == 0)
                ++three;
        }
        
        if(three == 0)
            cout << test_case << " ";
        else
        {
            for(int i = 0 ; i < three ; ++i)
                cout << "-";
           	cout  << " ";
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}