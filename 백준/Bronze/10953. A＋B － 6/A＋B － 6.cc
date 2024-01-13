#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	cin >> count;

	for (int i = 0; i < count; ++i)
	{
		string str;
		cin >> str;

		istringstream ss{ str };
		vector<int> v;
		string s;
		while (getline(ss, s, ','))
			v.push_back(stoi(s));

		cout << v[0] + v[1] << endl;
	}
}