#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int people;
	int a;
	int b;
	cin >> people >> a >> b;

	int i = 1;
	while (people != 2)
	{
		if (a % 2 != 0)
		{
			a += 1;
		}
		
		if (b % 2 != 0)
		{
			b += 1;
		}

		if (a / 2 == b / 2)
			break;

		a /= 2;
		b /= 2;
		++i;
	}
	cout << i << endl;
    
    return 0;
}