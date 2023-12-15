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

	set<string> people;
	int answer{};

	for (int i = 0; i < count; ++i)
	{
		string s;
		cin >> s;

		if (s == "ENTER")
		{
			people.clear();
			continue;
		}

		if (people.find(s) == people.end())
		{
			people.insert(s);
			++answer;
		}
		
	}
	
	cout << answer << endl;
    
    return 0;
}