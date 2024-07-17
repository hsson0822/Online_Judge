#include <iostream>
#include <map>
#include <queue>

using namespace std;

map<int, queue<char>> duck;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); ++i)
	{
		char temp = s[i];
		
		if (temp == 'q')
		{
			bool flag = false;
			for (auto& m : duck)
			{
				if (m.second.size() == 0)
				{
					m.second.push(temp);
					flag = true;
					break;
				}
			}

			if (!flag)
			{
				duck[duck.size()].push(temp);
			}
		}
		else if (temp == 'u')
		{
			bool flag = false;
			for (auto& m : duck)
			{
				if (m.second.size() == 1)
				{
					m.second.push(temp);
					flag = true;
					break;
				}
			}

			if (!flag)
			{
				cout << -1;
				return 0;
			}
		}
		else if (temp == 'a')
		{
			bool flag = false;
			for (auto& m : duck)
			{
				if (m.second.size() == 2)
				{
					m.second.push(temp);
					flag = true;
					break;
				}
			}

			if (!flag)
			{
				cout << -1;
				return 0;
			}
		}
		else if (temp == 'c')
		{
			bool flag = false;
			for (auto& m : duck)
			{
				if (m.second.size() == 3)
				{
					m.second.push(temp);
					flag = true;
					break;
				}
			}

			if (!flag)
			{
				cout << -1;
				return 0;
			}
		}
		else
		{
			bool flag = false;
			for (auto& m : duck)
			{
				if (m.second.size() == 4)
				{
					while (!m.second.empty())
						m.second.pop();
					flag = true;
					break;
				}
			}

			if (!flag)
			{
				cout << -1;
				return 0;
			}
		}
		
	}

	bool flag = false;
	for (auto m : duck)
	{
		if (m.second.size() != 0)
		{
			flag = true;
			break;
		}
	}

	if (flag)
		cout << -1;
	else
		cout << duck.size();

	return 0;
}