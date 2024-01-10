#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	cin >> count;

	for (int i = 0; i < count; ++i)
	{
		int quarter{};
		int dime{};
		int nickel{};
		int penny{};

		int money;
		cin >> money;

		quarter = money / 25;
		money %= 25;

		dime = money / 10;
		money %= 10;

		nickel = money / 5;
		money %= 5;

		penny = money;

		cout << quarter << " " << dime << " " << nickel << " " << penny << endl;
	}
	return 0;
}