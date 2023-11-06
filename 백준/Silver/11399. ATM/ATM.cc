#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <limits.h>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count{};
	cin >> count;

	vector<int> time;

	for (int i = 0; i < count; ++i)
	{
		int n;
		cin >> n;

		time.push_back(n);
	}

	sort(time.begin(), time.end());
	int sum{};
	int perTime{};

	for (int n : time)
	{
		perTime += n;
		sum += perTime;
	}

	cout << sum;
}