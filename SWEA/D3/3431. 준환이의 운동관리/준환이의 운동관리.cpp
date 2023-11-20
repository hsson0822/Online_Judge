#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int L;
        int U;
        int X;
        cin >> L >> U >> X;
        
        int min{};
        if(X > U)
            min = -1;
        else if( X >= L && X <= U)
            min = 0;
        else
            min = L - X;
        
        cout << "#" << test_case << " " << min << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}