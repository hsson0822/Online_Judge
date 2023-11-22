#include<iostream>

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
        
        int money; 
       	cin >> money;
        
        int count{};
        
        if(A > B)
        {
        	for(int i = 0 ; i <= money/A ; ++i)
        	{
                if(i != 0)
                {
                    count += money/A;
                    money %= A;
                }
                
                count += money/B;
                money %= B;
        	}
        }
        else
        {
            for(int i = 0 ; i <= money/B ; ++i)
        	{
                if(i != 0)
                {
                    count += money/B;
                    money %= B;
                }
                
                count += money/A;
                money %= A;
        	}
        }
        
        cout << "#" << test_case << " " << count << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}