#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
    {
        int degree;
        cin >> degree;

        int min = degree * 2;

        cout << "#" << test_case << " " << min/60 << " " << min % 60 << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}