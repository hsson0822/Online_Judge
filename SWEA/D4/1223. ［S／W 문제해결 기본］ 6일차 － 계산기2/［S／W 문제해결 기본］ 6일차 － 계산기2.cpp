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
				sta.push(str[i] - '0');
			}
			else if (str[i] == '*')
			{
				int a = nums.top();
				nums.pop();

				int b = str[i + 1] - '0';

				nums.push(a * b);
				++i;
			}
			else
				nums.push(str[i] - '0');

		}

		while (sta.size() != 0)
		{
			int a = nums.top();
			nums.pop();
			int b = nums.top();
			nums.pop();

			nums.push(a + b);
			sta.pop();
		}


		cout << "#" << test_case << " " << nums.top() << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}