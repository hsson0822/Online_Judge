#include <iostream>

using namespace std;

int N;
int cnt;
int now;
int temp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;


	while (cnt != N)
	{
		++now;
		temp = now;

		while (temp != 0)
		{
			if (temp % 1000 == 666)
			{
				++cnt;
				break;
			}
			else
				temp /= 10;
		}
	}

	cout << now;

	return 0;
}