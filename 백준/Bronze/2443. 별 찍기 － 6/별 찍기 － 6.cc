#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;

	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < i; ++j)
			cout << " ";
		for (int j = 0; j < 2*(num-i)-1; ++j)
			cout << "*";
		cout << endl;
	}
	return 0;
}