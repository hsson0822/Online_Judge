#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a;
	int b;
	while (cin >> a >> b)
	{
		
		if (cin.eof()) break;
		else
			cout << a + b << endl;
	}

	return 0;
}