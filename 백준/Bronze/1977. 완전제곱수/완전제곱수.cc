#include <iostream>
#include <math.h>

using namespace std;

int start;
int last;
int miniest = 0;
int sum;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> start >> last;

	for (int i = start; i <= last; ++i)
	{
		if (sqrt(i) == floor(sqrt(i)))
		{
			sum += i;
			if (miniest == 0)
				miniest = i;
		}
	}
	if (sum == 0)
	{
		cout << "-1";
		return 0;
	}

	cout << sum << endl;
	cout << miniest;
	return 0; 
}