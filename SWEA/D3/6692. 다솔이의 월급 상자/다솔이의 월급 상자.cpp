#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int count;
		cin >> count;

		double sum{};

		for (int i = 0; i < count; ++i)
		{
			double p;
			int x;
			cin >> p >> x;
			sum += p * x;
		}

		cout << fixed;
		cout.precision(6);
		cout << "#" << test_case << " " << sum << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}