#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int count{};
	cin >> count;

	queue<int> cards;

	for (int i = 1; i <= count ; ++i)
	{
		cards.push(i);
	}

	bool flag = true;

	while (cards.size() != 1)
	{
		if (flag)
		{
			cards.pop();
			flag = false;
		}
		else
		{
			int num = cards.front();
			cards.pop();
			cards.push(num);
			flag = true;
		}
	}
	
	cout << cards.front();
}