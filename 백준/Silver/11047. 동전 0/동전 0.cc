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
	
	int makeMoney;
	cin >> makeMoney;

	vector<int> moneyList;
	for (int i = 0; i < count; ++i)
	{
		int n;
		cin >> n;
		moneyList.push_back(n);
	}
	
	sort(moneyList.rbegin(), moneyList.rend());

	int moneyCount{};

	for (int money : moneyList)
	{
		if (money > makeMoney) continue;

		moneyCount += makeMoney / money;
		makeMoney %= money;

		if (makeMoney == 0)
			break;
	}

	cout << moneyCount;
}