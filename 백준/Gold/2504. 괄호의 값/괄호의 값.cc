#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	stack<char> sta;
	stack<int> num;

	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '(' || str[i] == '[')
		{
			sta.push(str[i]);
		}
		else if (str[i] == ')' || str[i] == ']')
		{
			if (sta.size() == 0 || (sta.size() == 1 && sta.top() == '*'))
			{
				cout << 0;
				return 0;
			}

			int n = 1;
			if (sta.top() == '*')
			{
				sta.pop();
				n = num.top();
				num.pop();

				if (str[i] == ')')
				{
					n *= 2;
					if (sta.top() != '(')
					{
						cout << 0;
						return 0;
					}
					sta.pop();
				}
				else if (str[i] == ']')
				{
					n *= 3;
					if (sta.top() != '[')
					{
						cout << 0;
						return 0;
					}
					sta.pop();
				}

			}
			else if(sta.top() == '(' && str[i] == ')')
			{
				sta.pop();
				n = 2;
				
			}
			else if (sta.top() == '[' && str[i] == ']')
			{
				sta.pop();
				n = 3;
			}
			else
			{
				cout << 0;
				return 0;
			}

			if (sta.size() != 0 && sta.top() == '*')
			{
				n += num.top();
				num.pop();
			}
			else
			{
				sta.push('*');
			}

			num.push(n);
		}
	}
	
	if (sta.size() == 1 && sta.top() == '*')
		cout << num.top();
	else
		cout << 0;

	return 0;
}