#include <bits/stdc++.h>

using namespace std;

stack<char> sta;

bool checkPPAP()
{
	string str{};

	for (int i = 0; i < 4; ++i)
	{
		str = sta.top() + str;
		sta.pop();
	}
	// cout << str<<endl;
	if (str == "PPAP")
		return true;

	for (int i = 0; i < 4; ++i)
		sta.push(str[i]);

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	for (int i = 0; i < str.size(); ++i)
	{
		char ch = str[i];
		sta.push(ch);

		if (sta.size() >= 4)
		{
			if (checkPPAP())
			{
				sta.push('P');
			}
		}
	}

	if (sta.size() == 1 && sta.top() == 'P')
		cout << "PPAP";
	else
		cout << "NP";

	return 0;
}