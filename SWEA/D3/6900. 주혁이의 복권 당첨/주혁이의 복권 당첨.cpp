#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		map<string, int> lucky;

		int N;
		int M;
		cin >> N >> M;

		for (int i = 0; i < N; ++i)
		{
			string s;
			int n;
			cin >> s >> n;
			lucky[s] = n;
		}

		vector<string> myNum;
		for (int i = 0; i < M; ++i)
		{
			string s;
			cin >> s;
			myNum.push_back(s);
		}

		int answer{};

		for (auto m : lucky)
		{
			for (string s : myNum)
			{
				int numCount{};
				int correct{};

				for (int i = 0; i < m.first.size(); ++i)
				{
					if (m.first[i] == '*') continue;

					++numCount;

					if (m.first[i] == s[i])
						++correct;
					else
						break;
				}

				if (numCount == correct)
					answer += m.second;
			}
		}

		cout << "#" << test_case << " " << answer << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}