#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, int> book;

	int count;
	cin >> count;

	for (int i = 0; i < count; ++i)
	{
		string site;
		cin >> site;
		book[site]++;
	}

	vector<pair<string, int>> vec{ book.begin(), book.end() };

	sort(vec.begin(), vec.end(), [](auto& a, auto& b)
		{
			return a.first < b.first;
		});

	stable_sort(vec.begin(), vec.end(), [](auto& a, auto& b)
		{
			return a.second > b.second;
		});

	cout << vec[0].first;
}