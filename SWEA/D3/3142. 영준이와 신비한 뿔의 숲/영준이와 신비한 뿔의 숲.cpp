#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int uni;
        int twin;
        
        int horn;
        int count;
        cin >> horn >> count;
        
        twin = horn - count;
        uni = count- twin;
		
        cout << "#" << test_case << " " << uni << " " << twin << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}