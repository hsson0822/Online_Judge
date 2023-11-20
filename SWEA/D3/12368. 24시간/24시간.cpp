#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int now;
        int next;
        cin >> now >> next;
        
        now += next;
        
        if(now >= 24)
            now %= 24;
        
        cout << "#" << test_case << " " << now << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}