#include <iostream>
#include <climits>
using namespace std;

string A;
string B;
int miniest = INT_MAX;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B;

	for (int i = 0; i <= B.size() - A.size(); ++i)
	{
		int cnt{};
		for (int j = 0; j < A.size(); ++j)
		{
			if (A[j] != B[i + j])
			{
				++cnt;
			}
		}
		
		if (miniest > cnt)
			miniest = cnt;
	}

	cout << miniest;

	return 0;
}