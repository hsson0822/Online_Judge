#include<iostream>
#include<string>
#include<set>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		set<int> spade;
		set<int> dia;
		set<int> heart;
		set<int> clover;

		string s;
		cin >> s;

		for (int i = 0; i < s.size(); i += 3)
		{
			string numStr;
			numStr += s[i + 1];
			numStr += s[i + 2];
			int n = stoi(numStr);

			if (s[i] == 'S')
				spade.insert(n);
			else if(s[i] == 'D')
				dia.insert(n);
			else if (s[i] == 'H')
				heart.insert(n);
			else if (s[i] == 'C')
				clover.insert(n);
		}

		cout << "#" << test_case << " ";
		if (dia.size() + heart.size() + clover.size() + spade.size() != s.size()/3)
			cout << "ERROR\n";
		else
		{
			cout << 13 - spade.size() << " " << 13 - dia.size() << " " << 13 - heart.size() << " " << 13 - clover.size() << "\n";
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}