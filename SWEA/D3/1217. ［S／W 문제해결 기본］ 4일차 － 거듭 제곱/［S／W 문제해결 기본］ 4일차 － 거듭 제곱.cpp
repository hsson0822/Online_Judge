#include<iostream>
#include<math.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	for(test_case = 1; test_case <= 10; ++test_case)
	{
        int test;
        cin >> test;
		unsigned long long n;
        unsigned long long s;
        cin >> n >> s;
        unsigned long long result =  pow(n,s) ;
        cout << "#" << test << " " << result << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}