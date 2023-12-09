#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string a;
		string b;
		cin >> a >> b;

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		string newNum;
		int i;
		bool add = false;
		
		if (a.size() > b.size())
		{
			for (i = 0; i < b.size(); ++i)
			{
				int m = a[i] - '0';
				int n = b[i] - '0';
				int k = m + n;

				if (add)
				{
					++k;
					add = false;
				}

				if (k >= 10)
				{
					add = true;
					k %= 10;
				}

				newNum += to_string(k);
			}

			for (; i < a.size(); ++i)
			{
				int k = a[i]-'0';
				
				if (add)
				{
					++k;
					add = false;

					if (k >= 10)
					{
						add = true;
						k %= 10;
					}
				}
				
				newNum += to_string(k);
			}
            if (add)
				newNum += '1';
		}
		else
		{
			for (i = 0; i < a.size(); ++i)
			{
				int m = a[i] - '0';
				int n = b[i] - '0';
				int k = m + n;

				if (add)
				{
					++k;
					add = false;
				}

				if (k >= 10)
				{
					add = true;
					k %= 10;
				}

				newNum += to_string(k);
			}

			for (; i < b.size(); ++i)
			{
				int k = b[i]-'0';
				if (add)
				{
					++k;
					add = false;

					if (k >= 10)
					{
						add = true;
						k %= 10;
					}
				}
				newNum += to_string(k);
			}
            if (add)
				newNum += '1';
		}

		reverse(newNum.begin(), newNum.end());
		cout << "#" << test_case << " " << newNum << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}