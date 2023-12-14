#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int broken;
	int shop;
	cin >> broken >> shop;
	set<int> package;
	set<int> one;

	for (int i = 0; i < shop; ++i)
	{
		int p;
		int o;
		cin >> p >> o;
		package.insert(p);
		one.insert(o);
	}

	int p = (*package.begin());
	int o = (*one.begin());
	int answer{};

	if (o * 6 > p)
	{
		answer += (broken / 6) * p;
		broken %= 6;

		if (broken * o > p)
			answer += p;
		else
			answer += broken * o;
	}
	else
	{
		answer += broken * o;
	}


	cout << answer << endl;
    return 0;
}