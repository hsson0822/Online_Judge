#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int people;
        int P;
        int T;
        
        cin >> people >> P >> T;
        
        int max{};
        int min{};
        
        if(P >T)
            max = T;
        else
            max = P;
        
        if(P+T > people)
            min = P+T - people;
        else
            min = 0;
        
        cout << "#" << test_case << " " << max << " " << min << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}