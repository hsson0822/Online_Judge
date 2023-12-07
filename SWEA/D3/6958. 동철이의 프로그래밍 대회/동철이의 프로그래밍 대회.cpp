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
		vector<int> correct;
		int max{};
		int people;
		int problem;
		cin >> people >> problem;

		for (int i = 0; i < people; ++i)
		{
			int cor{};
			for (int j = 0; j < problem; ++j)
			{
				int n;
				cin >> n;
				if (n)
					++cor;
			}
			correct.push_back(cor);
			if (max < cor)
				max = cor;
		}

		int first{};
		for (int n : correct)
			if (n == max)
				++first;

		cout << "#" << test_case << " " << first << " " << max << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}