#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
    {
        string answer;

        for (int i = 0; i < 3; ++i)
        {
            string str;
            cin >> str;
            char a = str[0];
            a = toupper(a);
            answer += a;
        }

        cout << "#" << test_case << " " << answer << "\n";

    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}