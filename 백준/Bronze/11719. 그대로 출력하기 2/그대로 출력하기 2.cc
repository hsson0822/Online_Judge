#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;

	while (getline(cin, str))
	{
		cout << str << endl;
	}
	return 0;
}