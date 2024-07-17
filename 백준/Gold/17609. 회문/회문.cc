#include <iostream>

using namespace std;

int N;
bool check;

bool isPalindrome(string s, int left, int right)
{
	int cnt{};
	while (left < right)
	{
		if (s[left] == s[right])
		{
			++left;
			--right;
		}
		else
		{
			if (check)
				return false;
			check = true;
			return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
		}

	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		string s;
		cin >> s;

		check = false;
		bool isP = isPalindrome(s, 0, s.size() - 1);

		if (isP && !check)
			cout << "0\n";
		else if (isP && check)
			cout << "1\n";
		else
			cout << "2\n";
	}

	return 0;
}