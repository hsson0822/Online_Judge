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
        int obstacle;
        cin >> obstacle;
        
        int now{};
        int up = 0;
        int down = 0;
        
        cin >> now;
        
        for(int i = 1 ; i < obstacle ; ++i )
        {
            int n;
            cin >>n;
            
            if(n > now)
            {
                if(up < n-now)
                	up = n - now;
            }
            else
            {
                if(down < now-n)
                	down = now - n;
            }
            now = n;
        }
		cout << "#" << test_case << " " << up << " " << down << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}