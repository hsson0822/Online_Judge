#include <iostream>

using namespace std;

int testCase;
int N;
int M;
int goalX;
int goalY;
int day[2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> testCase;

	for (int t = 0; t < testCase; ++t)
	{
		cin >> N >> M >> goalX >> goalY;
		day[0] = goalX;
		day[1] = goalY;
		int cnt{};
		
		while (day[0] <= N * M)
		{
			if (day[0] < day[1])
				day[0] += N;
			else if (day[0] > day[1])
				day[1] += M;
			else
				break;
		}

		if (day[0] > N * M)
			day[0] = -1;
		cout << day[0] << endl;
	}
	return 0;
}