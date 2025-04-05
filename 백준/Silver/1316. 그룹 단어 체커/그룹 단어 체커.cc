#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N{};
	cin >> N;

	map<char, bool> alpha;

	vector<string> vec;
	for (int i = 0; i < N; ++i)
	{
		string s;
		cin >> s;
		vec.push_back(s);
	}

	int answer{};
	for (string& s : vec)
	{
		char before{};
		bool flag = true;

		for (char ch : s)
		{
			if (before == '\0')
			{
				before = ch;
				alpha[before] = true;
				continue;
			}

			if (before != ch)
			{
				if (alpha[ch])
				{
					before = ch;
					flag = false;
					break;
				}
				else
				{
					alpha[before] = true;
					before = ch;
				}
			}
		}

		if (flag)
		{
			++answer;
		}

		alpha.clear();
	}

	cout << answer;

	return 0;
}