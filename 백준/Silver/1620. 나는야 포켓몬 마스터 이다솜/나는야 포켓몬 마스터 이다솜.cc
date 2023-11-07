#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int bookPokemon;
	cin >> bookPokemon;
	int findPokemon;
	cin >> findPokemon;

	unordered_map<string, int> strPokemon;
	unordered_map<int, string> intPokemon;

	for (int i = 0; i < bookPokemon; ++i)
	{
		string str;
		cin >> str;
		strPokemon[str] = i+1;
		intPokemon[i + 1] = str;
		
	}
	
	for (int i = 0; i < findPokemon; ++i)
	{
		string str;
		cin >> str;

		if (strPokemon[str] == 0)
		{
			cout << intPokemon[stoi(str)] << "\n";
		}
		else
		{
			cout << strPokemon[str] << "\n";
		}
	}

}