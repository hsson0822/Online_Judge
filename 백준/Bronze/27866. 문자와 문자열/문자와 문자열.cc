#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	int index;
	
	cin >> str >> index;
	cout << str[index - 1];

	return 0;
}