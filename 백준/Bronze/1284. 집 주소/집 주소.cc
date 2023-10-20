#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	while (true)
	{
		int planeSize = 1;

		int num;
		cin >> num;

		if (num == 0) break;

		string numStr = to_string(num);

		planeSize += numStr.size();

		for (char num : numStr)
		{
			if (num == '1')
				planeSize += 2;
			else if (num == '0')
				planeSize += 4;
			else
				planeSize += 3;
		}

		cout << planeSize << endl;
	}


}