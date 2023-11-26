#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;

		bool flag = false;
		for (int i = 1; i <= 9; ++i)
		{
			for (int j = 1; j <= 9; ++j)
			{
				if (i * j == n)
				{
					flag = true;
					break;
				}
			}

			if (flag)
				break;
		}

		cout << "#" << test_case << " ";

		if (flag)
			cout << "Yes" << "\n";
		else
			cout << "No" << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}