#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	stack<char> sta;
	string bomb;
	string str;

	cin >> str >> bomb;

	for (int i = 0; i < str.size(); ++i)
	{
		sta.push(str[i]);

		if (str[i] == bomb[bomb.size() -1] && sta.size() >= bomb.size())
		{
			string temp;

			for (int j = 0; j < bomb.size(); ++j)
			{
				temp.push_back(sta.top());
				sta.pop();
			}

			reverse(temp.begin(), temp.end());
			
			if (temp != bomb)
				for (int j = 0; j < bomb.size(); ++j)
					sta.push(temp[j]);
		}
	}

	string answer;
	answer.reserve(1000000);

	while (!sta.empty())
	{
		answer.push_back(sta.top());
		sta.pop();
	}

	reverse(answer.begin(), answer.end());

	if (answer.size() == 0)
		cout << "FRULA";
	else
		cout << answer;

	return 0;
}