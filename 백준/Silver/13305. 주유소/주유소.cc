#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	cin >> count;

	deque<int> leng;
	deque<int> city;

	for (int i = 0; i < count - 1; ++i)
	{
		int n;
		cin >> n;
		leng.push_back(n);
	}

	for (int i = 0; i < count; ++i)
	{
		int n;
		cin >> n;
		city.push_back(n);
	}

	int now = city[0];
	int money = now * leng[0];

	for (int i = 1; i < count-1; ++i)
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