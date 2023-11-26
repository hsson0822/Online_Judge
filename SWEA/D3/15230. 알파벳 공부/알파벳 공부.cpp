#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string alpha{ "abcdefghijklmnopqrstuvwxyz" };
		string str;
		cin >> str;

		int answer{};
		for (int i = 0; i < str.size(); ++i)
			if (str[i] == alpha[i])
				++answer;
			else
				break;

		cout << "#" << test_case << " " << answer << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}