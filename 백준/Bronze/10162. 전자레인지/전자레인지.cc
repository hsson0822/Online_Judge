#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int five{};
	int one{};
	int ten{};

	int time;
	cin >> time;

	five = time / 300;
	time %= 300;

	one = time / 60;
	time %= 60;

	ten = time / 10;
	time %= 10;

	if (time != 0)
	{
		cout << -1;
		return 0;
	}

	cout << five << " " << one << " " << ten;

	return 0;
}