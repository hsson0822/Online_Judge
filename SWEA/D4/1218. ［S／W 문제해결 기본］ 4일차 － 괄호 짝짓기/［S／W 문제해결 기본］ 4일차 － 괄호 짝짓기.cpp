#include<iostream>
#include<stack>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		stack<char> sta;
		int size;
		cin >> size;
		for (int i = 0; i < size; ++i)
		{
			char ch;
			cin >> ch;
			
			if (ch == ')')
			{
				if (sta.top() == '(')
					sta.pop();
				else
					sta.push(ch);
			}
			else if (ch == ']')
			{
				if (sta.top() == '[')
					sta.pop();
				else
					sta.push(ch);
			}
			else if (ch == '}')
			{
				if (sta.top() == '{')
					sta.pop();
				else
					sta.push(ch);
			}
			else if (ch == '>')
			{
				if (sta.top() == '<')
					sta.pop();
				else
					sta.push(ch);
			}
			else
				sta.push(ch);
		}

		if(!sta.size())
			cout << "#" << test_case << " 1" << endl;
		else
			cout << "#" << test_case << " 0" << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}