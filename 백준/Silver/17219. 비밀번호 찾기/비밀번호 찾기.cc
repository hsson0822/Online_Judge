#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, string> map;
	
	int siteCount;
	cin >> siteCount;

	int findSiteCount;
	cin >> findSiteCount;

	for (int i = 0; i < siteCount; ++i)
	{
		string site;
		string pass;

		cin >> site >> pass;

		map[site] = pass;
	}
	
	for (int i = 0; i < findSiteCount; ++i)
	{
		string site;
		cin >> site;
		cout << map[site] << "\n";
	}
}