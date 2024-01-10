#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	int index{};
	for (char ch : str)
	{
		cout << ch;
		++index;
		if (index == 10)
		{
			cout << endl;
			index = 0;
		}
	}

	return 0;
}