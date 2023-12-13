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
		stack<int> sta;

		string str;
		cin >> str;

		for (int i = 0; i < size; ++i)
		{
			if (str[i] == '+')
			{
				int a = sta.top();
				sta.pop();

				int b = str[i + 1]-'0';

				sta.push(a + b);
				++i;
			}
			else
				sta.push(str[i] - '0');

		}


		cout << "#" << test_case << " " << sta.top() << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}