#include<iostream>

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

		int hype;
		cin >> hype;
		for (int i = 0; i < hype; ++i)
		{
			int n;
			cin >> n;

			int alpha{};
			for (int j = 0; j < str.size(); ++j)
			{
				if (isalpha(str[j]))
				{
					if (alpha == n)
					{
						str.insert(j, "-");
						break;
					}

					++alpha;

					if (alpha == n)
					{
						str.insert(j+1, "-");
						break;
					}
				}
			}
		}
		cout << "#" << test_case << " " << str << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}