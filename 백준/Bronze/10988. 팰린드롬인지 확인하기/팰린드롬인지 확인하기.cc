#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	string rev = str;
	reverse(rev.begin(), rev.end());

	if (str == rev)
		cout << 1;
	else
		cout << 0;

	return 0;
}