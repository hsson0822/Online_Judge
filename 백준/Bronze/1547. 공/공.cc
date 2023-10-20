#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<int, bool> map;

	map[1] = true;
	map[2] = false;
	map[3] = false;

	int count{};
	cin >> count;

	for (int i = 0 ; i < count; ++i)
	{
		int a;
		int b;

		cin >> a >> b;

		bool temp = map[a];
		map[a] = map[b];
		map[b] = temp;
	}

	for (int i = 1; i <= 3; ++i)
	{

		if (map[i])
		{
			cout << i;
			break;
		}
	}

}