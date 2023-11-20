#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int strSize;
        cin >> strSize;
        
        string A;
        string B;
        cin >>A >> B;
        
        int cnt{};
        for(int i = 0 ; i < strSize ; ++i)
        {
            if(A[i] == B[i])
                ++cnt;
        }
        
        cout << "#" << test_case << " " << cnt << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}