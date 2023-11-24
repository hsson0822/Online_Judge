#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
    {
        string str;
        cin >> str;

        for (char& ch : str)
        {
            if (ch == 'b')
                ch = 'd';
            else if (ch == 'd')
                ch = 'b';
            else if (ch == 'p')
                ch = 'q';
            else if (ch == 'q')
                ch = 'p';
        }
        reverse(str.begin(), str.end());
        cout << "#" << test_case << " " << str << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}