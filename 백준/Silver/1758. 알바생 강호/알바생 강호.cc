#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    long long count;
	cin >> count;

	long long answer{};
	vector<long long> vec;

	for (long long i = 1; i <= count; ++i)
	{
		long long n;
		cin >> n;
		vec.push_back(n);
		
	}

	sort(vec.rbegin(), vec.rend());

	for (long long i = 1; i <= count; ++i)
	{
		long long sum = vec[i-1] - (i - 1);
		
		if (sum <= 0)
			sum = 0;

		answer += sum;
	}

	cout << answer << endl;
    
    
    return 0;
}