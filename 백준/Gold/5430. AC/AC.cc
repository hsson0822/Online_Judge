#include <iostream>
#include <deque>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int testCase;
int N;
string str;
string num;
deque<int> deq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> testCase;

	for (int t = 0; t < testCase; ++t)
	{
		cin >> str >> N >> num;
		
		num = num.substr(1, num.size()-2);
		istringstream ss{ num };
		string s;

		while (getline(ss, s, ','))
		{
			deq.push_back(stoi(s));
		}

		bool flag = true;
		bool error = false;

		for (int i = 0; i < str.size(); ++i)
		{
			

			if (str[i] == 'R')
			{
				if (flag)
					flag = false;
				else
					flag = true;
			}
			else if (str[i] == 'D')
			{
				if (deq.empty())
				{
					error = true;
					break;
				}
				if (flag)
					deq.pop_front();
				else
					deq.pop_back();
			}
		}

		if (!error)
		{
			if (!flag)
				reverse(deq.begin(), deq.end());

			int k = deq.size();
			cout << "[";
			for (int i = 0; i < k; ++i)
			{
				cout << deq.front();
				deq.pop_front();

				if (i != k - 1)
					cout << ",";
			}
			cout << "]\n";
		}
		else
		{
			cout << "error\n";
		}
	}

	return 0;
}