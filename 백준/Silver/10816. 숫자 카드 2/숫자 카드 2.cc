#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt{};
	cin >> cnt;

	map<int, int> cards;

	for (int i = 0; i < cnt; ++i)
	{
		int n;
		cin >> n;
		cards[n]++;
	}

	cin >> cnt;

	for (int i = 0; i < cnt; ++i)
	{
		int n;
		cin >> n;
		cout << cards[n] << " ";
	}
	
}