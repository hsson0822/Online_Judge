#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <limits.h>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<int> nums;

	int count{};
	cin >> count;

	for (int i = 0; i < count; ++i)
	{
		string str;
		cin >> str;

		if (str == "top")
		{
			if (nums.empty())
				cout << "-1" << endl;
			else
				cout << nums.top() << endl;
		}
		else if (str == "size")
		{
			cout << nums.size() << endl;
		}
		else if (str == "empty")
		{
			if (nums.empty())
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else if (str == "pop")
		{
			if (nums.empty())
				cout << "-1" << endl;
			else
			{
				cout << nums.top() << endl;
				nums.pop();
			}
		}
		else
		{
			int n;
			cin >> n;
			nums.push(n);
		}
	}
	
}