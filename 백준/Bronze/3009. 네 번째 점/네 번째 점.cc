#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	set<int> front;
	set<int> back;

	for (int i = 0; i < 3; ++i)
	{
		int f;
		cin >> f;

		if (front.find(f) == front.end())
			front.insert(f);
		else
			front.erase(f);

		int b;
		cin >> b;

		if (back.find(b) == back.end())
			back.insert(b);
		else
			back.erase(b);
	}
	cout << *(front.begin()) << " " << *(back.begin());
	
	return 0;
}