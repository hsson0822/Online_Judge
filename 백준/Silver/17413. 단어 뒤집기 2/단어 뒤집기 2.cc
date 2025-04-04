#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str{};

	getline(cin, str);

	string answer{};
	for (char ch : str)
	{
		if (ch == '<')
		{
			if (answer.size() != 0)
			{
				reverse(answer.begin(), answer.end());
				cout << answer;
				answer = {};
			}

			answer += '<';
		}
		else if (ch == '>')
		{
			answer += '>';
			cout << answer;
			answer = {};
		}
		else if (ch == ' ' && *answer.begin() != '<')
		{
			reverse(answer.begin(), answer.end());
			cout << answer + " ";
			answer = {};
		}
		else
		{
			answer += ch;
		}
	}

	if (answer.size() != 0)
	{
		reverse(answer.begin(), answer.end());
		cout << answer << " ";
	}

	return 0;
}
