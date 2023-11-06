#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <limits.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count{};

	cin >> count;

	for (int i = 0; i < count; ++i)
	{
		string s;
		cin >> s;

		int pair{};

		for (char ch : s)
		{
			if (ch == '(')
				++pair;
			else if (ch == ')')
			{
				--pair;

				if (pair < 0)
					break;
			}
		}

		if (pair == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
}