#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	vector<string> alpha{ "ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN" };
	for (test_case = 1; test_case <= 10; ++test_case)
	{
        string s;
		cin >> s;
        
		map<int, int> alphaMap;
		int cnt;
		cin >> cnt;
		for(int i = 0 ; i < cnt ; ++i)
		{
			string s;
			cin >> s;

			int n;
			if (s == "ZRO")
				n = 0;
			else if (s == "ONE")
				n = 1;
			else if (s == "TWO")
				n = 2;
			else if (s == "THR")
				n = 3;
			else if (s == "FOR")
				n = 4;
			else if (s == "FIV")
				n = 5;
			else if (s == "SIX")
				n = 6;
			else if (s == "SVN")
				n = 7;
			else if (s == "EGT")
				n = 8;
			else if (s == "NIN")
				n = 9;

			alphaMap[n]++;
		}

		cout << "#" << test_case << "\n";
		for (auto m : alphaMap)
		{
			for (int i = 0; i < m.second; ++i)
				cout << alpha[m.first] << " ";
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}