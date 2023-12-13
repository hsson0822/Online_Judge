#include<iostream>
#include<stack>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int size;
		cin >> size;
		stack<int> nums;
		stack<char> sta;

		string str;
		cin >> str;

		for (int i = 0; i < size; ++i)
		{
			if (str[i] == '+')
			{
				sta.push(str[i]);
			}
			else if (str[i] == '*')
			{
				if (str[i + 1] == '(')
				{
					sta.push(str[i]);
					continue;
				}

				int a = nums.top();
				nums.pop();

				int b = str[i + 1] - '0';

				nums.push(a * b);
				++i;
			}
			else if (str[i] == '(')
			{
				sta.push(str[i]);
			}
			else if (str[i] == ')')
			{
				while (sta.top() != '(')
				{
					int a = nums.top();
					nums.pop();
					int b = nums.top();
					nums.pop();

					if (sta.top() == '+')
						nums.push(a + b);
					else if (sta.top() == '*')
						nums.push(a * b);

					sta.pop();
				}

				sta.pop();
			}
			else
				nums.push(str[i] - '0');

			while (sta.size() != 0 && sta.top() == '*')
			{
				int a = nums.top();
				nums.pop();
				int b = nums.top();
				nums.pop();

				nums.push(a * b);

				sta.pop();
			}
		}

		cout << "#" << test_case << " " << nums.top() << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}