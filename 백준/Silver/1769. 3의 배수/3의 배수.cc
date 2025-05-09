#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <sstream>
#include <climits>
#include <math.h>
#include <cstring>

using namespace std;

map<int, map<int, vector<pair<int, string>>>> birth;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string num;
	cin >> num;

	int t{};

	while(num.size() > 1)
	{
		++t;
		int sum{};

		for (char ch : num)
			sum += ch - '0';

		num = to_string(sum);
	}

	cout << t<< "\n";
	if (stoi(num) % 3 == 0)
		cout << "YES";
	else
		cout << "NO";
	
	return 0;
}
