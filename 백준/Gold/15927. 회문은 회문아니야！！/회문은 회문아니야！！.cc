#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

bool check(string str)
{
	string temp = str;
	reverse(temp.begin(), temp.end());

	if (str == temp)
		return false;
	
	return true;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	int answer = -1;
	if (check(str))
	{
		cout << str.size();
		return 0;
	}
	else
	{
		map<char, int> cnt;
		for (int i = 0; i < str.size(); ++i)
			cnt[str[i]]++;

		if (cnt.size() == 1)
		{
			cout << -1;
			return 0;
		}
		cout << str.size() - 1;
		return 0;

	}

	return 0;
}
