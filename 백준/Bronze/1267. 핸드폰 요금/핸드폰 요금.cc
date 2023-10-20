#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count{};
	cin >> count;

	int Ymoney{};
	int Mmoney{};

	for (int j = 0; j < count; ++j)
	{
		int time{};
		cin >> time;

		Ymoney += time / 30 * 10;
		if (time % 30 >= 0)
			Ymoney += 10;

		Mmoney += time / 60 * 15;
		if (time % 60 >= 0)
			Mmoney += 15;
	}

	if (Mmoney < Ymoney)
		cout << "M " << Mmoney;
	else if (Mmoney > Ymoney)
		cout << "Y " << Ymoney;
	else
		cout << "Y M " << Mmoney;

}