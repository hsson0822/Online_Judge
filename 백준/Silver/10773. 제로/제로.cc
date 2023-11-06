#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count{};
	cin >> count;

	stack<int> moneyList;

	for (int i = 0; i < count; ++i)
	{
		int n;
		cin >> n;

		if (n)
			moneyList.push(n);
		else
			moneyList.pop();
	}

	int sum{};
	while (moneyList.size() != 0)
	{
		int money = moneyList.top();
		sum += money;
		moneyList.pop();
	}
	cout << sum;
}