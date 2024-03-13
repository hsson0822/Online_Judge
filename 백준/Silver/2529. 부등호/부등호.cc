#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int N;
vector<char> compare;
vector<int> nums;
string bigger = to_string(LLONG_MIN);
string smaller = to_string(LLONG_MAX);
string str;
bool used[10];

void dfs(int cnt)
{
	if (str.size() == N + 1)
	{
		if (stoll(str) > stoll(bigger))
			bigger = str;

		if (stoll(str) < stoll(smaller))
			smaller = str;

		return;
	}

	for (int i = 0; i <= 9; ++i)
	{
		if (!used[i])
		{
			if (compare[cnt] == '>')
			{
				if (str[str.size() - 1] - '0' > i)
				{
					str += to_string(i);
					used[i] = true;
					dfs(cnt + 1);
					used[i] = false;
					str = str.substr(0, str.size() - 1);
				}
			}
			else if (compare[cnt] == '<')
			{
				if (str[str.size() - 1] - '0' < i)
				{
					str += to_string(i);
					used[i] = true;
					dfs(cnt + 1);
					used[i] = false;
					str = str.substr(0, str.size() - 1);
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		char k;
		cin >> k;
		compare.push_back(k);
	}

	for (int i = 0; i <= 9; ++i)
	{
		nums.push_back(i);
	}

	for (int i = 0; i <= 9; ++i)
	{
		str += to_string(i);
		used[i] = true;
		dfs(0);
		used[i] = false;
		str = "";
	}

	cout << bigger << endl << smaller;
	return 0;
}