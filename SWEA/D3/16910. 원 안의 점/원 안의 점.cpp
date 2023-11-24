#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n;
        cin >> n;
        long big = n * n;
        
        long answer{};
        for(int i = n*-1 ; i <= n ; ++i)
        {
            for(int j = n*-1 ; j <= n ; ++j)
            {
                int X = i *i;
                int Y= j * j;
                
                if( X + Y <= big)
                    ++answer;
            }
        }
        cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}