#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string s;
		cin >> s;

		int ball{};
		
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '(' && s[i + 1] == ')')
			{
				++ball;
				++i;
			}
			else if (s[i] == '(' && s[i + 1] == '|')
			{
				++ball;
				++i;
			}
			else if (s[i] == '|' && s[i + 1] == ')')
			{
				++ball;
				++i;
			}
		}

		cout << "#" << test_case << " " << ball << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}