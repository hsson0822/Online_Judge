#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	
	int count{};
	while (cin >> str)
	{
		++count;
	}
	cout << count;

	return 0;
}