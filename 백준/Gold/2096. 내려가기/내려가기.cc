#include <iostream>

using namespace std;

int N;
int big[3];
int small[3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int a;
		int b;
		int c;
		cin >> a >> b >> c;


		if (i == 0)
		{
			big[0] = a;
			big[1] = b;
			big[2] = c;

			small[0] = a;
			small[1] = b;
			small[2] = c;

			continue;
		}

		int bA = big[0];
		int bB = big[1];
		int bC = big[2];

		big[0] = a + max(bA, bB);
		big[1] = b + max(bA, max(bB, bC));
		big[2] = c + max(bB, bC);

		int sA = small[0];
		int sB = small[1];
		int sC = small[2];

		small[0] = a + min(sA, sB);
		small[1] = b + min(sA, min(sB, sC));
		small[2] = c + min(sB, sC);
	}

	int b = max(big[0], max(big[1], big[2]));
	int s = min(small[0], min(small[1], small[2]));

	cout << b << " " << s;
	
	return 0;
}