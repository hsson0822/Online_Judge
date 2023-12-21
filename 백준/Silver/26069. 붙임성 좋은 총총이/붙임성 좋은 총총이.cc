#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int count;
	cin >> count;

	set<string> dance;
	dance.insert("ChongChong");

	for (int i = 0; i < count; ++i)
	{
		string a;
		string b;
		cin >> a >> b;

		if (dance.find(a) != dance.end() || dance.find(b) != dance.end())
		{
			dance.insert(a);
			dance.insert(b);
		}
	}
	cout << dance.size();
    
    return 0;
}