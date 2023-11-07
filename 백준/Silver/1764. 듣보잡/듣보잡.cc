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

	int listenCnt;
	cin >> listenCnt;

	int lookCnt;
	cin >> lookCnt;
	
	map<string, bool> listenPerson;

	for (int i = 0; i < listenCnt; ++i)
	{
		string str;
		cin >> str;
		listenPerson[str] = false;
	}


	int count{};
	for (int i = 0; i < lookCnt-1; ++i)
	{
		string lookPerson;
		cin >> lookPerson;

		if (auto fin = listenPerson.find(lookPerson) ; fin != listenPerson.end())
		{
			fin->second = true;
			++count;
		}
	}

	cout << count << "\n";
	for (auto m : listenPerson)
	{
		if (m.second)
			cout << m.first << "\n";
	}

}