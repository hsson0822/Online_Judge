#include <iostream>

#define EARTH 15
#define SUN 28
#define MOON 19

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int year = 1;
	int earth = 1;
	int	sun = 1;
	int moon = 1;

	int E, S, M;
	cin >> E >> S >> M;

	while (true)
	{
		if (earth == E && sun == S && moon == M)
		{
			break;
		}

		++year;
		++earth;
		++sun;
		++moon;

		if (earth > EARTH)
			earth = 1;

		if (sun > SUN)
			sun = 1;

		if (moon > MOON)
			moon = 1;
	}

	cout << year;

	return 0;
}