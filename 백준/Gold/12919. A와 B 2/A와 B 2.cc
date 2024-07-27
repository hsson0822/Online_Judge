#include <iostream>
#include <algorithm>

using namespace std;

string temp{};

void R(string S, string T)
{
	if (S == T)
	{
		cout << 1;
		exit(0);
	}

	if (S.size() >= T.size())
		return;

	if (T[T.size() - 1] == 'A')
	{
		temp = T;
		temp.erase(temp.size() - 1);
		R(S, temp);
	}

	if (T[0] == 'B')
	{
		temp = T;
		temp.erase(temp.begin());
		reverse(temp.begin(), temp.end());
		R(S, temp);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;
	string T;
	cin >> S >> T;

	R(S, T);

	cout << 0;

	return 0;
}