#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	deque<int> nums;

	int count{};
	cin >> count;

	for (int i = 0; i < count; ++i)
	{
		string str;
		cin >> str;

		if (str == "push_front")
		{
			int n;
			cin >> n;
			nums.push_front(n);
		}
		else if (str == "push_back")
		{
			int n;
			cin >> n;
			nums.push_back(n);
		}
		else if (str == "pop_front")
		{
			if (nums.empty())
				cout << "-1" << endl;
			else
			{
				cout << nums.front() << endl;
				nums.pop_front();
			}
		}
		else if (str == "pop_back")
		{
			if (nums.empty())
				cout << "-1" << endl;
			else
			{
				cout << nums.back() << endl;
				nums.pop_back();
			}
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
		else if (str == "front")
		{
			if (nums.empty())
				cout << "-1" << endl;
			else
				cout << nums.front() << endl;
		}
		else if (str == "back")
		{
			if (nums.empty())
				cout << "-1" << endl;
			else
				cout << nums.back() << endl;
		}
	}
}