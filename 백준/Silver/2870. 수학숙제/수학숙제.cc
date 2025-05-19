#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <sstream>
#include <climits>
#include <math.h>
#include <cstring>

using namespace std;

int N;

struct cmp
{
	bool operator()(string A, string B)
	{
		if (A.size() == B.size())
			return A > B;
		
		return A.size() > B.size();
	}
};

string isZero(string str)
{
	string num = "";
	bool flag = 0;
	for (char ch : str)
	{
		if (ch != '0') {
			num += ch;
			flag = true;
		}
		else if (flag && ch == '0')
			num += '0';
	}

	if (num == "")
		return "0";
	else
		return num;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	priority_queue<string, vector<string>, cmp> answer;

	for (int i = 0; i < N; ++i)
	{
		string s;
		cin >> s;

		string num{};

		for (char ch : s)
		{
			if (isdigit(ch))
				num += ch;
			else if (!isdigit(ch) && num.size() != 0)
			{
				answer.push(isZero(num));
				num = "";
			}
		}

		if(num.size() != 0)
			answer.push(isZero(num));
	}

	while (!answer.empty())
	{
		cout << answer.top() << "\n";
		answer.pop();
	}

	return 0;
}
