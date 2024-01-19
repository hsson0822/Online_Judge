#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int caseNum = 1;
	while (true)
	{
		int L;
		int P;
		int V;
		cin >> L >> P >> V;
		if (L == 0 || P == 0 || V == 0)
			break;

		int count = V / P * L;
		V %= P;
		if (V != 0 && V <= L)
			count += V;
		else if (V != 0 && V > L)
			count += L;

		cout <<"Case " << caseNum++ << ": " << count << endl;
	}
}