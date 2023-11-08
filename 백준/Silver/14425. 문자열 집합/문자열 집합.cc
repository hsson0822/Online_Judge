#include <iostream>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int spellCount;
	cin >> spellCount;

	int N;
	cin >> N;

	set<string> s;
	for (int i = 0; i < spellCount; ++i)
	{
		string str;
		cin >> str;
		s.insert(str);
	}


	int count{};
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		auto it = s.find(str);
		if (it != s.end())
			++count;
	}

	cout << count;
}