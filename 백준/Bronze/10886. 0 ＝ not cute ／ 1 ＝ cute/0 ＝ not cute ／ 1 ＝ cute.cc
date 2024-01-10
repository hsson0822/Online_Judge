#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cute{};
	int notCute{};

	int count;
	cin >> count;

	for (int i = 0; i < count; ++i)
	{
		int n;
		cin >> n;
		
		if (n)
			++cute;
		else
			++notCute;
	}

	if (cute >= notCute)
		cout << "Junhee is cute!" << endl;
	else
		cout << "Junhee is not cute!" << endl;
	return 0;
}