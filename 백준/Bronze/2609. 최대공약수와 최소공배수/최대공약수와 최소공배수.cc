#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a;
	int b;
	cin >> a >> b;

	int GCD = 1;
	int LCM = 1;

	for (int i = 2; i <= min(a, b); ++i)
	{
		if (a % i == 0 && b % i == 0)
		{
			GCD *= i;
			LCM *= i;
			a /= i;
			b /= i;
			i = 1;
		}
	}

	LCM *= a;
	LCM *= b;

	cout << GCD << endl;
	cout << LCM << endl;

	return 0;
}