#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    string str;
	cin >> str;

	set<string> word;
	while (str.size() != 0)
	{
		word.insert(str);
		str.erase(str.begin(), str.begin() + 1);
	}

	for (string s : word)
		cout << s << endl;
    
    return 0;
}