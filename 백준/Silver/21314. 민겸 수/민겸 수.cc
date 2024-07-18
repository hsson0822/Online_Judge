#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	string big{};
	string small{};

	string temp;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == 'K')
		{
			if (temp.size() != 0)
			{
				big += '5';
				for (int i = 0; i < temp.size(); ++i)
				{
					if (i == 0)
					{
						small += '1';
					}
					else
					{
						small += '0';
					}
					big += '0';
				}
				
				small += '5';
			}
			else
			{
				big += '5';
				small += '5';
			}
			temp = "";
		}
		else
		{
			temp += str[i];
		}
	}

	if (temp.size() != 0)
	{
		for (int i = 0; i < temp.size(); ++i)
		{
			big += '1';
			if (i == 0)
				small += '1';
			else
				small += '0';
		}

	}

	cout << big << "\n" << small;

	return 0;
}