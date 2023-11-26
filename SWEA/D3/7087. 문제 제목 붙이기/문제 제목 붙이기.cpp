#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	string alpha{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int strCount;
		cin >> strCount;

		set<char> capital;
		for (int i = 0; i < strCount; ++i)
		{
			string str;
			cin >> str;

			capital.insert(str[0]);
		}

		vector<char> vec{capital.begin(), capital.end()};
		int answer{};
		
		for (int i = 0; i < vec.size(); ++i)
		{
			if (vec[i] == alpha[i])
				++answer;
			else
				break;
		}


		cout << "#" << test_case << " " << answer << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}