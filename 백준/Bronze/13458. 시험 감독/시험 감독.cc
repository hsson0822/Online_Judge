#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long classCount;
	cin >> classCount;

	vector<long long> student;
	for (long long i = 0; i < classCount; ++i)
	{
		long long n;
		cin >> n;
		student.push_back(n);
	}

	long long B;
	long long C;
	cin >> B >> C;

	long long count{};
	for (long long& n : student)
	{
		n -= B;
		++count;

		if (n > 0)
		{
			count += n / C;
			n %= C;

			if (n != 0)
				++count;
		}
	}
	cout << count;
	return 0;
}