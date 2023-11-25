#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
    {
        vector<string> str;
        int maxSize{};

        for (int i = 0; i < 5; ++i)
        {
            string s;
            cin >> s;
            str.push_back(s);

            if (s.size() > maxSize)
                maxSize = s.size();
        }

        string answer;
        for (int i = 0; i < maxSize; ++i)
        {
            for (int j = 0; j < str.size(); ++j)
            {
                if (str[j].size() <= i) continue;

                answer += str[j][i];
            }
        }

        cout << "#" << test_case << " " << answer << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}