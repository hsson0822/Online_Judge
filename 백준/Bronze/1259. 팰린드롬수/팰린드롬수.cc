#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{

		string str;
		string rev;

		cin >> str;
		if (str == "0")
			break;

		rev = str;
		reverse(rev.begin(), rev.end());

		if (str == rev)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}


	return 0;
}