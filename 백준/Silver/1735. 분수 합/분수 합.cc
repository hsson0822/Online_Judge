#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int Ason;
	int Amom;
	int Bson;
	int Bmom;

	cin >> Ason >> Amom >> Bson >> Bmom;

	int tempA = Amom;
	int tempB = Bmom;
	Amom *= tempB;
	Ason *= tempB;

	Bson *= tempA;
	Bmom *= tempA;

	int son = Ason + Bson;
	int mom = Amom;

	int small = min(son, mom);

	for (int i = small; i >= 2; --i)
	{
		if (son % i == 0 && mom % i == 0)
		{
			son /= i;
			mom /= i;
			i =  min(son, mom);
		}
	}

	cout << son << " " << mom << endl;

	return 0;
}