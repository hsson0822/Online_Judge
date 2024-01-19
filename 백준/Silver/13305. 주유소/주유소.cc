#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long count;
	cin >> count;

	deque<int> leng;
	deque<int> city;

	for (int i = 0; i < count - 1; ++i)
	{
		long long n;
		cin >> n;
		leng.push_back(n);
	}

	for (int i = 0; i < count; ++i)
	{
		long long n;
		cin >> n;
		city.push_back(n);
	}

	long long now = city[0];
	long long money = now * leng[0];

	for (long long i = 1; i < count-1; ++i)
	{
		if (now < city[i])
			money += now * leng[i];
		else
		{
			now = city[i];
			money += now * leng[i];
		}
	}
	cout << money;

}