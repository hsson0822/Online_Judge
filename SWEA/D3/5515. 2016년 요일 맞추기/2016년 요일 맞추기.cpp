#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	vector<int> days{ 0,31,29,31,30,31,30,31,31,30,31,30,31 };

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int mon;
		int day;
		cin >> mon >> day;

		int sum = 3;
		for (int i = 0; i < mon; ++i)
		{
			sum += days[i];
		}
		sum += day;
		sum %= 7;
		

		cout << "#" << test_case << " " << sum << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}