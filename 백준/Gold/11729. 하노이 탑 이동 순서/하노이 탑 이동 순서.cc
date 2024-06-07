#include <iostream>

using namespace std;

void hanoi(int num, int from, int to, int bypass)
{
	if (num == 1)
		cout << from << " " << to << "\n";
	else
	{
		hanoi(num - 1, from, bypass, to);
		cout << from << " " << to << "\n";
		hanoi(num - 1, bypass, to, from);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
    cin >> num;
    cout << (1<< num)-1 << endl;
    hanoi(num, 1, 3, 2);

	return 0;
}