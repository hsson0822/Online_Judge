#include<iostream>
#include<math.h>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		long long num;
		cin >> num;

		long long i;
		long long A;
		long long B;
		for (i = 1; i <= sqrt(num); ++i)
		{
			if (num % i == 0)
			{
				A = i;
				B = num / i;
			}
		}

		long long answer = A + B - 2;

		cout << "#" << test_case << " " << answer<< endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}