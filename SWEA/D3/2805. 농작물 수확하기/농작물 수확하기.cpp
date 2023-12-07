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
		vector<string> farm;
		int size;
		cin >> size;
		int gain{};

		for (int i = 0; i < size; ++i)
		{
			string s;
			cin >> s;
			farm.push_back(s);
		}

		for (int i = 0; i < size; ++i)
		{
			if (i <= size / 2)
			{
				for (int j = size/2 -i; j <= size/2+i; ++j)
				{

					int n = farm[i][j] - '0';
					gain += n;
				}
			}
			else
			{
				for (int j = i - size/2; j < size - (i - size/2); ++j)
				{
					int n = farm[i][j] - '0';
					gain += n;
				}
			}
		}

		cout << "#" << test_case << " " << gain << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}